#include <iostream>

#include "SimiVMStack.cpp"
#include "SimiVMRegister.cpp"
#include "SimiParser.cpp"

int main(const int argc, const char* argv[]) {
    SimiVMRegister vm(128);

    vm.mov(EAX, "Hello World!");
    vm.mov(ZX, 2);
}
