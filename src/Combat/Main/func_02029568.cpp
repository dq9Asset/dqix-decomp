// usa: 02029568
// jpn: 02029120
void Init0202949c(char*);
extern "C" unsigned short data_020ef74c;
extern "C" void func_02029568(char* self) {
 Init0202949c(self);
 *(int*)(self+0)=1;
 *(short*)(self+0x50)=0; *(short*)(self+0x52)=0; *(short*)(self+0x54)=0;
 *(short*)(self+0x56)=0; *(short*)(self+0x58)=0; self[0x6c]=1;
 *(short*)(self+0x5a)=0;
 *(short*)(self+0x5c)=-1; *(short*)(self+0x5e)=-1; *(short*)(self+0x60)=-1;
 self[0x6d]=0; self[0x6e]=0; *(int*)(self+0x44)=0; *(int*)(self+0x48)=0;
 *(unsigned short*)(self+0x62)=10; *(unsigned short*)(self+0x64)=0;
 *(unsigned short*)(self+0x66)=*(unsigned short*)(self+0x62)+*(unsigned short*)(self+0x64);
 self[0x6f]=0; *(short*)(self+0x6a)=0; *(short*)(self+0x68)=0;
 data_020ef74c=0x7d40;
 self[0x71]=0; self[0x72]=0; self[0x73]=0; self[0x74]=0;
 *(int*)(self+0x40)=0; self[0x70]=0; *(int*)(self+0x4c)=8;
 for(int i=0;i<2;++i) *(int*)(self+0x78+i*4)=0;
}
