#include <mcpelauncher/linker.h>
#include "symbols.h"
//#include "armhfrewrite.h"
//#include <functional>

//void (*Mouse::feed)(char, char, short, short, short, short);
void (*Mouse::feed)(char, signed char, short, short, short, short);

int *Keyboard::_states;
std::vector<Keyboard::InputEvent> *Keyboard::_inputs;
int *Keyboard::_gameControllerId;

void SymbolsHelper::initSymbols(void *handle) {
//    Mouse::feed = (void (*)(char, char, short, short, short, short)) linker::dlsym(handle, "_ZN5Mouse4feedEccssss");
    Mouse::feed = (void (*)(char, signed char, short, short, short, short)) linker::dlsym(handle, "_ZN5Mouse4feedEccssss");
//    Mouse::feed = ARMHFREWRITE((void (*)(char, char, short, short, short, short)) linker::dlsym(handle, "_ZN5Mouse4feedEccssss"));
//void *func = ARMHFREWRITE((*)linker::dlsym(handle, "_ZN5Mouse4feedEccssss"));

    Keyboard::_states = (int *) linker::dlsym(handle, "_ZN8Keyboard7_statesE");
    Keyboard::_inputs = (std::vector<Keyboard::InputEvent> *) linker::dlsym(handle, "_ZN8Keyboard7_inputsE");
    Keyboard::_gameControllerId = (int *) linker::dlsym(handle, "_ZN8Keyboard17_gameControllerIdE");
}
