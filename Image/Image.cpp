#include "Image.hpp"

#include <fstream>

using std::cout;
using std::ofstream;

Image::Image()
    : type(Type::DEF), description(0), resolution(0, 0), max_value(1), grid(resolution, 0) { setMaxValue(max_value); }

Image::Image(Type type, string description, size_t width, size_t height, size_t max_value)
    : type(type), description(description), resolution(width, height), max_value(1), grid(resolution, 0) { setMaxValue(max_value); }

Image::Image(Type type, vector<string> description, size_t width, size_t height, size_t max_value)
    : type(type), description(description), resolution(width, height), max_value(1), grid(resolution, 0) { setMaxValue(max_value); }

bool Image::operator == (const Image& other) {

    if(this->type == other.type && this->description == other.description && this->resolution == other.resolution && this->max_value == other.max_value && this->grid == other.grid) return true;
    else return false;

}

Type Image::getType() const { return this->type; }

Description Image::getDescription() const { return this->description; }

Point Image::getResolution() const { return this->resolution; }

size_t Image::getMaxValue() const { return this->max_value; }

Grid Image::getGrid() const { return this->grid; }

void Image::setMaxValue(size_t max_value) { 
    
    if(max_value > this->MAX_MAX_VALUE) throw "ERROR! Max value exceeds the maximum possible for these types of files!";

    this->max_value = max_value; 
        
}

void Image::print() const {

    cout << typeWriteType(type);

    if(this->description.with_description() == true) this->description.print();

    this->resolution.print();

    cout << this->max_value << '\n';

    this->grid.print();

}


void Image::writeTo(const string& name) {

    string fileName(name);
    fileName += typeGetExtension(type);

    ofstream file(fileName);

    file << typeWriteType(type);
    
    if(this->description.with_description() == true) file << this->description.toString();
    
    file << this->resolution.toString() << this->max_value << '\n' << this->grid.toString();

    file.close();

}

int main() {

    Description desc(3);

    desc[0] = "Hello there!";
    desc[1] = "#How you doing?";
    desc[2] = "Its ya boi!";
    
    Image image(Type::PBM, desc.getDescription(), 3, 4, 2);

    image.writeTo("test");

    return 0;

}