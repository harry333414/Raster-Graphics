#include "RGB.hpp"

void RGB::checkInput(size_t color, size_t input) {

    if(input < 0 || input > this->MAX_VALUE) throw "ERROR! RGB colors take between 0 and 255!";

    color = input;

}

RGB::RGB() 
    : red(0), green(0), blue(0) {}

RGB::RGB(size_t red, size_t green, size_t blue) 
    : RGB() {

        this->checkInput(this->red, red);

        this->checkInput(this->green, green);

        this->checkInput(this->blue, blue);

    }

size_t RGB::getRed() const { return this->red; }

size_t RGB::getGreen() const { return this->green; }

size_t RGB::getBlue() const { return this->blue; }