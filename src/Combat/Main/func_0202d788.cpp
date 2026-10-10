#include <globaldefs.h>
int GetSharedHalfwordOrBattleDefault();
void SetField0x48UnlessState9Or10(int);
extern "C" int _Z24IssueBattleCommandSlot30issst(int, short, short, unsigned short, unsigned short);
extern "C" void func_0202d840();
extern char data_021015a0[];
// USA: 0202d788; JPN: 0202d2f8
extern "C" ARM int func_0202d788(unsigned short channel) {
    int mask = GetSharedHalfwordOrBattleDefault();
    if (mask == 0x8000) { SetField0x48UnlessState9Or10(3); *(int*)(data_021015a0 + 0x10) = 9; return 3; }
    if (mask == 0) { SetField0x48UnlessState9Or10(0x16); *(int*)(data_021015a0 + 0x10) = 9; return 0x18; }
    while (!(mask & (1 << (channel - 1)))) { ++channel; if (channel > 16) return 0x18; }
    return (unsigned short)_Z24IssueBattleCommandSlot30issst((int)func_0202d840, 3, 0x11, channel, 0x1e);
}
