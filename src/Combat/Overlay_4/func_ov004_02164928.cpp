#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/DetailedTreasureMapData.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "std_library_functions.h"
#include "World/Zone3D.h"

struct MapList02164928 {
    TreasureMapMetadata maps[99];
    DetailedTreasureMapData details[8];
    unsigned char count;
};
struct MapCoordinates02164928 { int x, y, z; };
struct Payload0201165c { MapCoordinates02164928 coordinates; unsigned int environment, monsterRank; };
struct Obj021f9bb0;
struct Obj020d8080;
struct TailList020469b4;
struct TailNode020469b4;
extern MapList02164928* data_ov004_02171010;
GameResources* GetWord0x0_0200fb8c(int*);
extern "C" Zone3D* func_02012fe4();
int IsBrightnessTransitionActive(GameResources*);
int GetScaledStat_021634dc_021634dc(void*);
extern "C" void* func_ov011_021849c8(void*);
extern "C" Obj021f9bb0* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(Obj021f9bb0*);
unsigned int GetShort28_021f9bb0(Obj021f9bb0*);
void InitTreasureMapEntry0201165c(char*, const void*, int, Payload0201165c);
typedef void (*InitMap02164928)(char*, const void*, int, MapCoordinates02164928, unsigned int, unsigned int);
extern "C" unsigned char func_02090294(ActiveGrottoClass*);
extern "C" void func_0208f748(char*, int*);
void EnqueueEventTag163_021cfcec(unsigned char);
void ClearBitArray_02011408(void*);
extern "C" int* func_0202ae18();
int CheckField0NonZero_0202b7d8(int*);
extern "C" int func_0202c508(int*);
extern "C" void func_ov017_021cfabc();
extern "C" void func_ov017_021cf730(int, int);
void EnqueueEventTag167_021d3ec8();
void InitObject020d8080(Obj020d8080*);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);

// JPN: 0x02164fe8; USA/EUR: 0x02164928.
extern "C" ARM int func_ov004_02164928(void* self) {
    if (data_ov004_02171010->count == 0) return 0;
    GameState* state = GameState::GetInstance();
    GameResources* resources = GetWord0x0_0200fb8c(reinterpret_cast<int*>(state));
    Zone3D* zone = func_02012fe4();
    ActiveGrottoClass* area = zone->GetActiveGrotto();
    GrottoStruct* grotto = state->GetGrottoStruct();
    if (IsBrightnessTransitionActive(resources)) return 0;
    for (int i = 0; i < data_ov004_02171010->count; ++i)
        data_ov004_02171010->maps[i].ClearInitialByteUnknownBit();
    int mapIndex = GetScaledStat_021634dc_021634dc(self);
    for (int i = 0; i < 99; ++i)
        data_ov004_02171010->maps[i].ClearInitialByteUnknownBit();
    data_ov004_02171010->maps[mapIndex].SetInitialByteUnknownBit();
    Obj021f9bb0* node = func_ov023_021f6880(func_ov011_021849c8(self), 10);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 7) return 0;
    unsigned int detailIndex = GetShort28_021f9bb0(node);
#if defined(jpn)
    if (data_ov004_02171010->details[detailIndex].mapType_ == 1) {
        reinterpret_cast<InitMap02164928>(InitTreasureMapEntry0201165c)(reinterpret_cast<char*>(state), &data_ov004_02171010->maps[mapIndex], data_ov004_02171010->details[detailIndex].entranceZoneID_, *reinterpret_cast<MapCoordinates02164928*>(&data_ov004_02171010->details[detailIndex].entranceX_), data_ov004_02171010->details[detailIndex].regular_.environ_, data_ov004_02171010->details[detailIndex].regular_.startingMonsterRank_);
        grotto->unknown_8 = func_02090294(area);
    } else if (data_ov004_02171010->details[detailIndex].mapType_ == 2) {
        reinterpret_cast<InitMap02164928>(InitTreasureMapEntry0201165c)(reinterpret_cast<char*>(state), &data_ov004_02171010->maps[mapIndex], data_ov004_02171010->details[detailIndex].entranceZoneID_, *reinterpret_cast<MapCoordinates02164928*>(&data_ov004_02171010->details[detailIndex].entranceX_), 0, 0);
        grotto->unknown_8 = func_02090294(area);
    }
    strcpy(grotto->activeMapImageName, data_ov004_02171010->details[detailIndex].mapImageName_);
    if (data_ov004_02171010->details[detailIndex].mapType_ == 1) {
        DetailedTreasureMapData::RegularMapData* regular = &data_ov004_02171010->details[detailIndex].regular_;
        sprintf(grotto->activeMapNameNoLevel, regular->nameNoLevel_);
        grotto->activeMapLevel = data_ov004_02171010->details[detailIndex].regular_.level_;
    } else if (data_ov004_02171010->details[detailIndex].mapType_ == 2) {
        DetailedTreasureMapData::LegacyBossMapData* legacy = &data_ov004_02171010->details[detailIndex].legacy_;
        sprintf(grotto->activeMapNameNoLevel, legacy->mapNameNoLevel_);
        grotto->activeMapLevel = data_ov004_02171010->details[detailIndex].legacy_.level_;
    }
