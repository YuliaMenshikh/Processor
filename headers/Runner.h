#pragma once

#include <cstddef>
#include <cinttypes>
#include <stack>

#include "Text.h"
#include "Commands.h"


/*!
 * Class which run all commands from bytecode.
 */
class Runner
{
public:
    /*!
     * Constructor - read bytecode.
     * @param fileName - name of the file with bytecode.
     */
    Runner(const char* fileName);

    /*!
     * Destructor - free _bytecode.
     */
    ~Runner();

    /*!
     * Run all commands from bytecode.
     */
    void Run();

private:
    std::stack<int32_t> _stack;
    char* _bytecode;
    size_t _codesize;
    size_t _codePointer;

    int32_t firstArg;
    int32_t secondArg;

    bool eqFlag;
    bool grFlag;

    int32_t registr[CNT_REGISTRES];

    /*!
     * Read one argument from bytecode.
     */
    void ArgFromByteCode();

    /*!
     * Get two arguments from the stack.
     */
    void TwoArgumentsFromStack();
    /*!
     * Get one argument from the stack.
     */
    void OneArgumentFromStack();



};