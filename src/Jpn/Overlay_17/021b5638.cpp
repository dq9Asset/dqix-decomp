#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"

struct StreamHeader;

extern "C" char* func_02012dac(void);
extern "C" int func_020105f8(char* battleStruct);
extern "C" int func_0201062c(char* battleStruct);
extern "C" int func_0201b328(int monsterId);
extern "C" void func_0209da10(
    void* dest, struct StreamHeader* data, int size, int param,
    int monsterId, int field5cb0, int field5cb4);

extern const char data_ov017_021d82b1;

struct ScriptSource_021b4f48 {
    unsigned short monsterId;
    char pad2[0x10 - 0x2];
    int param;
};

struct ScriptRequest_021b4f48 {
    char pad0[8];
    struct ScriptSource_021b4f48* source;
    int taskId;
    unsigned char state;
};

// JPN: func_ov017_021b5638
extern "C" ARM void func_ov017_021b5638(struct ScriptRequest_021b4f48* request) {
    GameState* battle = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)func_02012dac() + 0x240c);

    if (loader->GetTaskStatus(request->taskId) == 0) {
        return;
    }
    if (loader->GetDetailedTaskStatus(request->taskId) == BackgroundLoader::TaskStatus_Complete) {
        unsigned int size;
        void* data;
        loader->GetLoadedFileByID(request->taskId, &data, &size);
        if (data != 0) {
            int monsterId = request->source->monsterId;
            int field5cb0 = func_020105f8((char*)battle);
            int field5cb4 = func_0201062c((char*)battle);
            if (func_0201b328(monsterId)) {
                int rank = grotto->GetFloorMonsterRank(monsterId % 20);
                int environ = grotto->GetActiveGrottoEnviron();
                monsterId = rank + (environ * 100 + 0x9c40);
            }
            func_0209da10(
                (char*)request->source + 0x5c, (struct StreamHeader*)data, size,
                request->source->param, monsterId, field5cb0, field5cb4);
        }
    }
    loader->RemoveTask(request->taskId);
    request->taskId = -1;
    request->taskId = loader->QueueLoadFile(&data_ov017_021d82b1, 0);
    request->state = BackgroundLoader::TaskStatus_Fence;
}

#endif
