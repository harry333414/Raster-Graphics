#include "PPM.hpp"

PPM::PPM() 
    : Image(), rgb_grid(0, RGB()) {}

PPM::PPM(Type type, size_t width, size_t height, size_t max_value)
    : Image(type, width, height, max_value), rgb_grid(this->resolution.getWidth() * this->resolution.getHeight(), RGB()) {}

PPM::PPM(Type type, string description, size_t width, size_t height, size_t max_value)
    : Image(type, description, width, height, max_value), rgb_grid(this->resolution.getWidth() * this->resolution.getHeight(), RGB()) {}
    
PPM::PPM(Type type, vector<string> description, size_t width, size_t height, size_t max_value)
    : Image(type, description, width, height, max_value), rgb_grid(this->resolution.getWidth() * this->resolution.getHeight(), RGB()) {}