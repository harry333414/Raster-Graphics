#include "ConvertedFile.hpp"

int main() {

    std::ifstream file("test.pbm");

    ConvertedFile convert;

    convert.getInfo(file);

    // convert.printInfo();

    return 0;

}