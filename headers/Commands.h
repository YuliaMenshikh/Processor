#pragma once

#include <cstring>
#include <cstdint>

struct InfCode
{
    char* name;
    uint8_t code;
    int args;
    bool use_reg;
};

enum CODE {
    END = 0xA0,
    IN = 0xA1,
    OUTTOP = 0xA2,
    PUSH = 0xA3,
    PUSHR = 0xA4,
    POP = 0xA5,
    POPR = 0xA6,
    CMP = 0xA7,

    ADD = 0xB0,
    SUB = 0xB1,
    MUL = 0xB2,
    DIV = 0xB3,
    MOD = 0xB4,
    SQRT = 0xB5,

    JMP = 0xC0,
    JL = 0xC1,
    JLE = 0xC2,
    JB = 0xC3,
    JBE = 0xC4,
    JE = 0xC5,
    JNE = 0xC6
};


const InfCode commands[] = {
        {"end", END, 0, false},
        {"in", IN, 1, true},
        {"outtop", OUTTOP, 0, false},
        {"pushr", PUSHR, 1, true},
        {"push", PUSH, 1, false},
        {"popr", POPR, 1, true},
        {"pop", POP, 0, false},
        {"cmp", CMP, 0, false},

        {"add", ADD, 0, false},
        {"sub", SUB, 0, false},
        {"mul", MUL, 0, false},
        {"div", DIV, 0, false},
        {"mod", MOD, 0, false},
        {"sqrt", SQRT, 0, false},

        {"jmp", JMP, 1, false},
        {"jle", JLE, 1, false},
        {"jl", JL, 1, false},
        {"jbe", JBE, 1, false},
        {"jb", JB, 1, false},
        {"je", JE, 1, false},
        {"jne", JNE, 1, false}

};

const size_t CNT_COMMANDS = sizeof(commands) / sizeof(InfCode);

bool Strcmp(const char* s1, const char* s2);

uint8_t getCode(const char* cmd, int& args, bool& useReg);

//=================

struct InfReg
{
    char* name;
    int32_t number;
};

const InfReg registres[] = {
        {"r0", 0},
        {"r1", 1},
        {"r2", 2},
        {"r3", 3},
        {"r4", 4},
        {"r5", 5},
        {"r6", 6}
};

const size_t CNT_REGISTRES = sizeof(registres) / sizeof(InfReg);

int32_t getReg(const char* reg);