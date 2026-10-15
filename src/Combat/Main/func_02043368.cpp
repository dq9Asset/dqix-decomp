#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageRenderResources.h"

#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Struct0205a198;
struct ActiveEntry02046900;
struct Rec020467f0;

void Init0205a198(struct Struct0205a198* p);
int CountActiveEntries(struct ActiveEntry02046900* entry);
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* outLength);
extern "C" int func_0205a528(LoadTable* renderer, void* data, int size, SafeAllocator* allocator);

extern char data_020f007f;
extern char data_020f0093;

// USA: func_02043368
extern "C" ARM void func_02043368(MessageSystem* self) {
    if (self->messageAllocator == 0) {
        return;
    }
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (self->messageLoadState == 0) {
        if (self->messageRenderer != 0) {
            return;
        }
        GrottoStruct* grotto = GameState::GetInstance()->GetGrottoStruct();
        if (grotto != 0 && grotto->unknown_0[0] != 0 && grotto->unknown_0[2] == 0) {
            return;
        }
#if defined(jpn)
        self->messageLoadTask = loader->QueueLoadFile(&data_020f0093, 0);
#else
        self->messageLoadTask = loader->QueueLoadFileInGP2(&data_020f007f, &data_020f0093, 0);
#endif
        self->messageLoadState++;
        return;
    }

    if (self->messageLoadState == 1) {
        if (loader->GetTaskStatus(self->messageLoadTask) == 0) {
            return;
        }
        self->messageAllocator->Reset();
        self->messageRenderer = static_cast<LoadTable*>(self->messageAllocator->Allocate(0x54));
        self->messageSprites = static_cast<Struct0205a198*>(self->messageAllocator->Allocate(0xf0));
        self->messageSpriteEntries = static_cast<Container0205a3d0*>(self->messageAllocator->Allocate(8));

        if (self->messageRenderer != 0 && self->messageSprites != 0 && self->messageSpriteEntries != 0) {
            InitStruct0205a444(self->messageRenderer);
            for (unsigned short i = 0; i < 6; i++) {
                Init0205a198(&self->messageSprites[i]);
            }
            ClearField0And40205a234(self->messageSpriteEntries);
            self->messageRenderer->subScreen = 0;
            {
                struct LoadTable* table = self->messageRenderer;
                table->records = self->messageSprites;
                table->recordCount = 6;
            }
            self->messageRenderer->animationEntries = self->messageSpriteEntries;
            self->field234 = 0;

            void* rec;
            void* found;
            unsigned int foundLen;
            int recLen;
            loader->GetLoadedFileByID(self->messageLoadTask, &found, &foundLen);
            int count = CountActiveEntries(static_cast<ActiveEntry02046900*>(found));
            for (int i = 0; i < count; i++) {
                void* r = FindRecordByIndex(static_cast<Rec020467f0*>(found), i, &rec, &recLen);
                func_0205a528(self->messageRenderer, r, recLen, self->messageAllocator);
            }
        }

        loader->RemoveTask(self->messageLoadTask);
        self->messageLoadTask = -1;
        self->messageLoadState++;
        return;
    }

    if (self->messageLoadState == 2) {
        if (self->messageRenderer != 0 && self->messageSpriteEntries != 0) {
            return;
        }
        self->messageRenderer = 0;
        self->messageSprites = 0;
        self->messageSpriteEntries = 0;
        self->field234 = 0;
        self->messageLoadTask = -1;
        self->messageLoadState = 0;
    }
}
