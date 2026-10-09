#if defined(jpn)
#include <globaldefs.h>

// JPN: func_ov031_0221b44c
// Decodes the Nintendo Wi-Fi base64 alphabet, using dot and hyphen with asterisk padding.
// A null output returns the decoded byte count; malformed characters otherwise map to zero.
extern "C" ARM int DecodeNintendoWifiBase64(const char* input, unsigned int length, char* output, unsigned int capacity) {
    if (length & 3) return -1;
    int encodedBitCount = 0;
    unsigned int characterIndex = 0;
    if (length > characterIndex) {
        do {
            if (input[characterIndex] != '*') encodedBitCount += 6;
            ++characterIndex;
        } while (characterIndex < length);
    }
    int decodedByteCount = encodedBitCount / 8;
    if (output == 0) return decodedByteCount;
    if (capacity < (unsigned int)decodedByteCount) return -1;
    if (length == 0) return 0;
    char* destination = output;
    int bytesWritten;
    do {
        char sextets[4];
        char* sextet = sextets;
        int characterIndex = 0;
        do {
            int encodedCharacter = input[characterIndex];
            if (encodedCharacter >= 'A' && encodedCharacter <= 'Z') *sextet = encodedCharacter - 'A';
            else if (encodedCharacter >= 'a' && encodedCharacter <= 'z') *sextet = encodedCharacter - 'G';
            else if (encodedCharacter >= '0' && encodedCharacter <= '9') *sextet = encodedCharacter + 4;
            else if (encodedCharacter == '.') *sextet = 62;
            else if (encodedCharacter == '-') *sextet = 63;
            else *sextet = 0;
            ++characterIndex;
            ++sextet;
        } while (characterIndex < 4);
        destination[0] = (sextets[0] << 2) | (sextets[1] >> 4);
        bytesWritten = destination + 1 - output;
        input += 4;
        if (bytesWritten >= decodedByteCount) break;
        destination[1] = (sextets[1] << 4) | (sextets[2] >> 2);
        bytesWritten = destination + 2 - output;
        if (bytesWritten >= decodedByteCount) break;
        destination[2] = (sextets[2] << 6) | sextets[3];
        destination += 3;
        bytesWritten = destination - output;
    } while (bytesWritten < decodedByteCount);
    return bytesWritten;
}

#endif
