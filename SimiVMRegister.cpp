#include <iostream>

enum Registers {
    EA,     // Normal register
    EB,     //
    EAX,    // Pointer register
    EBX,    //
    ZX,     // Instruction register
    ZY,     // Parameter of instruction register
    BEGIN   // First index of free memory
};

class SimiVMRegister {
public:
    SimiVMRegister(int memorySize) : SIZE(memorySize), data(new int[SIZE]) {}
    ~SimiVMRegister() { delete data; }

    void mov(Registers leftRegister, int rightInt) {
        data[leftRegister] = rightInt;

        if (leftRegister == ZX)
            handleInstruction(rightInt);
    }

    void mov(Registers left, Registers right) {
        data[left] = data[right];
    }

    void add(Registers leftRegister, int rightInt) {
        data[leftRegister] += rightInt;
    }

    void add(Registers left, Registers right) {
        data[left] += data[right];
    }

private:
    int* data = nullptr;
    int SIZE = 0;

    enum Operations {
        ADD,
        SUB,
        MULT,
        DIV,
    };

    void handleOperation(Operations operation, Registers left, Registers right) {
        if (operation == ADD)
            data[left] += data[right];
        if (operation == SUB)
            data[left] -= data[right];
        if (operation == MULT)
            data[left] *= data[right];
        if (operation == DIV)
            data[left] /= data[right];
    }

    void handleInstruction(int instructionCode) {
        // Read into
        /*
        if (instructionCode == 1)
            for ()
            */
    }

    // Returns size of string
    int loadString(const char* inputString) {
        int inputSize;

        for (inputSize = 0; inputString[inputSize] != '\0'; inputSize++)
            data[BEGIN + inputSize] = inputString[inputSize];

        return inputSize;
    }
};