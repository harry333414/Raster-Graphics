#pragma once

#include "../UI/UserInterface.hpp"

class Engine {

    private:

        static size_t session;

        UserInterface ui;
        string line;

    public:

        Engine();

        void start();

        ~Engine() = default;

};