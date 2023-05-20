#pragma once

#include <string>

using std::string;

enum class Type {

    DEF = 0,
    PBM,
    PGM,
    PPM,
    PBM_B,
    PGM_B,
    PPM_B

};

const string typeWriteType(Type type) {

    switch (type) {
    
        case Type::PBM : return "P1\n"; break;
        case Type::PGM : return "P2\n"; break;
        case Type::PPM : return "P3\n"; break;
        case Type::PBM_B : return "P4\n"; break;
        case Type::PGM_B : return "P5\n"; break;
        case Type::PPM_B : return "P6\n"; break;
        default: return "No type!\n"; break;
    
    }

}

const string typeGetExtension(Type type) {

    switch (type) {
    
        case Type::PBM : return ".pbm"; break;    
        case Type::PGM : return ".pgm"; break;    
        case Type::PPM : return ".ppm"; break;    
        case Type::PBM_B : return ".pbm"; break;    
        case Type::PGM_B : return ".pgm"; break;    
        case Type::PPM_B : return ".ppm"; break;    
        default: return ".txt"; break;
    
    }

}