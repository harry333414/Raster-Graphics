#pragma once

#include "../Image/Image.hpp"

#include <fstream>

using std::ifstream;

class FileReader {

///         TBD !!!!!!!!READING 1 LINE FILES!!!!!!!!

    private:

        ifstream file;

        bool max_value_needed = true;

        size_t linesCounter(ifstream& file);

        vector<string> convertToString(ifstream& file);
        vector<string> convertToString_PPM(Image& image, vector<string>& initial);

        size_t spaceCounterAndExceptionChecker(Image& image, const string& line);
        size_t stringToNumber(const string& line, size_t start, size_t end);
        
        void setType(Image& image, const string& line);

        void addToDescription(Image& image, const string& line);

        void setResolution(Image& image, const string& line);

        void setMaxSize(Image& image, const string& line);

        void setGrid(Image& image, const vector<string>& lines);

    public:

        FileReader();
        FileReader(const string& name);

        void switchFile(const string& name);

        Image convertToImage(); 

        ~FileReader();

};