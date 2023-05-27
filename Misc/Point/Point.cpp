#include "Point.hpp"

using std::cout;

Point::Point()
    : width(0), height(0) {}

Point::Point(size_t width, size_t height)
    : width(width), height(height) {}

bool Point::operator == (const Point& other) {

    if(this->width == other.width && this->height == other.height) return true;
    else return false;

}

bool Point::operator != (const Point& other) {

    if(this->width != other.width || this->height != other.height) return true;
    else return false;

}

size_t Point::getWidth() const { return this->width; }

size_t Point::getHeight() const { return this->height; }

void Point::setWidth(size_t width) { this->width = width; }

void Point::setHeight(size_t height) { this->height = height; }

const string Point::toString() const {

    string resolution;

    resolution += std::to_string(this->width);
    resolution.push_back(' ');
    resolution += std::to_string(this->height);
    resolution.push_back('\n');

    return resolution;

}

void Point::print() const { cout << this->width << ' ' << this->height << '\n'; }