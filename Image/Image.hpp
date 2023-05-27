#pragma once

#include "../Type/Type.hpp"
#include "../TypeConverter/TypeConverter.hpp"
#include "../Description/Description.hpp"
#include "../Misc/Point/Point.hpp"
#include "../Grid/RGB_grid/Grid_RGB.hpp"

class Image {

    private:

        static const size_t MAX_LINE_LENGTH = 75;
        static const size_t MAX_MAX_VALUE = 255;

        Type type;
        TypeConverter typeConverter;
        Description description;
        Point resolution;
        size_t max_value;
        Grid grid;

        void copy(const Image& other);

    public:

        Image();
        Image(Type type, size_t width, size_t height, size_t max_value);
        Image(Type type, string description, size_t width, size_t height, size_t max_value);
        Image(Type type, vector<string> description, size_t width, size_t height, size_t max_value);

        
        Image(const Image& other);
        Image& operator = (const Image& other);

        void RGBToGrayscale();
        void GrayscaleToMonochrome();
        void negative();

        bool operator == (const Image& other);

        Type getType() const;
        Description getDescription() const;
        Point getResolution() const;
        size_t getMaxValue() const;
        Grid getGrid() const;

        void setType(Type type);
        void setDescription(const Description& description);
        void setResolution(size_t width, size_t height);
        void setMaxValue(size_t max_value);
        void setGrid(const Grid& grid);
        void setGridResolution(size_t width, size_t height);
        void setGridGrayscaleBool(bool grayscale);
        void setGridMonochromeBool(bool monochrome);
        void addToDescription(const string& line);
        void addToGrid(const Grid grid);
        void setGridAt(size_t index, size_t red, size_t green, size_t blue);

        void print() const;

        void writeTo(const string& name);

        ~Image() = default;

};