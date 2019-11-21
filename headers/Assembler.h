#pragma once

#include <map>

#include "Text.h"

/*!
 * Class which converts a sequence of commands into bytecode.
 */
class Assembler
{
public:
    /*!
     * Constructer in which the source text is read.
     * @param fileName - source file name with sequence of commands.
     */
    Assembler(const char* fileName);

    /*!
     * Convert source to bytecode.
     * @param fileOut - destination file with bytecode.
     */
    void assemble(const char* fileOut);
private:
    //! source text
    Text _buffer;

    //! labels -> address
    std::map<std::string, uint32_t> labels;

    /*!
     * Preprocess text (to use labels).
     */
    void preprocess();
};