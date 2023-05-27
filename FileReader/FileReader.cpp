#include "FileReader.hpp"

#include <exception>

size_t FileReader::linesCounter(ifstream& file) {

    size_t counter = 0;
    string line;
    
    while(getline(file, line)) counter++;

    // file.close();

    return counter;

}

vector<string> FileReader::convertToString(ifstream& file) {

    vector<string> lines;
    string line;

    while(getline(file, line)) lines.push_back(line);

    // file.close();

    return lines;

}

void FileReader::setType(Image& image, const string& line) {

    if(line.front() != 'P' ||
      (size_t)line[1] < 49 || (size_t)line[1] > 54 ||
      line.size() > 2)
        throw std::invalid_argument("ERROR! Wrong file type!");

    image.setType((Type)((size_t)line[1] - 48));

    if(image.getType() == Type::PBM || image.getType() == Type::PBM_B) this->max_value_needed = false;

}

void FileReader::addToDescription(Image& image, const string& line) { image.addToDescription(line); }

size_t FileReader::spaceCounterAndExceptionChecker(Image& image, const string& line) {

    size_t spaceCounter = 0;

    if(image.getType() != Type::PBM && image.getType() != Type::PBM_B) {
    if((int)line[0] == 48 && (int)line[1] >= 48 && (int)line[1] <= 57) throw std::invalid_argument("ERROR! Number cannot start with 0!");
    }
    for(size_t i = 0; i < line.size(); i++) {

        if(line[i] == ' ') {

            spaceCounter++;
        
            if((int)line[i + 1] == 48 && (int)line[i + 2] >= 48 && (int)line[i + 2] <= 57) throw std::invalid_argument("ERROR! Number cannot start with 0!");

            continue;

        }
        
        if((size_t)line[i] < 48 || (size_t)line[i] > 57) throw std::invalid_argument("ERROR! Resolution can take only numbers!");

    }

    return spaceCounter;

}

size_t FileReader::stringToNumber(const string& line, size_t start, size_t end) {

    size_t number = 0;

    for(size_t i = start; i < end; i++) number = number * 10 + (line[i] - '0');
    
    return number;

}

void FileReader::setResolution(Image& image, const string& line) {

    size_t spaceCounter = this->spaceCounterAndExceptionChecker(image, line);

    if(line.back() == ' ') spaceCounter--;

    switch (spaceCounter) {
        
        case 1: {
            
            for(size_t i = 0; i < line.size(); i++) {

                if(line[i] == ' ') {

                    if(this->stringToNumber(line, 0, i) <= 0 || this->stringToNumber(line, i + 1, line.size()) <= 0)
                        throw std::invalid_argument("ERROR! Resolution cannot take such values!");

                    image.setResolution(this->stringToNumber(line, 0, i), this->stringToNumber(line, i + 1, line.size()));

                    break;

                }

            }

            break;
        
        }
        
        case 2: {

            this->max_value_needed = false;

            bool resChange = false;
            size_t start;

            size_t width;

            for(size_t i = 0; i < line.size(); i++) {

                if(line[i] == ' ') {

                    if(!resChange) {
                        
                        width = this->stringToNumber(line, 0, i);
                    
                        start = i + 1;

                        resChange = true;

                    }else {

                        image.setResolution(width, this->stringToNumber(line, start, i));

                        image.setMaxValue(this->stringToNumber(line, i + 1, line.size()));

                        break;

                    }

                }

            }

            break;
        
        }
        
        default: {

            throw std::invalid_argument("ERROR! Wrong input on the resolution of the picture!");

            break;
        
        }

    }

}

void FileReader::setMaxSize(Image& image, const string& line) {

    size_t spaceCounter = this->spaceCounterAndExceptionChecker(image, line);

    if(image.getType() == Type::PBM || image.getType() == Type::PBM_B) this->max_value_needed = false;

    bool isItPBM = false;

    if(spaceCounter != 0 && this->max_value_needed) throw std::invalid_argument("ERROR! There is only one maximum value that can be set!");

    size_t max_value = this->stringToNumber(line, 0, line.size()); 
    
    if(image.getType() == Type::DEF) { throw std::invalid_argument("ERROR! File doesn't have a type!"); }
    else if(image.getType() == Type::PBM || image.getType() == Type::PBM_B) { image.setMaxValue(1); }
    else {
    
        if(max_value < 0 || max_value > 255) throw std::invalid_argument("ERROR! File type doesn't support such maximum value!");
        else image.setMaxValue(max_value);
    
    }

}

