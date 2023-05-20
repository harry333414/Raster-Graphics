#pragma once

#include "../Misc/IPrintable/IPrintable.hpp"
#include "../Misc/Point/Point.hpp"

#include <iostream>
#include <vector>
#include <string>

using std::size_t;
using std::vector;
using std::string;

class Grid : public IPrintable {

    private:

        vector<vector<size_t>> grid;

    public:
    
        Grid();
        Grid(size_t width, size_t height);
        Grid(size_t width, size_t height, size_t number);
        Grid(Point resolution);
        Grid(Point resolution, size_t number);
        Grid(vector<size_t> line);
        Grid(vector<vector<size_t>> grid);

        bool operator == (const Grid& other);

        vector<vector<size_t>> getGrid() const;

        const string toString() const override final;

        void print() const override final;

        ~Grid() = default;

};