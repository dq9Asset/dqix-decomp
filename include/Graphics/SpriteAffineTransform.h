#pragma once

#include <globaldefs.h>
#include "System/Matrix.h"
#include "Resource/MessageRenderResources.h"

struct Matrix2x2 {
    fix32_t values[4];
};




typedef char VerifySpriteMatrixSize[sizeof(Matrix2x2) == 0x10 ? 1 : -1];
typedef char VerifySpriteScaleOffset[offsetof(Struct0205a198, scaleX) == 0xc ? 1 : -1];
typedef char VerifySpriteAngleOffset[offsetof(Struct0205a198, angle) == 0x1c ? 1 : -1];
typedef char VerifySpriteMatrixIndexOffset[offsetof(Struct0205a198, matrixIndex) == 0x20 ? 1 : -1];

extern "C" void func_020c111c(Matrix2x2* rotation, fix32_t sine, fix32_t cosine);
void ScalePairsByTwoFactors_020c1128(const Matrix2x2* source, Matrix2x2* destination,
                           fix32_t scaleX, fix32_t scaleY);
extern "C" void func_0205b0d8(LoadTable* context, Matrix2x2* transform,
                             Matrix2x2* affine, Struct0205a198* sprite);
int GetBits10And11_0205b174(int unused, Struct0205a198* sprite);
