#include "RGB.hpp"

// void RGB::checkInput(size_t color, size_t input) {

//     if(input < 0 || input > this->MAX_VALUE) throw "ERROR! RGB colors take between 0 and 255!";

//     color = input;

// }

RGB::RGB() 
    : red(0), green(0), blue(0) {}

RGB::RGB(size_t red, size_t green, size_t blue) 
    : red(red), green(green), blue(blue) {}

bool RGB::operator != (const RGB& other) {

    if(this->red == other.red && this->blue == other.blue && this->green == other.green) return true;
    else return false;

}

size_t RGB::getRed() const { return this->red; }

size_t RGB::getGreen() const { return this->green; }

size_t RGB::getBlue() const { return this->blue; }

void RGB::setRed(size_t color) { this->red = color; }

void RGB::setGreen(size_t color) { this->green = color; }

void RGB::setBlue(size_t color) { this->blue = color; }