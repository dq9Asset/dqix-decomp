#include <globaldefs.h>

struct AdpcmState_0218feb4 {
    int predictor;
    int stepIndex;
};

extern const short data_ov016_0219cef0[];
extern const signed char data_ov016_0219cee0[];

// USA: func_ov016_0218feb4
extern "C" ARM void func_ov016_0218feb4(AdpcmState_0218feb4* state, unsigned char* input, int length, unsigned int* output) {
    int i = 0;
    if (length <= 0) return;
    do {
        int nibble = input[i];
        int first;
        int step1 = data_ov016_0219cef0[state->stepIndex];
        state->stepIndex += data_ov016_0219cee0[nibble & 7];
        if (state->stepIndex < 0) state->stepIndex = 0;
        if (state->stepIndex > 88) state->stepIndex = 88;
        int diff1 = step1 >> 3;
        if (nibble & 4) diff1 += step1;
        if (nibble & 2) diff1 += step1 >> 1;
        if (nibble & 1) diff1 += step1 >> 2;
        if (nibble & 8) state->predictor -= diff1;
        else state->predictor += diff1;
        if (state->predictor < -0x8000) state->predictor = -0x8000;
        if (state->predictor > 0x7fff) state->predictor = 0x7fff;

        nibble >>= 4;
        first = state->predictor;
        int step2 = data_ov016_0219cef0[state->stepIndex];
        state->stepIndex += data_ov016_0219cee0[nibble & 7];
        if (state->stepIndex < 0) state->stepIndex = 0;
        if (state->stepIndex > 88) state->stepIndex = 88;
        int diff2 = step2 >> 3;
        if (nibble & 4) diff2 += step2;
        if (nibble & 2) diff2 += step2 >> 1;
        if (nibble & 1) diff2 += step2 >> 2;
        if (nibble & 8) state->predictor -= diff2;
        else state->predictor += diff2;
        if (state->predictor < -0x8000) state->predictor = -0x8000;
        if (state->predictor > 0x7fff) state->predictor = 0x7fff;

        *output++ = (unsigned short)first | (state->predictor << 16);
        i++;
    } while (i < length);
}
