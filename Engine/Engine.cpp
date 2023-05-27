#include "Engine.hpp"

size_t Engine::session = 1;

Engine::Engine()
    : line(), ui() { this->session++; }

void Engine::start() {

    std::cout << "Welcome to Basic Raster Graphics app by harry333414\n";
    std::cout << "Here are the possible things that you can write: \n";
    std::cout << "load - lets you load a session\n";
    std::cout << "save - lets you save your first inputted picture back to the original file\n";
    std::cout << "save as - lets you save your first inputted picture to a new file\n";
    std::cout << "help - loads this information\n";
    std::cout << "switch - lets you switch sessions\n";
    std::cout << "undo - lets you come back one step\n";
    std::cout << "exit - ends the program\n";
    

}