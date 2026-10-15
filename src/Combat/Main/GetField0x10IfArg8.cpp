#include <globaldefs.h>
#include "Resource/FontGlyphTable.h"
#include "Resource/MessageSystem.h"

// USA: func_020429bc
ARM FontGlyphTable* GetFontGlyphTable_020429bc(int pixelSize) {
    FontGlyphTable* table = NULL;
#if defined(jpn)
    switch (pixelSize) {
    case 6: table = data_02107800.font6; break;
    case 8: table = data_02107800.font8; break;
    case 10: table = data_02107800.font10; break;
    case 12: table = data_02107800.font12; break;
    }
#else
    if (pixelSize == 8) table = data_02107800.font8;
#endif
    return table;
}
