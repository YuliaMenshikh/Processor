EXECUTE(END, {
    _codePointer++;
    return;
})

EXECUTE(IN, {
    ArgFromByteCode();
    scanf("%" SCNd32, &secondArg);
    registr[firstArg / MULTIPL] = secondArg * MULTIPL;
})

EXECUTE(OUTTOP, {
    OneArgumentFromStack();
    std::cout << firstArg / MULTIPL;// << firstArg % MULTIPL << '\n';
    if (firstArg % MULTIPL)
        std::cout << ',' << firstArg % MULTIPL;
    std::cout << '\n';
})

EXECUTE(PUSH, {
    ArgFromByteCode();
    _stack.push(firstArg);
})

EXECUTE(PUSHR, {
    ArgFromByteCode();
    _stack.push(registr[firstArg / MULTIPL]);
})

EXECUTE(POP, {
    _stack.pop();
})

EXECUTE(POPR, {
    ArgFromByteCode();
    registr[firstArg / MULTIPL] = _stack.top();
    _stack.pop();
})

EXECUTE(CMP, {
    TwoArgumentsFromStack();
    _stack.push(secondArg);
    _stack.push(firstArg);
    eqFlag = (firstArg == secondArg);
    grFlag = (firstArg > secondArg);
})

EXECUTE(ADD,{
    TwoArgumentsFromStack();
    _stack.push(firstArg + secondArg);

})

EXECUTE(SUB,{
    TwoArgumentsFromStack();
    _stack.push(firstArg - secondArg);
})

EXECUTE(MUL,{
    TwoArgumentsFromStack();
    _stack.push(firstArg * secondArg / MULTIPL);
})

EXECUTE(DIV,{
    TwoArgumentsFromStack();
    _stack.push(firstArg * MULTIPL / secondArg);
})

EXECUTE(MOD,{
    TwoArgumentsFromStack();
    _stack.push((firstArg % secondArg) * MULTIPL);
})

EXECUTE(SQRT,{
    TwoArgumentsFromStack();
    _stack.push(std::sqrt(firstArg * MULTIPL));
})

EXECUTE(JMP,{
    ArgFromByteCode();
    _codePointer = firstArg / MULTIPL;
})

EXECUTE(JL,{
    ArgFromByteCode();
    if (!grFlag && !eqFlag)
    _codePointer = firstArg / MULTIPL;
})

EXECUTE(JLE,{
    ArgFromByteCode();
    if (!grFlag || eqFlag)
    _codePointer = firstArg / MULTIPL;
})

EXECUTE(JB,{
    ArgFromByteCode();
    if (grFlag && !eqFlag)
    _codePointer = firstArg / MULTIPL;
})

EXECUTE(JBE,{
    ArgFromByteCode();
    if (grFlag || eqFlag)
    _codePointer = firstArg / MULTIPL;
})

EXECUTE(JE,{
    ArgFromByteCode();
    if (eqFlag)
    _codePointer = firstArg / MULTIPL;
})

EXECUTE(JNE,{
    ArgFromByteCode();
    if (!eqFlag)
    _codePointer = firstArg / MULTIPL;
})