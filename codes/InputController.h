#ifndef D8618E35_1ECC_4046_BD6A_AC7F4072817E
#define D8618E35_1ECC_4046_BD6A_AC7F4072817E

#include <iostream>
#include <string>

class InputController{ 
    // singletone
    // Control user input via console
    public:
    InputController() {};
    char MainKeyboardLoop();
    static InputController* GetInstance();

    protected:
    static InputController* _instance;
};

#endif /* D8618E35_1ECC_4046_BD6A_AC7F4072817E */
