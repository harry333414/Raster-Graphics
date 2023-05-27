#pragma once

#include <iostream>

using std::size_t;

class RGB {

    private:

        static const size_t MAX_VALUE = 255;

        size_t red;
        size_t green;
        size_t blue;

        // void checkInput(size_t color, size_t input);

    public:

        RGB();
        RGB(size_t red, size_t green, size_t blue);

        size_t getRed() const;
        size_t getGreen() const;
        size_t getBlue() const;
        
        void setRed(size_t color);
        void setGreen(size_t color);
        void setBlue(size_t color);

        bool operator != (const RGB& other);

        ~RGB() = default;

};