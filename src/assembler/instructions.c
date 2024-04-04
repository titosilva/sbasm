#include "instructions.h"

char get_instruction_size(Instructions ins) {
    if (ins == STOP) {
        return 1;
    }

    if (ins == COPY) {
        return 3;
    }

    if (ins >= ADD && ins <= STOP) {
        return 2;
    }

    return -1;
}