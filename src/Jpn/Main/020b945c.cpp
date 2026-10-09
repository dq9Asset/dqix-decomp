#if defined(jpn)
#include "Graphics/NSBXX/RenderCommands.h"
#include <globaldefs.h>

extern RenderCommandHandler *data_02109f2c;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// JPN: func_020b945c
ARM void ApplyBindPoseScaling(BoneMatrixRenderData *bmrd) {
    RenderCommandHandler *handler = data_02109f2c;
    uint8_t *instructionPointer   = handler->instructionPointer_;
    unsigned int boneIndex        = instructionPointer[1];
    NSBXXNameList *boneList       = handler->boneList_;
    NSBXXBoneMatrix *boneMatrix;
    uint32_t *offset;
    if (boneList == NULL) goto lookup_failed;
    offset = (uint32_t *) boneList->GetEntryv3Safe(boneIndex);
    if (offset == NULL) goto lookup_failed;
    boneMatrix = (NSBXXBoneMatrix *) boneList->GetEntryFromPtrOffset(offset);
    goto lookup_done;
lookup_failed:
    boneMatrix = NULL;
lookup_done:
    intptr_t scaleDataAddress = (intptr_t) (boneMatrix + 1);
    unsigned int boneFlags    = boneMatrix->flags_;
    if (!(boneFlags & 1)) scaleDataAddress += sizeof(NSBXXBoneMatrix::Translation);
    if (!(boneFlags & 2)) {
        if (boneFlags & 8)
            scaleDataAddress += sizeof(NSBXXBoneMatrix::PivotMatrixData);
        else
            scaleDataAddress += sizeof(NSBXXBoneMatrix::RotationMatrixData);
    }
    handler->boneMatrixRenderDataScalePopulateProc_(bmrd, (NSBXXBoneMatrix::Scaling *) scaleDataAddress, instructionPointer,
                                                    boneFlags);
}


#endif
