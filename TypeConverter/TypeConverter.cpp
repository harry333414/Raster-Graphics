#include "TypeConverter.hpp"

TypeConverter::TypeConverter()
    : type(Type::DEF) {}

TypeConverter::TypeConverter(Type type)
    : type(type) {}

const Type& TypeConverter::getType() const { return this->type; }

void TypeConverter::setType(Type type) { this->type = type; }

const string TypeConverter::typeWriteType() const {

    switch (this->type) {
    
        case Type::PBM : return "P1\n"; break;
        case Type::PGM : return "P2\n"; break;
        case Type::PPM : return "P3\n"; break;
        case Type::PBM_B : return "P4\n"; break;
        case Type::PGM_B : return "P5\n"; break;
        case Type::PPM_B : return "P6\n"; break;
        default: return "No type!\n"; break;
    
    }

}

const string TypeConverter::typeGetExtension() const {

    switch (this->type) {
    
        case Type::PBM : return ".pbm"; break;    
        case Type::PGM : return ".pgm"; break;    
        case Type::PPM : return ".ppm"; break;    
        case Type::PBM_B : return ".pbm"; break;    
        case Type::PGM_B : return ".pgm"; break;    
        case Type::PPM_B : return ".ppm"; break;    
        default: return ".txt"; break;
    
    }

}