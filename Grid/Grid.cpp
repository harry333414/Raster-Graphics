#include "Grid.hpp"

using std::cout;

Grid::Grid() 
    : grid(0, vector<size_t>(0, 0)) {}

Grid::Grid(size_t width, size_t height) 
    : grid(width, vector<size_t>(height, 0)) {}

Grid::Grid(size_t width, size_t height, size_t number)
    : grid(width, vector<size_t>(height, number)) {}

Grid::Grid(Point resolution)
    : grid(resolution.getWidth(), vector<size_t>(resolution.getHeight(), 0)) {}

Grid::Grid(Point resolution, size_t number) 
    : grid(resolution.getWidth(), vector<size_t>(resolution.getHeight(), number)) {}

Grid::Grid(vector<size_t> line) 
    : grid(1, line) {}

Grid::Grid(vector<vector<size_t>> grid)
    : grid(grid) {}

bool Grid::operator == (const Grid& other) {

    if(this->grid.size() != other.grid.size()) return false;

    for(size_t i = 0; i < this->grid.size(); i++) {

        if(this->grid[i].size() != other.grid[i].size()) return false;

        for(size_t j = 0; j < this->grid[i].size(); j++) {

            if(this->grid[i][j] != other.grid[i][j]) return false;

        }

    }

    return true;

}

vector<vector<size_t>> Grid::getGrid() const { return this->grid; }

const string Grid::toString() const {

    string gridString;

    for(size_t i = 0; i < this->grid.size(); i++) {

        for(size_t j = 0; j < this->grid[i].size(); j++) {
        
            gridString += std::to_string(this->grid[i][j]);
        
            gridString.push_back(' ');
        
        }

        gridString.push_back('\n');

    }

    gridString.pop_back();

    return gridString;

}

void Grid::print() const {

    for(size_t i = 0; i < this->grid.size(); i++) {

        for(size_t j = 0; j < this->grid[i].size(); j++) cout << this->grid[i][j] << ' ';

        cout << '\n';

    }

}