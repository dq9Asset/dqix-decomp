// usa: 0206ea8c
// jpn: 0206fbe0
struct BitSet {char pad[0x41b]; unsigned char bits[2][32];};
extern "C" void func_0206ea8c(BitSet* object,int which,int index,int enabled){
short slot=which&1;
short byte=index>>3;
unsigned short bit=index&7; bit ^= 7;

if(enabled) object->bits[slot][byte] |= 1<<bit; else object->bits[slot][byte] &= ~(1<<bit);
}
