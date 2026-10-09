#if defined(jpn)
#include <globaldefs.h>
#include <std_library_functions.h>

// JPN: func_ov000_02170f58
// Finds the six neighbors of a cell on the staggered battle grid.
// A missing neighbor is 255; odd rows have one fewer usable column.
extern "C" ARM void GetBattleGridNeighbors(unsigned char* neighborCells, const int* gridCell)
{
    int column = *gridCell % 9;
    int row = *gridCell / 9;
    unsigned char neighbors[6];
    if (row % 2 == 0) {
        if (column == 0) {
            if (row == 0) {
                neighbors[0] = 255;
                neighbors[1] = column + (row + 1) * 9;
                neighbors[2] = 255;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = 255;
                neighbors[5] = 255;
            } else if (row == 8) {
                neighbors[0] = 255;
                neighbors[1] = 255;
                neighbors[2] = 255;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = 255;
                neighbors[5] = column + (row - 1) * 9;
            } else {
                neighbors[0] = 255;
                neighbors[1] = column + (row + 1) * 9;
                neighbors[2] = 255;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = 255;
                neighbors[5] = column + (row - 1) * 9;
            }
        } else if (column == 8) {
            if (row == 0) {
                neighbors[0] = column - 1 + (row + 1) * 9;
                neighbors[1] = 255;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = 255;
                neighbors[4] = 255;
                neighbors[5] = 255;
            } else if (row == 8) {
                neighbors[0] = 255;
                neighbors[1] = 255;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = 255;
                neighbors[4] = column - 1 + (row - 1) * 9;
                neighbors[5] = 255;
            } else {
                neighbors[0] = column - 1 + (row + 1) * 9;
                neighbors[1] = 255;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = 255;
                neighbors[4] = column - 1 + (row - 1) * 9;
                neighbors[5] = 255;
            }
        } else {
            if (row == 0) {
                neighbors[0] = column - 1 + (row + 1) * 9;
                neighbors[1] = column + (row + 1) * 9;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = 255;
                neighbors[5] = 255;
            } else if (row == 8) {
                neighbors[0] = 255;
                neighbors[1] = 255;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = column - 1 + (row - 1) * 9;
                neighbors[5] = column + (row - 1) * 9;
            } else {
                neighbors[0] = column - 1 + (row + 1) * 9;
                neighbors[1] = column + (row + 1) * 9;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = column - 1 + (row - 1) * 9;
                neighbors[5] = column + (row - 1) * 9;
            }
        }
    } else {
        if (column == 0) {
            if (row == 8) {
                neighbors[0] = 255;
                neighbors[1] = 255;
                neighbors[2] = 255;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = column + (row - 1) * 9;
                neighbors[5] = column + 1 + (row - 1) * 9;
            } else {
                neighbors[0] = column + (row + 1) * 9;
                neighbors[1] = column + 1 + (row + 1) * 9;
                neighbors[2] = 255;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = column + (row - 1) * 9;
                neighbors[5] = column + 1 + (row - 1) * 9;
            }
        } else if (column == 7) {
            if (row == 8) {
                neighbors[0] = 255;
                neighbors[1] = 255;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = 255;
                neighbors[4] = column + (row - 1) * 9;
                neighbors[5] = column + 1 + (row - 1) * 9;
            } else {
                neighbors[0] = column + (row + 1) * 9;
                neighbors[1] = column + 1 + (row + 1) * 9;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = 255;
                neighbors[4] = column + (row - 1) * 9;
                neighbors[5] = column + 1 + (row - 1) * 9;
            }
        } else if (column < 7) {
            if (row == 8) {
                neighbors[0] = 255;
                neighbors[1] = 255;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = column + (row - 1) * 9;
                neighbors[5] = column + 1 + (row - 1) * 9;
            } else {
                neighbors[0] = column + (row + 1) * 9;
                neighbors[1] = column + 1 + (row + 1) * 9;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = column + (row - 1) * 9;
                neighbors[5] = column + 1 + (row - 1) * 9;
            }
        } else {
            neighbors[0] = 255;
            neighbors[1] = 255;
            neighbors[2] = 255;
            neighbors[3] = 255;
            neighbors[4] = 255;
            neighbors[5] = 255;
        }
    }
    INLINE_MEMCPY(neighborCells, neighbors, sizeof(neighbors));
}

#endif
