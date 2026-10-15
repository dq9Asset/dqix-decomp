#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"


struct TransitionOwner0208cfcc { char padding[0x3c]; SafeAllocator allocator; };
struct ActiveEntry02046900;
struct Rec020467f0;
#if defined(jpn)
extern char data_020f12cc[];
#endif
extern char data_020f11eb[];
extern char data_020f11fe[];
extern char data_02108760[];
void SetSubBrightness(GameResources*, int, int);
int CountActiveEntries(ActiveEntry02046900*);
void InitStruct0205a444(char*);
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
extern "C" void func_0205a528(TransitionList0208cfcc*, void*, int, SafeAllocator*);
void WrapAddByteField0x22_0205aed0(void*, char*, unsigned int, int);
void SetBitfieldStoreBytes0205af38(int, char*, int, int);
int IsSubBrightnessTransitionActive(GameResources*);
void SetForwardAndStore0205eb54(void*, int, int);
void DispatchIfField0xc4NonNeg_0205eb90(void*, int, int);
void ForwardField0xc0_0205eb80(void*);

static inline int NoShortDelay0208cfcc(MessageControlOwner* obj) { return (obj->flags & 0x100) == 0; }

// USA: func_0208cfcc
extern "C" ARM void func_0208cfcc(MessageControlOwner* obj) {
    TransitionOwner0208cfcc* owner;
    BackgroundLoader* loader;
    GameResources* resources = func_ov017_0218b5b0();
    loader = BackgroundLoader::GetInstance();
    if (obj->transitionStage == 0) {
        int shortDelay = NoShortDelay0208cfcc(obj) == 0;
        unsigned int limit = 300;
        if (shortDelay) limit = 150;
        if (obj->timer < limit) obj->timer += GameState::GetInstance()->GetTickCount();
        else if (shortDelay) {
            SetSubBrightness(resources, -4, 4);
#if defined(jpn)
            obj->task = loader->QueueLoadFile(data_020f12cc, 0);
#else
            obj->task = loader->QueueLoadFileInGP2(data_020f11eb, data_020f11fe, 0);
#endif
            obj->transitionStage++;
        } else {
            SetFieldD20208bf28(obj, obj->value, 0);
            obj->flags |= 4;
            obj->counter = 0;
            obj->field_d7 = 0;
            obj->transitionStage = 2;
        }
    } else if (obj->transitionStage == 1) {
        if (loader->GetTaskStatus(obj->task)) {
            owner = obj->owner;
            owner->allocator.Reset();
            void* record;
            void* file;
            unsigned int length;
            loader->GetLoadedFileByID(obj->task, &file, &length);
            int count = CountActiveEntries((ActiveEntry02046900*)file);
            InitStruct0205a444((char*)&obj->list);
            obj->list.active = 1;
            obj->list.entries = obj->entries;
            obj->list.type = 3;
            for (int i = 0; i < count; i++) {
                int size;
                void* entry = FindRecordByIndex((Rec020467f0*)file, i, &record, &size);
                func_0205a528(&obj->list, entry, size, &owner->allocator);
            }
            WrapAddByteField0x22_0205aed0(&obj->list, (char*)obj->entries, 3, 64);
            loader->RemoveTask(obj->task);
            obj->task = -1;
            obj->flags |= 4;
            obj->counter = 0;
            obj->field_d7 = 0;
            obj->transitionStage++;
        }
    } else if (obj->transitionStage == 2) {
        if (!IsSubBrightnessTransitionActive(func_ov017_0218b5b0())) {
            SetBitfieldStoreBytes0205af38((int)&obj->list, (char*)&obj->entries[0], 1, 1);
            SetBitfieldStoreBytes0205af38((int)&obj->list, (char*)&obj->entries[1], 1, 1);
            obj->field_d8 = 0;
            obj->blend = 0;
            obj->flags &= ~1;
            obj->transitionStage++;
        }
    } else if (obj->transitionStage == 3) {
        obj->flags |= 8;
        if (obj->blend < 1.0f) obj->blend += 0.2f;
        else {
            obj->blend = 1.0f;
            SetForwardAndStore0205eb54(data_02108760, 110, 110);
            DispatchIfField0xc4NonNeg_0205eb90(data_02108760, 0, 0);
            obj->transitionStage++;
            obj->delay = 30;
        }
    } else if (obj->transitionStage == 4) {
        obj->flags |= 128;
        obj->transitionStage++;
    } else if (obj->transitionStage == 5) {
        if (!(obj->flags & 128)) {
            obj->blend += 0.2f;
            if (1.0f < obj->blend) {
                obj->blend = 1.0f;
                obj->transitionStage++;
            }
        }
    } else if (obj->transitionStage == 6 && obj->delay == 0) {
        ForwardField0xc0_0205eb80(data_02108760);
        obj->state = 1;
        obj->transitionStage = 0;
    }
}
