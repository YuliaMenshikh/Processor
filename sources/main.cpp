#include <iostream>
#include "headers/Assembler.h"
#include "headers/Runner.h"

int main() {
    /*Assembler trans("equation.txt");
    trans.assemble("bytecode_equation.txt");*/

    Runner run("bytecode_equation.txt");
    run.Run();
    return 0;
}