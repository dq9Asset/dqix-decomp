#if defined(jpn)
#include "World/ZoneWarpScript.h"

extern Struct_020fdc20 data_020fd98c;
extern "C" void func_0201cb9c(ZoneFeatures::Opcode68Entry *entry);
extern "C" bool func_0201c8ec(Script::Parameter *param, int numParams, ZoneFeatures::Opcode68Entry &entry);
extern "C" void func_0201e300(ZoneFeatures *self, const ZoneFeatures::Opcode68Entry &entry);

// JPN: func_0201cc0c
extern "C" ARM int func_0201cc0c(Script::Parameter *params, int numParams) {
    Script::Parameter *paramsStart = params;
    ZoneFeatures::Opcode68Entry entry;
    func_0201cb9c(&entry);
    fix32_t centreX     = (int) (4096.0f * (params++)->ToFloat());
    fix32_t centreY     = (int) (4096.0f * (params++)->ToFloat());
    fix32_t centreZ     = (int) (4096.0f * (params++)->ToFloat());
    fix32_t halfLengthX = (int) (4096.0f * (params++)->ToFloat()) / 2;
    fix32_t halfLengthY = (int) (4096.0f * (params++)->ToFloat()) / 2;
    fix32_t halfLengthZ = (int) (4096.0f * (params++)->ToFloat()) / 2;

    entry.unk_4[0] = centreX + halfLengthX;
    entry.unk_4[1] = centreY + halfLengthY;
    entry.unk_4[2] = centreZ + halfLengthZ;
    entry.unk_4[3] = centreX - halfLengthX;
    entry.unk_4[4] = centreY - halfLengthY;
    entry.unk_4[5] = centreZ - halfLengthZ;

    entry.unk_58[0] = centreX;
    entry.unk_58[1] = centreY;
    entry.unk_58[2] = centreZ;

    entry.unk_52 = 4096.0f * (params++)->ToFloat();

    fix32_t halfLengthXSquared = FIX32_MULTIPLY(halfLengthX, halfLengthX);
    fix32_t halfLengthZSquared = FIX32_MULTIPLY(halfLengthZ, halfLengthZ);
    entry.unk_54               = halfLengthZSquared;
    entry.unk_54               = halfLengthXSquared + halfLengthZSquared;

    if (!func_0201c8ec(params, numParams - (params - paramsStart), entry)) return 0;
    func_0201e300(data_020fd98c.warp, entry);
    return 1;
}

#endif
