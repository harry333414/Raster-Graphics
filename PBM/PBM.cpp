#include "PBM.hpp"

PBM::PBM()
    : Image() {}

PBM::PBM(Type type, size_t width, size_t height)
    : Image(type, width, height, MAX_VALUE) {}

PBM::PBM(Type type, string description, size_t width, size_t height)
    : Image(type, description, width, height, MAX_VALUE) {}

PBM::PBM(Type type, vector<string> description, size_t width, size_t height)
    : Image(type, description, width, height, MAX_VALUE) {}