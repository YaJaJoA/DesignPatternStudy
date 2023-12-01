#include "InputController.h"

// static member variable
InputController* InputController::_instance;

char InputController::MainKeyboardLoop(){
    std::string str;
    std::getline(std::cin, str);
    std::wcout << "\033[A" << "                                     " << "\r"; //clear input line
    
    wchar_t keyboardInput = str[0];

    switch(keyboardInput){
        case 'w':
            //Move Up
            break;
        case 'a':
            //Move Left
            break;
        case 's':
            //Move Down
            break;
        case 'd':
            //Move Right
            break;
        default:
            break;
    }
    return keyboardInput;
}

InputController* InputController::GetInstance(){
    if (_instance == nullptr)
        _instance = new InputController();
    return _instance;
}
