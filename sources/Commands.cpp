#include "../headers/Commands.h"

bool Strcmp(const char* s1, const char* s2)
{
    size_t i1 = 0, i2 = 0;
    size_t s = strlen(s2);
    while (i1 < strlen(s1) && i2 < strlen(s2))
    {
        if (s1[i1] != s2[i2])
            return false;
        i1++, i2++;
    }
    return true;
}

uint8_t getCode(const char* cmd, int& args, bool& useReg)
{
    for (size_t ind = 0; ind < CNT_COMMANDS; ++ind)
    {
        if (Strcmp(cmd, commands[ind].name))
        {
            args = commands[ind].args;
            useReg = commands[ind].use_reg;
            return (uint8_t)commands[ind].code;
        }
    }
    return -1;
}

int32_t getReg(const char* reg)
{
    for (size_t ind = 0; ind < CNT_REGISTRES; ++ind)
    {
        if (Strcmp(reg, registres[ind].name))
        {
            return (int32_t)registres[ind].number;
        }
    }
    return -1;
}

