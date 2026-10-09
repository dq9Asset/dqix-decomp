#if defined(jpn)
#include <globaldefs.h>

#define VBLANK_COUNT (*(volatile unsigned long*)0x027ffc3c)
#define POWCNT (*(volatile unsigned short*)0x04000304)

#define PM_SUCCESS 0
#define PM_LCD_POWER_OFF 0
#define PM_LCD_POWER_ON 1
#define PM_LED_NONE 0

#define LCD_OFF_WAIT_FRAMES 7
#define LCD_INIT_WAIT_FRAMES 2
#define RETRY_WAIT_CYCLES 0xa3a47

struct PMStatics
{
    unsigned short isInit;
    unsigned long lcdCount;
    unsigned long initCount;
    volatile int sleepEndFlag;
    unsigned long command16Value;
};

extern PMStatics data_0211148c;

extern "C" void func_020cb238(unsigned long cycles);
extern "C" void func_020cb2ec();
extern "C" unsigned long func_020d00e0(int status);
extern "C" unsigned long func_020d007c(int led, void (*callback)(), int* arg);
extern "C" unsigned long func_020d02ac(int value);

// JPN: func_020d0674
extern "C" ARM int func_020d0674(int sw, int led, int skip, int isSync)
{
    switch (sw)
    {
    case PM_LCD_POWER_ON:
        if (!skip && VBLANK_COUNT - data_0211148c.lcdCount <= LCD_OFF_WAIT_FRAMES)
            return false;
        if (led != PM_LED_NONE)
        {
            if (isSync)
            {
                if (func_020d00e0(led) != PM_SUCCESS)
                    do
                        func_020cb238(RETRY_WAIT_CYCLES);
                    while (func_020d00e0(led) != PM_SUCCESS);
            }
            else
            {
                if (func_020d007c(led, NULL, NULL) != PM_SUCCESS)
                    do
                        func_020cb238(RETRY_WAIT_CYCLES);
                    while (func_020d007c(led, NULL, NULL) != PM_SUCCESS);
            }
        }
        POWCNT |= 1;
        if (func_020d02ac(data_0211148c.command16Value) != PM_SUCCESS)
            do
                func_020cb238(RETRY_WAIT_CYCLES);
            while (func_020d02ac(data_0211148c.command16Value) != PM_SUCCESS);
        break;
    case PM_LCD_POWER_OFF:
        if (func_020d02ac(0) != PM_SUCCESS)
            do
                func_020cb238(RETRY_WAIT_CYCLES);
            while (func_020d02ac(0) != PM_SUCCESS);
        if (VBLANK_COUNT - data_0211148c.initCount <= LCD_INIT_WAIT_FRAMES)
        {
            func_020cb2ec();
            func_020cb2ec();
        }
        POWCNT &= ~1;
        data_0211148c.lcdCount = VBLANK_COUNT;
        if (led != PM_LED_NONE)
        {
            if (isSync)
            {
                if (func_020d00e0(led) != PM_SUCCESS)
                    do
                        func_020cb238(RETRY_WAIT_CYCLES);
                    while (func_020d00e0(led) != PM_SUCCESS);
            }
            else
            {
                if (func_020d007c(led, NULL, NULL) != PM_SUCCESS)
                    do
                        func_020cb238(RETRY_WAIT_CYCLES);
                    while (func_020d007c(led, NULL, NULL) != PM_SUCCESS);
            }
        }
        break;
    }
    return true;
}


#endif
