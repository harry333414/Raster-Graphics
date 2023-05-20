#pragma once

#include "../Type/Type.hpp"
#include "../Description/Description.hpp"
#include "../Misc/Point/Point.hpp"
#include "../Grid/Grid.hpp"

class Image {

    protected:

        static const size_t MAX_LINE_LENGTH = 75;
        static const size_t MAX_MAX_VALUE = 1;

        Type type;
        Description description;
        Point resolution;
        size_t max_value;
        Grid grid;

    public:

        Image();
        Image(Type type, size_t width, size_t height, size_t max_value);
        Image(Type type, string description, size_t width, size_t height, size_t max_value);
        Image(Type type, vector<string> description, size_t width, size_t height, size_t max_value);

        virtual bool operator == (const Image& other);

        virtual Type getType() const;
        virtual Description getDescription() const;
        virtual Point getResolution() const;
        virtual size_t getMaxValue() const;
        virtual Grid getGrid() const;

        virtual void setMaxValue(size_t max_value);

        virtual void print() const;

        virtual void writeTo(const string& name);

        virtual ~Image() = default;

};