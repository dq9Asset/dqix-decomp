#include <globaldefs.h>
#include "Resource/MessageSystem.h"
void SetIndexIfValid0205bcdc(Struct_0205bbcc*, int);

// USA: func_0205bd78
extern "C" ARM int func_0205bd78(Struct_0205bbcc* s, int x, int y) {
    if (s->rectangleCount == 0) return -1;
    if (s->lefts == 0) return -1;
    if (s->tops == 0) return -1;
    if (s->widths == 0) return -1;
    if (s->heights == 0) return -1;

    x -= s->xOffset;
    y -= s->yOffset;

    int row = 0;
    while (row < *s->base.secondaryDimension) {
        int col = 0;
        while (col < *s->base.primaryDimension) {
            int idx = col * *s->base.secondaryDimension + row;
            if (s->rectangleCount > idx) {
                short a = s->lefts[idx];
                short b = s->tops[idx];
                short c = s->widths[idx];
                short d = s->heights[idx];
                int right = a + c;
                int bottom = b + d;
                if (x >= a && right >= x && y >= b && bottom >= y) {
                    *s->base.secondaryCursor = row;
                    *s->base.primaryCursor = col;
                    int result = GetScaledSumIfActive0205bd04(s);
                    if (s->base.count <= result) result = -1;
                    SetIndexIfValid0205bcdc(s, result);
                    return result;
                }
            }
            col++;
        }
        row++;
    }
    return -1;
}
