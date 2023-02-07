#include <iostream>

#include "SimiVMStack.cpp"
#include "SimiVMRegister.cpp"
#include "SimiParser.cpp"

void print(SimiVMStack& vm) {
    while (vm.peek() != 0)
    {
        std::cout << (char) vm.peek();
        vm.pop();
    }
}

int main(const int argc, const char* argv[]) {
    SimiVMRegister vm(128);

    vm.mov(EA, 2);
    vm.mov(EB, 3);

    vm.add(EA, EB);


}
