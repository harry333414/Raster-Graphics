#pragma once

#include "../IPrintable/IPrintable.hpp"

#include <iostream>

using std::size_t;

class Point : public IPrintable {

    private:

        size_t width;
        size_t height;

    public:

        Point();
        Point(size_t width, size_t height);

        bool operator == (const Point& other);

        size_t getWidth() const;
        size_t getHeight() const;

        const string toString() const override final;

        void print() const override final;

        ~Point() = default;

};