#pragma once

#include "../Image/Image.hpp"

class PGM : public Image {

    private:

        static const size_t MAX_MAX_VALUE = 65535;

    public:

        PGM();
        PGM(Type type, size_t width, size_t height, size_t max_value);
        PGM(Type type, string description, size_t width, size_t height, size_t max_value);
        PGM(Type type, vector<string> description, size_t width, size_t height, size_t max_value);

        void setMaxValue(size_t max_value) override final;

        ~PGM() = default;
  
};