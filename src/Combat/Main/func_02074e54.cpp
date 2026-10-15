#include <globaldefs.h>

struct BgControl02074e54 {
    unsigned short priority : 2;
    unsigned short charBase : 4;
    unsigned short mosaic : 1;
    unsigned short colorMode : 1;
    unsigned short screenBase : 5;
    unsigned short bgExtPltt : 1;
    unsigned short screenSize : 2;
};

struct BgControlBackup02074e54 {
    BgControl02074e54 mainBg0;
    BgControl02074e54 subBg0;
    BgControl02074e54 mainBg1;
    BgControl02074e54 subBg1;
    BgControl02074e54 mainBg2;
    BgControl02074e54 subBg2;
    BgControl02074e54 mainBg3;
    BgControl02074e54 subBg3;
    unsigned char mainSaved;
    unsigned char subSaved;
};

#define REG_DB_BG0CNT (*(volatile unsigned short*)0x4001008)
#define REG_DB_BG1CNT (*(volatile unsigned short*)0x400100a)
#define REG_DB_BG2CNT (*(volatile unsigned short*)0x400100c)
#define REG_DB_BG3CNT (*(volatile unsigned short*)0x400100e)

// USA: func_02074e54
extern "C" ARM void func_02074e54(struct BgControlBackup02074e54* backup) {
    if (!backup->subSaved) return;
    REG_DB_BG0CNT = (unsigned short)(((short)backup->subBg0.screenSize << 14) | (REG_DB_BG0CNT & 0x43) |
                                     ((short)backup->subBg0.colorMode << 7) | ((short)backup->subBg0.screenBase << 8) |
                                     ((short)backup->subBg0.charBase << 2) | ((short)backup->subBg0.bgExtPltt << 13));
    REG_DB_BG1CNT = (unsigned short)(((short)backup->subBg1.screenSize << 14) | (REG_DB_BG1CNT & 0x43) |
                                     ((short)backup->subBg1.colorMode << 7) | ((short)backup->subBg1.screenBase << 8) |
                                     ((short)backup->subBg1.charBase << 2) | ((short)backup->subBg1.bgExtPltt << 13));
    REG_DB_BG2CNT = (unsigned short)(((short)backup->subBg2.screenSize << 14) | (REG_DB_BG2CNT & 0x43) |
                                     ((short)backup->subBg2.colorMode << 7) | ((short)backup->subBg2.screenBase << 8) |
                                     ((short)backup->subBg2.charBase << 2));
    REG_DB_BG3CNT = (unsigned short)(((short)backup->subBg3.screenSize << 14) | (REG_DB_BG3CNT & 0x43) |
                                     ((short)backup->subBg3.colorMode << 7) | ((short)backup->subBg3.screenBase << 8) |
                                     ((short)backup->subBg3.charBase << 2));
    REG_DB_BG0CNT = (unsigned short)((REG_DB_BG0CNT & ~3) | backup->subBg0.priority);
    REG_DB_BG1CNT = (unsigned short)((REG_DB_BG1CNT & ~3) | backup->subBg1.priority);
    REG_DB_BG2CNT = (unsigned short)((REG_DB_BG2CNT & ~3) | backup->subBg2.priority);
    REG_DB_BG3CNT = (unsigned short)((REG_DB_BG3CNT & ~3) | backup->subBg3.priority);
    if (backup->subBg0.mosaic) {
        REG_DB_BG0CNT |= 0x40;
    } else {
        REG_DB_BG0CNT &= ~0x40;
    }
    if (backup->subBg1.mosaic) {
        REG_DB_BG1CNT |= 0x40;
    } else {
        REG_DB_BG1CNT &= ~0x40;
    }
    if (backup->subBg2.mosaic) {
        REG_DB_BG2CNT |= 0x40;
    } else {
        REG_DB_BG2CNT &= ~0x40;
    }
    if (backup->subBg3.mosaic) {
        REG_DB_BG3CNT |= 0x40;
    } else {
        REG_DB_BG3CNT &= ~0x40;
    }
}
