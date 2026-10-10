#include <globaldefs.h>
#include <World/Object3D.h>
typedef Vector3fix EventVector;
extern "C" void func_ov017_021c95ec(int,int,int,int,int,EventVector,int,unsigned char,unsigned char);
static inline short getKind(Object3D* o) { short value=o->unknown_4_; return value; }
// USA: 020794f8; JPN: 0207a3ec
extern "C" ARM void func_020794f8(Object3D* object, unsigned char flag6, unsigned char flag7) {
 int id=object->GetField06();
 int kind=getKind(object);
 int value=object->unknown_2_;
 EventVector position=object->position_;
 short field=*(short*)((char*)object+0xae);
 int index=(kind-0x70)%12;
 if(index>=0 && index<12) func_ov017_021c95ec(id,index,value,1,-1,position,field,flag6,flag7);
}
