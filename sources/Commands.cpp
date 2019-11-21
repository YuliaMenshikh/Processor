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
    // Search matched cmd-name
    for (size_t cmd_index = 0; cmd_index < CNT_COMMANDS; ++cmd_index)
    {
        if (Strcmp(cmd, commands[cmd_index].name))
        {
            args = commands[cmd_index].args;
            useReg = commands[cmd_index].use_reg;
            return (uint8_t)commands[cmd_index].code;
        }
    }
    return -1;
}

int32_t getReg(const char* reg)
{
    for (size_t reg_index = 0; reg_index < CNT_REGISTRES; ++reg_index)
    {
        if (Strcmp(reg, registres[reg_index].name))
        {
            return (int32_t)registres[reg_index].number;
        }
    }
    return -1;
}

