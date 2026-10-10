// JPN: main:020db84c
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
struct Struct020d9fc8;
struct Obj020397cc;
void ClearHandleArrayAndFinalize020d9fc8(Struct020d9fc8*);
void CancelPendingAction020397cc(Obj020397cc*,int);
void* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0(unsigned*,unsigned);
struct ResourceTask { char pad[8]; unsigned short flags; unsigned char state; unsigned char padb; int handles[1]; };
typedef void (ResourceTask::*Callback)();
union CallbackPair { Callback entries[2]; unsigned words[4]; };
extern "C" {
#if defined(jpn)
extern const char data_020f2a30[];
extern const CallbackPair data_020ee784;
#define ResourcePath data_020f2a30
#define CallbackTable data_020ee784
#else
extern const char data_020f2838[];
extern const CallbackPair data_020ee678;
#define ResourcePath data_020f2838
#define CallbackTable data_020ee678
#endif
extern Callback data_020e6d5c;
void func_020d9e44(ResourceTask* self) {
 BackgroundLoader* loader=BackgroundLoader::GetInstance();
 if(self->state==0) {
  if(self->flags==0) ClearHandleArrayAndFinalize020d9fc8((Struct020d9fc8*)self);
  else {
   CancelPendingAction020397cc((Obj020397cc*)GameState::GetInstance()->GetUnknownGameObject(),1);
   OrBitsIntoField0((unsigned*)GetDataPtr02114e04_020d6c00(),30);
   if(self->flags&1) self->handles[0]=loader->QueueLoadFile(ResourcePath,0);
   self->state++;
  }
 } else if(self->state==1) {
  int i;
  int complete=0;
  for(i=0;i<1;i++) {
   if(self->handles[i]==-1) complete++;
   else if(loader->GetTaskStatus(self->handles[i])) {
    if(loader->GetDetailedTaskStatus(self->handles[i])==2) break;
    loader->RemoveTask(self->handles[i]);self->handles[i]=-1;
   }
  }
  if(complete==1) self->state=0;
  else if(i!=1) {
   CallbackPair callbacks=CallbackTable;
   callbacks.entries[1]=data_020e6d5c;
   (self->*callbacks.entries[i])();
  }
 }
}
}
