#include "ConvertedFile.hpp"

size_t ConvertedFile::numberOfLines(std::ifstream& file) {

    size_t counter = 0;

    while(!file.eof()) {

        char neshto;

        file.get(neshto);

        if(neshto == '\n') {

            counter++;

        }

    }

    file.clear();

    file.seekg(0, std::ios::beg);

    return counter;

}

vector<string> getLines(std::ifstream& file, size_t counter) {

    vector<string> lines;
    
    char neshto;
    
    lines.resize(counter);

    for(size_t i = 0; i < counter; i++) {

        while(!file.eof() && neshto != '\n') {
            
            file.get(neshto);
     
            lines[i].push_back(neshto);
        
        }
        
    }
    
    file.clear();

    file.seekg(0, std::ios::beg);

    return lines;

}

void ConvertedFile::setType(string line) {

    if(line.front() != 'P') throw "ERROR! Wrong file type, should start with P!";

    if(line.size() != 2) throw "ERROR! Wrong file type, they have to be P + 1 through 6!";

    if((int)line.at(1) < 49 || (int)line.at(1) > 54) throw "ERROR! Wrong file type, file types can be between 1 and 6!";

    this->type = (size_t)line.at(1) - 48;

}

void ConvertedFile::setDescription(string line, bool withDescription) {

    if(withDescription == true) this->description = line;

}

void ConvertedFile::setWidthAndHeight(vector<string> lines, bool withDescription) {

    size_t pos;
    
    if(withDescription == false) pos = 1;
    else pos = 2;

    size_t spaceCounter = 0;
    size_t stopper;
    
    for(size_t i = 0; i < lines[pos].size(); i++) {

        if((size_t)lines[pos].at(i) < 48 || (size_t)lines[pos].at(i) > 57) {

            if((size_t)lines[pos].at(i) == 32) {

                spaceCounter++;

                stopper = i;

                continue;

            }

            throw "ERROR! Here should be inputted width and height, only numbers!";

            break;

        }

    }

    if(spaceCounter != 1) throw "ERROR! We need exactly two numbers and one space!";

    if((size_t)lines[pos].front() == 48) throw "ERROR! First number cannot start with a 0!";

    for(size_t i = stopper - 1; i >= 0; i--) {

        this->width += pow(10, stopper - i) * ((size_t)lines[pos].at(i) - 48);

    }

    if((size_t)lines[pos].at(stopper + 1) == 48) throw "ERROR! Second number cannot start with a 0!";

    for(size_t i = lines[pos].size(); i > stopper; i--) {

        this->height += pow(10, lines[pos].size() - i + 1) * ((size_t)lines[pos].at(i) - 48);

    }

}

void ConvertedFile::setMaxValue(vector<string> lines, bool withDescription) {

    size_t pos;

    if(withDescription == false) pos = 2;
    else pos = 3;

    if((size_t)lines[pos].front() == 48) throw "ERROR! Number cannot start with a 0!";

    if(this->type == 1 || this->type == 4) {
        
        for(size_t i = 0; i < lines[pos].size(); i++) {

            if((size_t)lines[pos].at(i) < 48 || (size_t)lines[pos].at(i) > 57) throw "ERROR! This type of files doesn't have an option to set a maximum value!";

        }

        this->max_value = 1;
    
    }else {

        for(size_t i = 0; i < lines[pos].size(); i++) {

            if((size_t)lines[pos].at(i) < 48 || (size_t)lines[pos].at(i) > 57) throw "ERROR! Only write one number for maximum value!";
            
        }

        for(size_t i = lines[pos].size(); i >= 0; i--) {

            this->max_value += pow(10, i + 1) * ((size_t)lines[pos].at(i) - 48);

        }

        if(this->type == 3 || this->type == 6) {

            

        }

    }

}

void ConvertedFile::setGrid(vector<string> lines, size_t counter, bool withDescription) {}

/// ?????????????????????????????????????????????????????????????????????????????????????????
ConvertedFile::ConvertedFile() 
    : type(0), description(""), width(0), height(0), max_value(0), grid(0, vector<size_t>(0)) {}

bool ConvertedFile::isItWithDescription(string line) {

    if(line.front() == '#') return true;
    else return false;

}

void ConvertedFile::setAll(vector<string> lines, size_t counter) {

    this->setType(lines[0]);

    this->setDescription(lines[1], isItWithDescription(lines[1]));
    
    this->setWidthAndHeight(lines, isItWithDescription(lines[1]));

    this->setMaxValue(lines, isItWithDescription(lines[1]));
    
    this->setGrid(lines, counter, isItWithDescription(lines[1]));

}

void ConvertedFile::getInfo(std::ifstream& file) {

    if(!file.is_open()) throw "ERROR! Problem with opening file!";
    
    size_t counter = this->numberOfLines(file);

    // std::cout << counter << std::endl;

    vector<string> lines = this->getLines(file, counter);

    // for(size_t i = 0; i < lines.size(); i++)
    //     std::cout << lines[i] << std::endl;

    setAll(lines, counter);

}

void ConvertedFile::printInfo() const { std::cout << this->description << std::endl; }