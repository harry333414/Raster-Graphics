#include "Grid_RGB.hpp"

Grid::Grid()
    : grid(0, RGB()), resolution(0, 0) {}

Grid::Grid(size_t width, size_t height)
    : grid(width * height, RGB()), resolution(width, height) {}

Grid::Grid(Point resolution)
    : grid(resolution.getHeight() * resolution.getWidth(), RGB()), resolution(resolution) {}

Grid::Grid(vector<RGB> rgb_grid)
    : grid(rgb_grid) /* resolution??? */ {}

Grid::Grid(const Grid& other)
    : grid(other.getGrid()), resolution(other.getWidth(), other.getHeight()) {}

bool Grid::isItGrayscalePixel(RGB pixel) const {

    if(pixel.getRed() == pixel.getGreen() && pixel.getRed() == pixel.getBlue()) return true;
    else return false;

}

RGB& Grid::operator [] (size_t index) {

    if(index < 0 && index > this->grid.size() - 1) throw std::out_of_range("ERROR! Grid cannot be accessed at such positions!");

    return this->grid[index];

}

const RGB& Grid::operator [] (size_t index) const {

    if(index < 0 && index > this->grid.size() - 1) throw std::out_of_range("ERROR! Grid cannot be accessed at such positions!");

    return this->grid[index];

}

Grid& Grid::operator = (const Grid& other) {

    if(this != &other) {

        this->grid = other.grid;

        this->resolution = other.resolution;

    }

    return *this;

}

bool Grid::operator == (const Grid& other) {

    if(this->grid.size() != other.grid.size()) return false;

    for(size_t i = 0; i < this->grid.size(); i++) {

        if(this->grid[i] != other.grid[i]) return false;
    
    }

    return true;

}

vector<RGB> Grid::getGrid() const { return this->grid; }
        
size_t Grid::getWidth() const { return this->resolution.getWidth(); }

size_t Grid::getHeight() const { return this->resolution.getHeight(); }

size_t Grid::getMaxValue() const { return this->max_value; }

bool Grid::isItGrayscaleGrid() const { return this->grayscale; }

bool Grid::isItMonochromeGrid() const { return this->monochrome; }

bool Grid::isItGrayscaleAndPPMGrid() const {

    if(this->monochrome) return false;
    else if(this->grayscale) return false;
    else {

        for(size_t i = 0; i < this->grid.size(); i++) {

            if(!this->isItGrayscalePixel(this->grid[i])) return false;

        }

        return true;

    }

}

void Grid::setGridAt(size_t index, size_t red, size_t green, size_t blue) {
    
    RGB temp(red, green, blue);

    this->grid.push_back(temp);

}

void Grid::setGrayscaleGridAt(size_t index, size_t grayscale) {

    RGB temp(grayscale, grayscale, grayscale);

    this->grid.push_back(temp);

}

void Grid::setGrayscaleBool(bool grayscale) { this->grayscale = grayscale; }
        
void Grid::setMonochromeBool(bool monochrome) { this->monochrome = monochrome; }

void Grid::setResolution(size_t width, size_t height) {

    this->resolution.setWidth(width);
    
    this->resolution.setHeight(height);

}

void Grid::setMaxValue(size_t max_value) { this->max_value = max_value; }

RGB Grid::getGridAt(size_t width, size_t height) const {

    if(width < 0 || width > this->resolution.getWidth()) throw std::out_of_range("ERROR! No such pixel, out of bounds!");
    if(height < 0 || height > this->resolution.getHeight()) throw std::out_of_range("ERROR! No such pixel, out of bounds!");
    
    return this->grid[width + height];

}

RGB Grid::getPixelAt(size_t index) const {

    if(index < 0 || index > this->grid.size()) throw std::out_of_range("ERROR! Grid does not have such values because there are not that many pixels!");

    return this->grid[index];

}

void Grid::setPixelAt(size_t index, RGB pixel) {

    if(index < 0 || index > this->grid.size()) throw std::out_of_range("ERROR! Grid does not have such values because there are not that many pixels!");

    this->grid[index].setRed(pixel.getRed());
    this->grid[index].setGreen(pixel.getGreen());
    this->grid[index].setBlue(pixel.getBlue());

}

void Grid::convertToGrayscale() {

    if(this->grayscale) throw std::invalid_argument("ERROR! Grid is already into grayscale type!");

    this->grayscale = true ;

    for(size_t i = 0; i < this->grid.size(); i++) {

        this->grid[i].setRed((size_t) (0.299 * this->grid[i].getRed() + 0.587 * this->grid[i].getGreen() + 0.114 * this->grid[i].getBlue()));

        this->grid[i].setGreen(this->grid[i].getRed());

        this->grid[i].setBlue(this->grid[i].getRed());

    }

}

void Grid::convertToMonochrome() {

    if(this->monochrome) throw std::invalid_argument("ERROR! Image is already into monochrome type!");

    this->monochrome = true;

    for(size_t i = 0; i < this->grid.size(); i++) {

        if((size_t) (0.299 * this->grid[i].getRed() + 0.587 * this->grid[i].getGreen() + 0.114 * this->grid[i].getBlue()) > 128) {

            this->grid[i].setRed(1);

            this->grid[i].setGreen(1);

            this->grid[i].setBlue(1);
        
        }else {

            this->grid[i].setRed(0);

            this->grid[i].setGreen(0);

            this->grid[i].setBlue(0);
            
        }

    }

}

void Grid::convertToNegative() {

    for(size_t i = 0; i < this->grid.size(); i++) {

        this->grid[i].setRed(this->max_value - this->grid[i].getRed());
        
        this->grid[i].setGreen(this->max_value - this->grid[i].getGreen());
        
        this->grid[i].setBlue(this->max_value - this->grid[i].getBlue());
    
    }

}

const string Grid::toString() const {

    string gridString;

    if(!this->grayscale) {
    
        for(size_t i = 0; i < this->grid.size(); i++) {

            gridString += std::to_string(this->grid[i].getRed());
            gridString.push_back(' ');
            gridString += std::to_string(this->grid[i].getGreen());
            gridString.push_back(' ');
            gridString += std::to_string(this->grid[i].getBlue());
            
            gridString.push_back('\n');

        }
    
    }else {

        for(size_t i = 0; i < this->grid.size(); i++) {

            gridString += std::to_string(this->grid[i].getRed());
             
            if((i + 1) % this->resolution.getWidth() == 0) gridString.push_back('\n');
            else gridString.push_back(' ');

        }

    }

    gridString.pop_back();

    return gridString;

}

void Grid::print() const {

    if(!this->grayscale) {

        for(size_t i = 0; i < this->grid.size(); i++) {

            cout << this->grid[i].getRed() << ' ' << this->grid[i].getGreen() << ' ' << this->grid[i].getBlue() << '\n';

        }
    
    }else {


        for(size_t i = 0; i < this->grid.size(); i++) {

            cout << this->grid[i].getRed();
            
            if((i + 1) % this->resolution.getWidth() == 0) std::cout << '\n';
            else std::cout << ' ';
        
        }

    }

}