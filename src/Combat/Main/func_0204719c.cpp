// usa: 0204719c
// jpn: 02047fbc
struct State4719c {
 int field0; short field4,field6; int field8,fieldc,field10,field14,field18;
 int position[3],rotation[3],scale[3]; unsigned char gap40[0x30];
 int field70,field74,field78,field7c; short field80,field82; unsigned char flags;
};
extern "C" void func_0204719c(State4719c* self) {
 self->field0=0;
 self->field6=0;
 self->field8=0;
 self->fieldc=0;
 self->field14=0;
 self->field4=3;
 self->field10=0;
 self->flags &= ~1;
 self->field78 = self->field7c = 0;
 self->field70 = self->field74 = 0;
 self->position[0]=0;
 self->position[1]=0;
 self->position[2]=0;
 self->rotation[0]=0;
 self->rotation[1]=0;
 self->rotation[2]=0;
 self->scale[0]=0x1000;
 self->scale[1]=0x1000;
 self->scale[2]=0x1000;
 self->field82=0x1f;
 self->field80=0x7fff;
 self->flags &= ~2;
 self->flags &= ~4;
}