#else
    MapList02164928* maps = data_ov004_02171010;
    DetailedTreasureMapData* detail = &maps->details[detailIndex];
    if (detail->mapType_ == 1) {
        reinterpret_cast<InitMap02164928>(InitTreasureMapEntry0201165c)(reinterpret_cast<char*>(state), &maps->maps[mapIndex], detail->entranceZoneID_, *reinterpret_cast<MapCoordinates02164928*>(&detail->entranceX_), detail->regular_.environ_, detail->regular_.startingMonsterRank_);
        grotto->unknown_8 = func_02090294(area);
    } else if (detail->mapType_ == 2) {
        reinterpret_cast<InitMap02164928>(InitTreasureMapEntry0201165c)(reinterpret_cast<char*>(state), &maps->maps[mapIndex], detail->entranceZoneID_, *reinterpret_cast<MapCoordinates02164928*>(&detail->entranceX_), 0, 0);
        grotto->unknown_8 = func_02090294(area);
    }
    strcpy(grotto->activeMapImageName, detail->mapImageName_);
    if (detail->mapType_ == 1) {
        DetailedTreasureMapData::RegularMapData* regular = &detail->regular_;
        sprintf(grotto->activeMapNameNoLevel, regular->nameNoLevel_);
        grotto->activeMapLevel = detail->regular_.level_;
        *reinterpret_cast<unsigned short*>(grotto->unk_a) = detail->regular_.suffix_;
    } else if (detail->mapType_ == 2) {
        DetailedTreasureMapData::LegacyBossMapData* legacy = &detail->legacy_;
        sprintf(grotto->activeMapNameNoLevel, legacy->mapNameNoLevel_);
        grotto->activeMapLevel = detail->legacy_.level_;
        *reinterpret_cast<unsigned short*>(grotto->unk_a) = 0;
    }
#endif
    GrottoStruct* active = state->GetGrottoStruct();
    char* event = zone->unk_2664;
    if (active->unknown_0[0]) {
        if (active->activeMapData.GetDiscoveryState() == DiscoveryState_Discovered ||
            active->activeMapData.GetDiscoveryState() == DiscoveryState_Cleared) {
            func_0208f748(event, &active->entranceX);
        }
    }
    active->unknown_0[3] = 0;
    EnqueueEventTag163_021cfcec(1);
    ClearBitArray_02011408(state);
    int* context = func_0202ae18();
    if (CheckField0NonZero_0202b7d8(context) && func_0202c508(context)) {
        func_ov017_021cfabc();
        func_ov017_021cf730(-1, 0);
        EnqueueEventTag167_021d3ec8();
    }
#if defined(jpn)
    if (data_ov004_02171010->details[detailIndex].discoveryState_ == 1) {
#else
    if (detail->discoveryState_ == 1) {
#endif
        TailList020469b4* list;
        Obj020d8080* object = static_cast<Obj020d8080*>(resources->unknown_ptr_array_3afc[42]);
        list = static_cast<TailList020469b4*>(resources->unknown_ptr_array_36fc[0]);
        InitObject020d8080(object);
        AppendNodeToTail(list, reinterpret_cast<TailNode020469b4*>(object));
    }
    return 0;
}
