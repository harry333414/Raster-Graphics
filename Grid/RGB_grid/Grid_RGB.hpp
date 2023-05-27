#pragma once

#include "../../Misc/IPrintable/IPrintable.hpp"
#include "../../Misc/Point/Point.hpp"
#include "../../Misc/RGB/RGB.hpp"

#include <iostream>
#include <vector>
#include <string>

using std::size_t;
using std::vector;
using std::string;
using std::cout;

class Grid : public IPrintable {

    private:
    
        vector<RGB> grid;
        Point resolution;
        size_t max_value;
        bool grayscale = false;
        bool monochrome = false;

        bool isItGrayscalePixel(RGB pixel) const;
        
    public:

        Grid();
        Grid(size_t width, size_t height);
        Grid(Point resolution);
        Grid(vector<RGB> rgb_grid);
        Grid(const Grid& other);

        RGB& operator [] (size_t index);
        const RGB& operator [] (size_t index) const;

        Grid& operator = (const Grid& other);
        bool operator == (const Grid& other);

        vector<RGB> getGrid() const;
        size_t getWidth() const;
        size_t getHeight() const;
        size_t getMaxValue() const;
        RGB getPixelAt(size_t index) const;
        RGB getGridAt(size_t width, size_t height) const;

        bool isItGrayscaleGrid() const;
        bool isItMonochromeGrid() const;
        bool isItGrayscaleAndPPMGrid() const;

        void setGridAt(size_t index, size_t red, size_t green, size_t blue);
        void setGrayscaleGridAt(size_t index, size_t grayscale);
        void setGrayscaleBool(bool grayscale);
        void setMonochromeBool(bool monochrome);
        void setResolution(size_t width, size_t height);
        void setMaxValue(size_t max_value);
        void addToGrid(const vector<RGB> line);
        void setPixelAt(size_t index, RGB pixel);

        void convertToGrayscale();
        void convertToMonochrome();
        void convertToNegative();

        const string toString() const override final;

        void print() const override final;

        ~Grid() = default;

};