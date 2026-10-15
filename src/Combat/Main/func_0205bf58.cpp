#include <globaldefs.h>

#include "Resource/MessageSystem.h"

struct NavigationSteps { int values[4]; };
struct NavigationKeys { unsigned short values[5]; };
struct NavigationRepeatDirections { unsigned char values[4]; };
int TestFlag0SetAndFlag1Clear_02012444(unsigned short*, int);
int TestFlagMask_02012430(unsigned short*, int);
int TestFlagInSecondWord_02012468(unsigned short*, unsigned int);
void ResetState0205bf3c(Struct_0205bef8*);
int ComputeScaledSum0205bb84(Struct_0205ba2c*);
void AdvanceWrappedAccumulator0205c4a8(Struct_0205ba2c*, int);
extern "C" void func_0205bb04(Struct_0205ba2c*, int);
extern const NavigationKeys data_020e7db8;
extern const NavigationSteps data_020e7dc4;
extern const NavigationRepeatDirections data_020e7db0, data_020e7db4;
extern unsigned short data_02114e30;

// USA: func_0205bf58
extern "C" ARM int func_0205bf58(Struct_0205bef8* navigation, unsigned int ticks) {
    if (navigation->base.count == 0) return 0;
    if (navigation->base.columns <= 0) return 0;
    if (navigation->base.rows <= 0) return 0;
    unsigned char initialDelay = navigation->initialDelay;
    unsigned char repeatDelay = navigation->repeatDelay;
    NavigationKeys keys = data_020e7db8;
    int index = 0;
    while (keys.values[index] != 0xffff && navigation->key == 0) {
        unsigned short key = keys.values[index];
        if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, key)) {
            if (navigation->rowRepeat | navigation->columnRepeat) {
                ResetState0205bf3c(navigation);
                break;
            }
            NavigationSteps steps = data_020e7dc4;
            NavigationRepeatDirections rowRepeats = data_020e7db0;
            NavigationRepeatDirections columnRepeats = data_020e7db4;
            navigation->key = key;
            navigation->countdown = initialDelay;
            navigation->step = steps.values[index];
            navigation->rowRepeat = rowRepeats.values[index];
            navigation->columnRepeat = columnRepeats.values[index];
            if (navigation->key == 0x40 || navigation->key == 0x80) {
                int previous = navigation->base.row;
                navigation->base.row += navigation->step;
                if (navigation->wrapRows) {
                    if (navigation->base.rows <= navigation->base.row) navigation->base.row = 0;
                    else if (navigation->base.row < 0) navigation->base.row = navigation->base.rows - 1;
                    if (navigation->key == 0x40) {
                        int total = navigation->base.count;
                        if (total <= ComputeScaledSum0205bb84(&navigation->base))
                            func_0205bb04(&navigation->base, total - 1);
                    } else if (navigation->key == 0x80) {
                        if (navigation->base.count <= ComputeScaledSum0205bb84(&navigation->base))
                            navigation->base.row = 0;
                    }
                } else {
                    if (navigation->base.rows <= navigation->base.row) navigation->base.row = previous;
                    else if (navigation->base.row < 0) navigation->base.row = previous;
                    if (ComputeScaledSum0205bb84(&navigation->base) >= navigation->base.count)
                        navigation->base.row = previous;
                }
            } else if (navigation->key == 0x20 || navigation->key == 0x10) {
                int previous = navigation->base.column;
                navigation->base.column += navigation->step;
                if (navigation->base.columns <= navigation->base.column) {
                    if (navigation->wrapColumns) {
                        navigation->base.column = 0;
                        if (navigation->base.pages > 1) AdvanceWrappedAccumulator0205c4a8(&navigation->base, 1);
                    } else {
                        if (navigation->base.pages == 1) navigation->base.column = previous;
                        else {
                            navigation->base.column = 0;
                            AdvanceWrappedAccumulator0205c4a8(&navigation->base, 1);
                        }
                    }
                } else if (navigation->base.column < 0) {
                    if (navigation->wrapColumns) {
                        navigation->base.column = navigation->base.columns - 1;
                        if (navigation->base.pages > 1) AdvanceWrappedAccumulator0205c4a8(&navigation->base, -1);
                    } else {
                        if (navigation->base.pages == 1) navigation->base.column = previous;
                        else {
                            navigation->base.column = navigation->base.columns - 1;
                            AdvanceWrappedAccumulator0205c4a8(&navigation->base, -1);
                        }
                    }
                }
                if (ComputeScaledSum0205bb84(&navigation->base) >= navigation->base.count) {
                    if (navigation->base.pages == 1) navigation->base.column = previous;
                    else {
                        navigation->base.column = 0;
                        AdvanceWrappedAccumulator0205c4a8(&navigation->base, 1);
                    }
                }
            }
            return 1;
        }
        ++index;
    }
    if (navigation->rowRepeat) {
        if (TestFlagMask_02012430(&data_02114e30, 0xf0)) {
            unsigned char elapsed = ticks;
            if (elapsed < navigation->countdown) navigation->countdown -= elapsed;
            else {
                navigation->countdown = repeatDelay;
                navigation->rowRepeat = 1;
                navigation->columnRepeat = 0;
                navigation->base.row += navigation->step;
                if (navigation->base.rows <= navigation->base.row) navigation->base.row = navigation->base.rows - 1;
                else if (navigation->base.row < 0) navigation->base.row = 0;
                int total = navigation->base.count;
                if (total <= ComputeScaledSum0205bb84(&navigation->base))
                    func_0205bb04(&navigation->base, total - 1);
                if (navigation->key == 0x40 || navigation->key == 0x20) {
                    int total = navigation->base.count;
                    if (total <= ComputeScaledSum0205bb84(&navigation->base))
                        func_0205bb04(&navigation->base, total - 1);
                } else if (navigation->key == 0x80 || navigation->key == 0x10) {
                    if (navigation->base.count <= ComputeScaledSum0205bb84(&navigation->base))
                        navigation->base.row = 0;
                }
            }
        }
        if (TestFlagInSecondWord_02012468(&data_02114e30, 0xf0)) ResetState0205bf3c(navigation);
        return 1;
    } else if (navigation->columnRepeat) {
        if (TestFlagMask_02012430(&data_02114e30, 0xf0)) {
            unsigned char elapsed = ticks;
            if (elapsed < navigation->countdown) navigation->countdown -= elapsed;
            else {
                navigation->countdown = repeatDelay;
                navigation->rowRepeat = 0;
                navigation->columnRepeat = 1;
                navigation->base.column += navigation->step;
                if (navigation->base.columns <= navigation->base.column) {
                    navigation->base.column = navigation->base.columns - 1;
                    AdvanceWrappedAccumulator0205c4a8(&navigation->base, 1);
                } else if (navigation->base.column < 0) {
                    navigation->base.column = 0;
                    AdvanceWrappedAccumulator0205c4a8(&navigation->base, -1);
                }
                if (ComputeScaledSum0205bb84(&navigation->base) >= navigation->base.count) {
                    if (navigation->base.pages == 1) navigation->base.column = 0;
                    else {
                        navigation->base.column = 0;
                        AdvanceWrappedAccumulator0205c4a8(&navigation->base, 1);
                    }
                }
            }
        }
        if (TestFlagInSecondWord_02012468(&data_02114e30, 0xf0)) ResetState0205bf3c(navigation);
        return 1;
    }
    return 0;
}
