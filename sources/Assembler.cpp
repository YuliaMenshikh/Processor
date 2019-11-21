#include <string>

#include "../headers/Assembler.h"
#include "../headers/Commands.h"

Assembler::Assembler(const char *fileName) : _buffer(fileName){}

void Assembler::assemble(const char *fileOut)
{
    preprocess();
    FILE* file = fopen(fileOut, "w");
    for (int line = 0; line < _buffer.StringsCount(); ++line)
    {
        if (_buffer[line][_buffer[line].length() - 1] == ':')
            continue;

        int args = -1;
        bool reg = -1;
        char code = (char)getCode(&_buffer[line][0], args, reg);
        fputc(code, file);
        if (args == 1)
        {
            const char* arg = &_buffer[line][0];
            while (*arg != ' ')
                arg++;
            arg++;

            uint32_t argument;
            bool jump = (bool)((code & (uint8_t)0xF0) == 0xC0);

            if (jump)
            {
                std::string_view s(arg, _buffer[line].length() - (arg - &_buffer[line][0]));
                argument = labels[std::string(s)];
            }
            else if (reg)
            {
                argument = getReg(arg);
            }
            else
            {
                argument = (int32_t)strtoll(arg, nullptr, 10);
            }
            int j = 0;
            char p;
            while (j < 4)
            {
                p = (char)(argument << (j * 8) >> (3 * 8));
                j++;
                fputc(p, file);
            }

        }
    }
    fclose(file);
}

void Assembler::preprocess()
{
    uint32_t jumpTo = 0;
    for (size_t line = 0; line < _buffer.StringsCount(); ++line)
    {
        int args = -1;
        bool reg = -1;
        getCode(&_buffer[line][0], args, reg);
        if (_buffer[line][0] == ' ')
            continue;

        if (_buffer[line][_buffer[line].length() - 1] == ':')
        {
            std::string_view s(&_buffer[line][0], _buffer[line].length() - 1);
            labels[std::string(s)] = jumpTo;
        }
        else if (args)
        {
            jumpTo += 5;
        }
        else
        {
            ++jumpTo;
        }
    }
}