void FileReader::setGrid(Image& image, const vector<string>& lines) {

    image.setGridResolution(image.getResolution().getWidth(), image.getResolution().getHeight());
    
    size_t counter = 0;

    if(image.getType() == Type::PBM || image.getType() == Type::PBM_B) {

        string line;

        for(size_t i = 0; i < lines.size(); i++) line += lines[i];

        image.setGridGrayscaleBool(true);
        image.setGridMonochromeBool(true);

        for(size_t i = 0; i < line.size(); i++) {

            if(line[i] == '0' || line[i] == '1') {

                size_t grayscale = (size_t)(line[i] - '0');

                image.setGridAt(counter++, grayscale, grayscale, grayscale);              

            }else if(line[i] != ' ') throw std::invalid_argument("ERROR! Grid is written wrongly!");
    
        }
    
    }else if(image.getType() == Type::PGM || image.getType() == Type::PGM_B) {
    
        image.setGridGrayscaleBool(true);

        size_t spaceCounter;

        size_t start;

        for(size_t i = 0; i < lines.size(); i++) {

            spaceCounter = this->spaceCounterAndExceptionChecker(image, lines[i]);
        
            for(size_t j = 0; j < lines[i].size(); j++) {

                if(lines[i][j] == ' ') continue;

                size_t number = lines[i][j] - '0';

                if(number >= 0 && number <= 9) {

                    start = j;

                    while(lines[i][j] - '0' >= 0 && lines[i][j] - '0' <= 9) { j++; }

                    size_t convertedNumber = this->stringToNumber(lines[i], start, j);

                    if(convertedNumber > image.getMaxValue()) throw std::invalid_argument("ERROR! One of the pixels exceeds the maximum value!");

                    image.setGridAt(counter++, convertedNumber, convertedNumber, convertedNumber);

                }else if(lines[i][j] != ' ') throw std::invalid_argument("ERROR! Grid is written wrongly!");

            }

        }

    }else if(image.getType() == Type::PPM || image.getType() == Type::PPM_B) {

        size_t red, green, blue;

        size_t start;

        size_t spaceCounter;
        
        for(size_t i = 0; i < lines.size(); i++) {

            spaceCounter = this->spaceCounterAndExceptionChecker(image, lines[i]);

            for(size_t j = 0; j < lines[i].size(); j++) {

                if(lines[i][j] == ' ') continue;

                size_t number = lines[i][j] - '0';

                if(number >= 0 && number <= 9) {

                    start = j;
                    
                    while(lines[i][j] - '0' >= 0 && lines[i][j] - '0' <= 9) { j++; }

                    size_t convertedNumber = this->stringToNumber(lines[i], start, j);

                    if(convertedNumber > image.getMaxValue()) throw std::invalid_argument("ERROR! One of the pixels exceeds the maximum value!");

                    switch(counter % 3) {

                        case 0: red = convertedNumber; break;
                        case 1: green = convertedNumber; break;
                        case 2: blue = convertedNumber; break;

                    }

                    if(counter % 3 == 2) image.setGridAt(counter, red, green, blue);

                    counter++;
                
                }else if(lines[i][j] != ' ') throw std::invalid_argument("ERROR! Grid is written wrongly!");

            }

        }

    }

    if(image.getGrid().getGrid().size() != image.getResolution().getWidth() * image.getResolution().getHeight()) throw std::out_of_range("ERROR! Amount of pixels does not match the resolution of the image!");

}

FileReader::FileReader() {}

FileReader::FileReader(const string& name) {
    
    this->file.open(name);

    if(!this->file.is_open()) throw std::invalid_argument("ERROR! Couldn't open the file!");

}

void FileReader::switchFile(const string& name) {

    this->file.close();

    this->file.open(name);
    
    if(!this->file.is_open()) throw std::invalid_argument("ERROR! Couldn't open the file!");

    this->max_value_needed = true;

}

Image FileReader::convertToImage() {

    Image image;

    vector<string> lines = this->convertToString(this->file);

    this->setType(image, lines.front());
    
    size_t lineCounter = 1;

    while(lines[lineCounter].front() == '#') {

        this->addToDescription(image, lines[lineCounter]);
    
        lineCounter++;

    }

    this->setResolution(image, lines[lineCounter++]);
    
    if(this->max_value_needed) this->setMaxSize(image, lines[lineCounter++]);

    vector<string> temp;

    for(; lineCounter < lines.size(); lineCounter++) temp.push_back(lines[lineCounter]);

    this->setGrid(image, temp);

    return image;

}

FileReader::~FileReader() { file.close(); }

// int main() {

//     FileReader file("test.pbm");

//     Image testImage = file.convertToImage();

//     testImage.writeTo("output");

// }