#if defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

extern "C" GameObject* func_0200fd78(GameState*, int);

extern "C" int func_02054fe4(unsigned char* obj);
struct Field150Holder02052e2c;
extern "C" short* func_020541fc(Field150Holder02052e2c* obj);
struct StructDE234_020de234 {
    int a, b, c, d;
    unsigned int field10Low : 10;
    unsigned int field10Mid : 10;
    unsigned int field10High : 8;
    unsigned int field10Unused : 4;
    short e, f, g, h, i;
};
extern "C" unsigned short func_020dfbb0(StructDE234_020de234* p, int preferMid);
struct EffectTable02072e94 {
    short values[10];
    unsigned char preferred : 1;
    unsigned char otherFlags : 7;
    unsigned char adjustment : 4;
    unsigned char otherAdjustment : 4;
};
struct Suffix02072e94 { char text[8]; };
struct Letters02072e94 { char text[10]; };
extern Suffix02072e94 data_020e8948;
extern Letters02072e94 data_020e8950;
extern char data_020f0dfc[];
extern char data_020f0e02[];

// JPN: func_02074024
extern "C" ARM int func_02074024(char* out, int combatantId, int kind,
                                StructDE234_020de234* entry, void* optional) {
    GameObject* combatant = func_0200fd78(GameState::GetInstance(), combatantId);
    unsigned char* fields = (unsigned char*)func_02054fe4((unsigned char*)combatant);
    EffectTable02072e94* table = (EffectTable02072e94*)func_020541fc((Field150Holder02052e2c*)combatant);
    int preferred = table->preferred;
    int value = func_020dfbb0(entry, table->preferred);
    StructDE234_020de234* alternate = NULL;
    StructDE234_020de234* primary = NULL;
    if (optional != NULL) {
        primary = (StructDE234_020de234*)optional;
        alternate = (StructDE234_020de234*)((char*)optional + 0xe0);
    }
    Suffix02072e94 suffix = data_020e8948;
    char letter[2] = {};
    char extra[2] = {};
    if (kind == 4) {
        strcpy(suffix.text, data_020f0dfc);
        letter[0] = 'a';
        letter[1] = 0;
        value += table->adjustment;
    }
    int alternateValue = -1;
    if (alternate != NULL && alternate->g > -1) {
        alternateValue = func_020dfbb0(alternate, preferred);
    }
    if (kind == 3) {
        letter[0] = 'a';
        letter[1] = 0;
        if (alternateValue >= 0) {
            unsigned int category = alternateValue / 100;
            if (category < 10) {
                Letters02072e94 letters = data_020e8950;
                char c = letters.text[category];
                if (c == 0) return 0;
                letter[0] = c;
                if (category == 3 && preferred == 0 && table->values[3] == 9001) {
                    letter[0] = 'f';
                }
            } else {
                return 0;
            }
        }
    }
    if (kind == 5 && primary != NULL) {
        if (table->values[4] == 8010 || table->values[4] < 0) {
            value = func_020dfbb0(primary, preferred);
        }
        strcpy(suffix.text, data_020f0dfc);
    }
    if (kind == 6) strcpy(suffix.text, data_020f0dfc);
    if (entry->g == 1000) value += fields[0x56a];
    sprintf(out, data_020f0e02, (char)entry->field10High, value, letter, extra, suffix.text);
    return 1;
}


#endif
