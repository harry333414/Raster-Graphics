#pragma once

#include <string>

using std::string;

class IPrintable {

    public:

        virtual const string toString() const = 0;

        virtual void print() const = 0;

        virtual ~IPrintable() = default;

};