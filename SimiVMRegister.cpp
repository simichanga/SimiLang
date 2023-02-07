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
    SimiVMRegister(const int memorySize) : SIZE(memorySize), data(new int[SIZE]) {}
    ~SimiVMRegister() { delete data; }

    void mov(const Registers leftRegister, const int rightInt) {
        data[leftRegister] = rightInt;

        if (leftRegister == ZX)
            handleInstruction(rightInt);
    }

    void mov(const Registers left, const Registers right) {
        data[left] = data[right];
    }

    void mov(const Registers left, const char* inputString) {
        mov(EA, loadString(inputString));
    }

    void add(const Registers leftRegister, const int rightInt) {
        data[leftRegister] += rightInt;
    }

    void add(const Registers left, const Registers right) {
        data[left] += data[right];
    }

    // Debug
    void superPrint() {
        for (int i = 0; i < 20; i++)
            std::cout << data[i] << std::endl;
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

    enum Instructions {
        NONE,
        PRINT_INT,
        PRINT_STR,
    };

    void handleOperation(const Operations operation, const Registers left, const Registers right) {
        if (operation == ADD)
            data[left] += data[right];
        if (operation == SUB)
            data[left] -= data[right];
        if (operation == MULT)
            data[left] *= data[right];
        if (operation == DIV)
            data[left] /= data[right];
    }

    void handleInstruction(const int instructionCode) {
        // Print
        switch (instructionCode) {
            case PRINT_INT:
                printRegInt();
                break;
            case PRINT_STR:
                printRegString();
                break;
            default:
                throw EXIT_FAILURE;
        }
    }

    // Returns size of string to put in respective EA or EB register
    int loadString(const char* inputString) {
        int inputSize;

        for (inputSize = 0; inputString[inputSize] != '\0'; inputSize++)
            data[BEGIN + inputSize] = inputString[inputSize];

        return inputSize;
    }

    void printRegInt() {
        for (int i = BEGIN; i < BEGIN + data[EA]; i++)
            std::cout << data[i];
    }

    void printRegString() {
        for (int i = BEGIN; i < BEGIN + data[EA]; i++)
            std::cout << (char) data[i];
    }
};