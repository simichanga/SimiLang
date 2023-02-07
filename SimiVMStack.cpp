//
// Created by simi on 31.01.2023.
//
#pragma once

class SimiVMStack {
public:
    SimiVMStack(int memorySize) : memoryStack(new int[memorySize]{0}) {}

    void push(int value) {
        memoryStack[++indexPointer] = value;
    }

    int pop() {
        if (indexPointer == 0) return 0;

        return memoryStack[indexPointer--];
    }

    int peek() {
        return memoryStack[indexPointer];
    }

    void add() {
        handleOperation(ADD);
    }

    void sub() {
        handleOperation(SUB);
    }

    void mult() {
        handleOperation(MULT);
    }

    void div() {
        handleOperation(DIV);
    }

private:
    int* memoryStack = nullptr;
    int indexPointer = 0;

    enum Operations {
        ADD,
        SUB,
        MULT,
        DIV,
    };

    // Helper methods
    void handleOperation(Operations operation) {
        if (indexPointer == 0) return;

        if (operation == ADD)
            memoryStack[indexPointer - 1] += memoryStack[indexPointer];
        if (operation == SUB)
            memoryStack[indexPointer - 1] -= memoryStack[indexPointer];
        if (operation == MULT)
            memoryStack[indexPointer - 1] *= memoryStack[indexPointer];
        if (operation == DIV)
            memoryStack[indexPointer - 1] /= memoryStack[indexPointer];

        memoryStack[indexPointer--] = 0;
    }
};