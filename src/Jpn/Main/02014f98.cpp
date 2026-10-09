#if defined(jpn)
#include "World/ZoneObjectResourceLoading.h"
#include <globaldefs.h>

extern "C" void *func_0200fb68(GameState *);
extern "C" void func_02014ae4(int, char *, char *);
extern "C" void func_0207ed10(char *);
extern "C" void func_0207ed2c(char *);
extern char data_020ef124[];
extern const ZoneAnimationResources data_020e77ec;

// JPN: func_02014f98
extern "C" ARM int func_02014f98(Zone3D *zone, Struct02012ff0 *tracker, Src02015134 *source) {
    GameState *gameState      = GameState::GetInstance();
    SafeAllocator *allocator  = zone->pAllocator_68_;
    char *pairTables          = static_cast<char *>(zone->unknown_ptr_50_);
    LightingManager *lighting = LightingManager::GetInstance();
    int applyLighting         = static_cast<ZoneLoadState *>(func_0200fb68(gameState))->unknown20 < 0;
    zone->unknown_834_        = applyLighting;
    char filename[0x50];
    unsigned int size;
    func_02014ae4(source->id, data_020ef124, filename);
    const void *file = GetFileFromNARCInMemory(filename);
    Object3D *object;
    if (file != NULL) {
        tracker->field4    = reinterpret_cast<int>(allocator->Allocate(sizeof(Object3D)));
        void *decompressed = DecompressLZ77FileIntoAllocatedSpace(*allocator, file, size);
        if (decompressed != NULL && tracker->field4 != 0) {
            Object3D *object = reinterpret_cast<Object3D *>(tracker->field4);
            object->Initialize();
            func_0207ed10(pairTables);
            object = reinterpret_cast<Object3D *>(tracker->field4);
            object->SetModelFromFile(allocator, decompressed, size, Model3D::TextureStagingMode_Normal);
            func_0207ed2c(pairTables);
            Model3D *model = reinterpret_cast<Object3D *>(tracker->field4)->pModel_;
            if (model != NULL) {
                NSBXXTex *texture = model->GetTEX0();
                if (texture != NULL) {
                    zone->textureImageMemory_ += NSBXX_Tex_GetBlock1Length(texture);
                    zone->texturePaletteMemory_ += NSBXX_Tex_GetBlock4Length(texture);
                }
                if (!(static_cast<unsigned char>(source->pad[2]) & 0x20) && applyLighting) {
                    lighting->ModelTransformTintBrightnessContrast(model->rawInternalModel_);
                }
                for (Zone3D::Model3DListNode *node = zone->firstModel_418_; node != NULL; node = node->pNext_) {
                    model->ApplyTexturesFromModel(&node->model_);
                    model->SetTEX0(node->model_.GetTEX0());
                }
            }
        }
        object = reinterpret_cast<Object3D *>(tracker->field4);
        if (object == NULL || object->pModel_ == NULL) {
            tracker->field0 = -1;
            return 0;
        }
    } else {
        tracker->field0 = -1;
        return 0;
    }
    if (object != NULL) {
        ZoneAnimationResources resources = data_020e77ec;
        for (ZoneAnimationResource *resource = resources.entries; resource->mask != 0; resource++) {
            if (resource->mask & static_cast<unsigned char>(source->pad[2])) {
                func_02014ae4(source->id, resource->extension, filename);
                const void *animationFile = GetFileFromNARCInMemory(filename);
                if (animationFile != NULL) {
                    void *animationData = DecompressLZ77FileIntoAllocatedSpace(*allocator, animationFile, size);
                    if (animationData != NULL) {
                        if (resource->slot < 0) {
                            object->LoadType0AnimationPackageFromBCFGScript(allocator, animationData, size);
                        } else {
                            object->LoadType0AnimationFromPersistentMemory(resource->slot, allocator, animationData, size);
                        }
                    }
                }
            }
        }
    }
    tracker->field0 = 2;
    return 1;
}


#endif
