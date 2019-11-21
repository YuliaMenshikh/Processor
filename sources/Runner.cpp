#include <cmath>
#include <iostream>

#include "../headers/Runner.h"
#include "../headers/Commands.h"

const int MULTIPL = 1000;

Runner::Runner(const char* fileName) :
        _codePointer(0)
{
    Text buf(fileName);
    _bytecode = (char*)calloc(buf.Size(), sizeof(char));
    buf.CopyText(&_bytecode);
    _codesize = buf.Size() - 1;
}

Runner::~Runner()
{
    free(_bytecode);
}

void Runner::Run()
{
    uint8_t command;
    while (_codePointer < _codesize)
    {
        command = (uint8_t)_bytecode[_codePointer];
        _codePointer++;
        #define EXECUTE(CODE, ACTIONS) \
            case CODE: \
                ACTIONS \
                break;


        switch (command)
        {
            #include "../headers/Instructions.hpp"

            default:
                continue;
        }
    }
}

void Runner::ArgFromByteCode()
{
    firstArg = 0;
    for (int i = 0; i < 4; ++i)
    {
        char c = _bytecode[_codePointer];
        firstArg = (firstArg << 8) | (uint8_t)c;
        _codePointer++;
    }
    firstArg *= MULTIPL;
}


void Runner::OneArgumentFromStack()
{
    firstArg = _stack.top();
    _stack.pop();
}

void Runner::TwoArgumentsFromStack()
{
    firstArg = _stack.top();
    _stack.pop();
    secondArg = _stack.top();
    _stack.pop();
}