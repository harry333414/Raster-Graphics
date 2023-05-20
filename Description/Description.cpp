#include "Description.hpp"

#include <iostream>

using std::cout;

Description::Description()
    : lines(0, "") {}

Description::Description(size_t size)
    : lines(size, "") {}

Description::Description(string line)
    : lines(1, line) {}

Description::Description(vector<string> lines)
    : lines(lines) {}

bool Description::operator == (const Description& other) {

    if(this->lines.size() != other.lines.size()) return false;

    for(size_t i = 0; i < this->lines.size(); i++) {

        if(this->lines[i] != other.lines[i]) return false;

    }

    return true;

}

vector<string> Description::getDescription() const { return this->lines; }

void Description::setDescription(const vector<string> description) { this->lines = description; }

bool Description::with_description() const {

    if(this->lines.size() == 0) return false;
    else return true;

}

const string Description::toString() const {

    string descriptionString;

    for(size_t i = 0; i < this->lines.size(); i++) {

        if(this->lines[i][0] != '#') descriptionString += "# ";

        descriptionString += this->lines[i] + '\n';

    }    

    return descriptionString;

}

string& Description::operator [] (size_t index) {

    if(index < 0 || index > this->lines.size()) throw "ERROR! Index cannot have such parameters!";

    return this->lines[index];

}

const string& Description::operator [] (size_t index) const {

    if(index < 0 || index > this->lines.size()) throw "ERROR! Index cannot have such parameters!";

    return this->lines[index];

}

void Description::print() const {

    for(size_t i = 0; i < this->lines.size(); i++) cout << this->lines[i] << '\n';

}