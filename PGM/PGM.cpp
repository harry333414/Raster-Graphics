#include "PGM.hpp"

PGM::PGM()
    : Image() {}

PGM::PGM(Type type, size_t width, size_t height, size_t max_value)
    : Image(type, width, height, max_value) {}

PGM::PGM(Type type, string description, size_t width, size_t height, size_t max_value)
    : Image(type, description, width, height, max_value) {}

PGM::PGM(Type type, vector<string> description, size_t width, size_t height, size_t max_value)
    : Image(type, description, width, height, max_value) {}