#include <globaldefs.h>
#include "Resource/MessageFrame.h"

// USA: func_020e1588
ARM void InitStruct020e1588(MessageFramePanel* panel) {
    panel->layouts = NULL;
    panel->object = NULL;
    panel->clips = NULL;
    ClearHeaderFields020e1354(&panel->headers[0]);
    ClearHeaderFields020e1354(&panel->headers[1]);
    ClearZeroStruct_020e1568(&panel->clipping);
    panel->offset = 0;
    panel->stride = 0;
    panel->y = 0;
    panel->x = 0;
    panel->height = 0;
    panel->width = 0;
    panel->count = 0;
    panel->flag3d = 0;
    panel->display = 0;
    panel->flag0 = 0;
    panel->flag1 = 0;
}
