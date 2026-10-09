#if defined(jpn)
#include <globaldefs.h>

struct Struct_0205c570;
struct Struct_0205bb84;

extern "C" int func_0205d2b8(void* obj, int v);
extern "C" int func_0205eaa8(struct Struct_0205c570* s);
extern "C" int func_0205cee4(struct Struct_0205bb84* s);
extern "C" int func_ov000_021767a0(void* obj, int targetIndex);
extern "C" void func_0205ce64(void* obj, int value);
extern "C" void func_0205eab4(unsigned char* obj, int val);

struct Command_02180634 {
    char pad0[0x10];
    signed char types[8];
    signed char typeIndex;
    char pad19[0x1d - 0x19];
    signed char targetPosition;
};

struct Menu_02180634 {
    char pad0[0x1c];
    signed char defaultPosition;
    char pad1d[0x118 - 0x1d];
    int dirty;
    char pad11c[0x188 - 0x11c];
    unsigned char cursor[0x244 - 0x188];
    unsigned char groupCursor[0x1f54 - 0x244];
    int groupIds[1];
};

// JPN: func_ov000_02180634
extern "C" ARM void func_ov000_02180634(struct Menu_02180634* menu, int unused, int count, struct Command_02180634* cmd) {
    int position;
    if (cmd == NULL) return;
    int type = cmd->types[cmd->typeIndex];
    if (type != 0xe && type != 0x19) return;
    func_0205d2b8(menu->groupCursor, 1);
    position = func_0205eaa8((struct Struct_0205c570*)menu->cursor);
    int group = func_0205cee4((struct Struct_0205bb84*)menu->groupCursor);
    int target = cmd->targetPosition;
    int currentGroup = func_ov000_021767a0(menu, position);
    if (type == 0x19) target = menu->defaultPosition;
    if (position != target) {
        func_0205ce64(menu->groupCursor, currentGroup);
        return;
    }
    if (group == currentGroup) return;
    int prev = -1;
    int groupIndex = -1;
    for (int i = 0; i < count; i++) {
        int id = menu->groupIds[i];
        if (prev != id) {
            groupIndex++;
            prev = id;
            if (group == groupIndex) {
                func_0205eab4(menu->cursor, i);
                menu->dirty = 1;
                return;
            }
        }
    }
}

#endif
