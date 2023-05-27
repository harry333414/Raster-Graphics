#include "Image.hpp"


#include <fstream>

using std::cout;
using std::ofstream;

void Image::copy(const Image& other) {

    setType(other.getType());

    setDescription(other.getDescription());

    setResolution(other.getResolution().getWidth(), other.getResolution().getHeight());

    setMaxValue(other.getMaxValue());

    setGrid(other.getGrid());

}

void Image::RGBToGrayscale() {

    if(!this->grid.isItGrayscaleGrid() && !this->grid.isItGrayscaleAndPPMGrid()) {

        this->grid.convertToGrayscale();

        this->type = Type::PGM;

    }

}

void Image::GrayscaleToMonochrome() { 
    
    if(!this->grid.isItMonochromeGrid()) {
        
        this->grid.convertToMonochrome(); 
    
        this->type = Type::PBM;
    
    }
    
}

void Image::negative() { this->grid.convertToNegative(); }

Image::Image()
    : type(Type::DEF), typeConverter(this->type), description(0), resolution(0, 0), max_value(1), grid(resolution) { setMaxValue(max_value); }

Image::Image(Type type, string description, size_t width, size_t height, size_t max_value)
    : type(type), typeConverter(this->type), description(description), resolution(width, height), max_value(1), grid(resolution) { setMaxValue(max_value); }

Image::Image(Type type, vector<string> description, size_t width, size_t height, size_t max_value)
    : type(type), typeConverter(this->type), description(description), resolution(width, height), max_value(1), grid(resolution) { setMaxValue(max_value); }

Image::Image(const Image& other) { this->copy(other); }

Image& Image::operator = (const Image& other) {

    if(this != &other) this->copy(other);

    return *this;

}

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
    
    if(max_value > this->MAX_MAX_VALUE) throw std::invalid_argument("ERROR! Max value exceeds the maximum possible for these types of files!");

    this->max_value = max_value; 

    this->grid.setMaxValue(max_value);
        
}

void Image::setType(Type type) {
    
    this->type = type;

    this->typeConverter.setType(type);

}

void Image::setDescription(const Description& description) { this->description = description; }

void Image::setResolution(size_t width, size_t height) {

    this->resolution.setWidth(width);

    this->resolution.setHeight(height);

}

void Image::setGridResolution(size_t width, size_t height) { this->grid.setResolution(width, height); }

void Image::setGridGrayscaleBool(bool grayscale) { this->grid.setGrayscaleBool(grayscale); }

void Image::setGridMonochromeBool(bool monochrome) { this->grid.setMonochromeBool(monochrome); }        

void Image::setGrid(const Grid& grid) { this->grid = grid; }

void Image::addToDescription(const string& line) { this->description.addToDescription(line); }

void Image::addToGrid(const Grid grid) {

    for(size_t i = 0; i < grid.getGrid().size(); i++) this->grid.getGrid().push_back(grid.getGrid()[i]);

}

void Image::setGridAt(size_t index, size_t red, size_t green, size_t blue) {

    // std::cout << index << ";" << red << " " << green << " " << blue << std::endl;

    if(this->grid.isItGrayscaleGrid()) this->grid.setGrayscaleGridAt(index, red);
    else this->grid.setGridAt(index, red, green, blue);

}

void Image::print() const {

    cout << this->typeConverter.typeWriteType();

    if(this->description.with_description() == true) this->description.print();

    this->resolution.print();

    if(this->getType() != Type::PBM && this->getType() != Type::PBM_B) cout << this->max_value << '\n';

    this->grid.print();

}


void Image::writeTo(const string& name) {

    string fileName(name);
    fileName += this->typeConverter.typeGetExtension();

    std::ofstream file(fileName);

    if(!file.is_open()) throw std::invalid_argument("ERROR! Couldn't open the file!");

    file << this->typeConverter.typeWriteType();
    
    if(this->description.with_description() == true) file << this->description.toString();
    
    file << this->resolution.toString();

    if(this->getType() != Type::PBM && this->getType() != Type::PBM_B) file << this->max_value << '\n' ;

    file << this->grid.toString();

    file.close();

}

// int main() {

//     Description desc(3);

//     desc[0] = "Hello there!";
//     desc[1] = "#How you doing?";
//     desc[2] = "Its ya boi!";
    
//     Image image(Type::PBM, desc.getDescription(), 3, 4, 2);

//     image.writeTo("test");

//     return 0;

// }