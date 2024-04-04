#pragma once

#include "../structures/strmap/strmap.h"

typedef enum { // DO NOT CHANGE THE ORDER!!
    ADD = 1,
    SUB = 2,
    MUL = 3,
    DIV = 4,
    JMP = 5,
    JMPN = 6,
    JMPP = 7,
    JMPZ = 8,
    COPY = 9,
    LOAD = 10,
    STORE = 11,
    INPUT = 12,
    OUTPUT = 13,
    STOP = 14,
} Instructions;

char get_instruction_size(Instructions);