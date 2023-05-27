#pragma once

#include "../FileReader/FileReader.hpp"

// enum class Direction {

//     DEF = 0,
//     UP,
//     DOWN,
//     LEFT,
//     RIGHT

// };

class UserInterface {

    private:

        static size_t session;

        string input;
        vector<Image> images;
        vector<string> image_names;
        FileReader converter;

    public:

        UserInterface();
        UserInterface(const string& input);

        Image& operator [] (size_t index);
        const Image& operator [] (size_t index) const;

        const string& getInput() const;
        const vector<Image> getImages() const;
        const vector<string> getImageNames() const;
        const FileReader& getConverter() const;

        void setInput(const string& input);
        void setImages(const vector<Image> images);
        
        void grayscale();
        void monochrome();
        void negative();
        void rotate(const string& direction);
        void addImage(const Image& image);
        void collage(const string& direction, const Image& image1, const Image& image2, const string& name);

        void print();

        ~UserInterface() = default;
    
};