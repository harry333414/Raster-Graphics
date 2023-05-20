#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

using std::size_t;
using std::string;
using std::vector;

class ConvertedFile {

    private:

        size_t type;
        string description;
        size_t width, height;
        size_t max_value;
        vector<vector<size_t>> grid;

        size_t numberOfLines(std::ifstream& file);

        vector<string> getLines(std::ifstream& file, size_t counter);

        void setType(string line);
        
        // MORE THAN ONE LINE OF DESCRIPTION!
        void setDescription(string line, bool withDescription);
        
        void setWidthAndHeight(vector<string> lines, bool withDescription);

        void setMaxValue(vector<string> lines, bool withDescription);
        
        void setGrid(vector<string> lines, size_t counter, bool withDescription);

    public:

        ConvertedFile();
        
        void getInfo(std::ifstream& file);

        bool isItWithDescription(string line);

        void setAll(vector<string> lines, size_t counter);

        void printInfo() const;

        ~ConvertedFile() = default;

};