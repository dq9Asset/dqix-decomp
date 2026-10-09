#if defined(jpn)
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "World/ZoneResourceTree.h"
#include <globaldefs.h>

extern "C" Element_1f2a4 *func_0201f030(Manager_1f2a4 *, int);
extern "C" void func_02012de0(InitTarget02013018 *);
extern "C" void func_02012e78(ListNode *, ListNode *);
extern "C" void func_02012ea8(Node020130e0 *, Node020130e0 *);
extern "C" int func_ov017_021b904c(void *);
extern "C" int func_0201ef3c(Table_1f1b0 *, int);
extern "C" void func_02012ed4(void *);

// JPN: func_02017574
extern "C" ARM void func_02017574(Zone3D *zone, void *resourceNode, SafeAllocator *allocator) {
    ZoneResourceTree *tree = static_cast<ZoneResourceTree *>(resourceNode);
    GameState::GetInstance();
    LightingManager *lighting = LightingManager::GetInstance();
    Manager_1f2a4 *manager    = reinterpret_cast<Manager_1f2a4 *>(&tree->resources.records);
    int count                 = manager->count;
    tree->nodes = static_cast<ZoneResourceRuntimeNode *>(allocator->Allocate(count * sizeof(ZoneResourceRuntimeNode)));
    if (tree->nodes == NULL) return;

    for (int i = 0; i < count; i++) {
        ZoneResourceTreeRecord *source = reinterpret_cast<ZoneResourceTreeRecord *>(func_0201f030(manager, i));
        ZoneResourceRuntimeNode *node  = &tree->nodes[i];
        func_02012de0(reinterpret_cast<InitTarget02013018 *>(node));
        node->key = source->key;
    }

    for (int i = 0; i < count; i++) {
        ZoneResourceTreeRecord *source = reinterpret_cast<ZoneResourceTreeRecord *>(func_0201f030(manager, i));
        ZoneResourceRuntimeNode *node  = &tree->nodes[i];
        int parentKey                  = source->parentKey;
        if (parentKey > -1) {
            for (int j = 0; j < count; j++) {
                ZoneResourceRuntimeNode *parent = &tree->nodes[j];
                if (source->parentKey == parent->key) {
                    node->parent = parent;
                    func_02012e78(reinterpret_cast<ListNode *>(parent), reinterpret_cast<ListNode *>(node));
                    break;
                }
            }
        } else if (i != 0) {
            func_02012ea8(reinterpret_cast<Node020130e0 *>(tree->nodes), reinterpret_cast<Node020130e0 *>(node));
        }
    }

    int timeOfDay        = lighting->timeOfDayIndex_;
    void *overrideObject = func_ov017_0218b5b0()->unknown_ptr_3718;
    if (overrideObject != NULL && func_ov017_021b904c(overrideObject)) {
        unsigned char *overrideData = static_cast<unsigned char *>(func_ov017_021b8478(overrideObject));
        timeOfDay                   = overrideData[5];
    }

    for (int i = 0; i < count; i++) {
        ZoneResourceTreeRecord *source = reinterpret_cast<ZoneResourceTreeRecord *>(func_0201f030(manager, i));
        ZoneResourceRuntimeNode *node  = &tree->nodes[i];
        node->source                   = source;
        node->unknown3a                = 0;
        Vector3i position              = source->position;
        if (node->parent == NULL) Vector3fix_Add(&position, &tree->position, &position);

        if (source->flags & 0x10)
            node->flags |= 4;
        else if (source->flags & (1 << timeOfDay))
            node->flags &= ~4;
        else
            node->flags |= 4;

        if (source->trackerKey < 0) {
            node->tracker = &tree->resources.trackers[source->key];
        } else {
            int index =
                func_0201ef3c(reinterpret_cast<Table_1f1b0 *>(&tree->resources.records), source->trackerKey);
            if (index >= 0) node->tracker = &tree->resources.trackers[index];
        }

        Struct02012ff0 *tracker = node->tracker;
        if (tracker != NULL) {
            if (tracker->field0 == 0 && tracker->field4 == 0) node->tracker = NULL;
            if (tracker->field0 == 1 && tracker->field4 == 0) node->tracker = NULL;
            if (tracker->field0 == 2 && tracker->field4 == 0) node->tracker = NULL;
            if (tracker->field0 == 2 && node->tracker != NULL) {
                node->object = static_cast<Object3D *>(allocator->Allocate(sizeof(Object3D)));
                if (node->object == NULL) {
                    node->tracker = NULL;
                } else {
                    node->object->Initialize();
                    reinterpret_cast<Object3D *>(tracker->field4)->ShallowCloneTo(node->object);
                }
            }
        }
    }
    func_02012ed4(tree->nodes);
}


#endif
