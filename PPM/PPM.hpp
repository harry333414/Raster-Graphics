#pragma once

#include "../Image/Image.hpp"
#include "../Misc/RGB/RGB.hpp"

class PPM : public Image {

    private:

        static const size_t MAX_MAX_VALUE = 255;
        vector<RGB> rgb_grid;

    public:

        PPM();
        PPM(Type type, size_t width, size_t height, size_t max_value);
        PPM(Type type, string description, size_t width, size_t height, size_t max_value);
        PPM(Type type, vector<string> description, size_t width, size_t height, size_t max_value);

        void setMaxValue(size_t max_value) override final;

        ~PPM() = default;

};