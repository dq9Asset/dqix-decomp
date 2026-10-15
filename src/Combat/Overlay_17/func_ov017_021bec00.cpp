#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Resource/Brightness.h"
#include "Resource/MessageSystem.h"
struct Obj020397cc;
struct TailList020469b4;
struct TailNode020469b4;
struct ZoneState021bec00 {
#if defined(jpn)
    char padding[0x240c];
#else
    char padding[0x23ec];
#endif
    ActiveGrottoClass grotto;
};
struct GrottoTransitionData {
    unsigned short id;
    char padding2[2];
    unsigned char flag4;
    char padding5[2];
    unsigned char flag7, flag8, flag9;
    char paddinga;
    signed char fieldb;
    unsigned char flagc;
    char paddingd[3];
    int x, y, z;
    short field1c, field1e;
    int fields20[4];
    char padding30[0x6c-0x30];
    short field6c;
    char padding6e[2];
};
struct PopupState021bec00 {
    unsigned char type, complete;
    char padding2[0x38-2];
    int state;
    char padding3c[4];
    int task;
    SafeAllocator allocator;
    char script[0xa4];
};
extern "C" void func_0202ae18();
extern "C" ZoneState021bec00* func_02012fe4();
extern "C" void VectorizedMemset(void*, int, unsigned int);
extern "C" int sprintf(char*, const char*, ...);
extern "C" void func_020dfec0(void*, SafeAllocator*, void*, unsigned int);
#if defined(jpn)
extern "C" void func_02043270(void*, int, int, int, int);
#else
extern "C" void func_02042b98(void*, int, int, int, int);
#endif
extern "C" void func_ov017_021bef84(PopupState021bec00*);
void CancelPendingAction020397cc(Obj020397cc*, int);
void SetBitsInField4_0203b4d8(unsigned int*, unsigned int);
void* AllocateAligned4_02012d88(AllocatorUnion*, unsigned int);
GrottoTransitionData* GetField0x3f8Address_0200fd0c(GameState*);
void InitAndResetHeader_0219e310(unsigned char*, int);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
void SetByteField0x253_020397c0(void*);
extern AllocatorUnion data_02114e20;
#if defined(jpn)
extern char data_ov017_021d86ac[], data_ov017_021d86c6[];
#else
extern char data_ov017_021d7e98[], data_ov017_021d7eb2[];
#endif
// USA: func_ov017_021bec00
extern "C" ARM void func_ov017_021bec00(PopupState021bec00* self) {
    GameState* game = GameState::GetInstance();
    func_0202ae18();
    GameResources* resources = func_ov017_0218b5b0();
    MessageSystem* controller = GetGlobalField0x1c020421a0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    ActiveGrottoClass* grotto = &func_02012fe4()->grotto;
    game->GetGrottoStruct();
    char text[0x100] = {};
    controller->b19ae = 0;
    if (self->state == 0) {
        CancelPendingAction020397cc((Obj020397cc*)game->GetUnknownGameObject(), 1);
        SetBitsInField4_0203b4d8(&resources->brightnessFlags_0, 0xc0);
        FontBankLoader* music = GetGlobal02109400_02094a00();
        BlankFunction02094b30(music, 0x203, 0);
        if (AlwaysTrue02094b4c(music)) {
            self->state = 1;
            self->allocator.CreateTypeA(AllocateAligned4_02012d88(&data_02114e20, 0xc00), 0xc00);
#if defined(jpn)
            self->task = loader->QueueLoadFile(data_ov017_021d86ac, 0);
#else
            self->task = loader->QueueLoadFile(data_ov017_021d7e98, 0);
#endif
        }
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->task)) {
            void* data;
            unsigned int length;
            loader->GetLoadedFileByID(self->task, &data, &length);
            self->allocator.Reset();
            func_020dfec0(&self->script, &self->allocator, data, length);
            loader->RemoveTask(self->task);
            self->task = -1;
            self->state = 2;
        }
    } else if (self->state == 2) {
        if (!IsBrightnessTransitionActive(resources)) {
            if ((unsigned char&)grotto->unknown_260_[2]) {
                GrottoTransitionData* transition = GetField0x3f8Address_0200fd0c(game);
                VectorizedMemset(transition, 0, 0x70);
                transition->flag4 = 1;
                transition->flag8 = 1;
                transition->flag9 = 1;
                transition->fieldb = -1;
                transition->fields20[0] = -1;
                transition->fields20[1] = -1;
                transition->fields20[2] = -1;
                transition->fields20[3] = -1;
                transition->field1e = -1;
                transition->flagc = 0;
                transition->field6c = -1;
                transition->id = (unsigned short&)grotto->unknown_274_;
                Vector3fix position = *(Vector3fix*)&grotto->unknown_264_[1];
                transition->x = position.x;
                transition->y = position.y;
                transition->z = position.z;
                transition->field1c = 0x3244;
                transition->flag7 = 1;
                TailList020469b4* list;
                unsigned char* node = (unsigned char*)resources->unknown_ptr_array_36fc[4];
                list = (TailList020469b4*)resources->unknown_ptr_array_36fc[0];
                InitAndResetHeader_0219e310(node, 0);
                AppendNodeToTail(list, (TailNode020469b4*)node);
                grotto->unknown_260_[2] = 0;
                func_ov017_021bef84(self);
                self->complete = 1;
            } else {
#if defined(jpn)
                sprintf(text, data_ov017_021d86c6, grotto->GetPopupName());
                func_0204500c(controller, text, 0);
#else
                sprintf(text, data_ov017_021d7eb2, grotto->GetPopupName());
                func_0204500c(controller, text, 0, 256);
#endif
                controller->b19b8 = 1;
                controller->b19af = 0;
#if defined(jpn)
                func_02043270(controller, (256-controller->primaryBounds.width)/2, 64, controller->primaryBounds.width, 30);
#else
                func_02042b98(controller, (256-controller->primaryBounds.width)/2, 64, controller->primaryBounds.width, 30);
#endif
                long long offset = controller->popupPosition.packed;
                int value = (int)offset;
                int count = (int)(offset >> 32) + 3;
                controller->popupPosition.x = value;
                controller->popupPosition.y = count;
                controller->w9a4 = 1;
                controller->active = 1;
                self->state = 3;
            }
        }
    } else if (self->state == 3 && controller->mode == 0) {
        ReinitController02043204(controller);
        SetByteField0x253_020397c0(game->GetUnknownGameObject());
        FontBankLoader* music = GetGlobal02109400_02094a00();
        BlankFunction02094b38(music, 0x1f9);
        func_02094ab0(music);
        func_ov017_021bef84(self);
        self->complete = 1;
    }
}
