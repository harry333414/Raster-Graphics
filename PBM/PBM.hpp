#pragma once

#include "../Image/Image.hpp"

class PBM : public Image {

    public:

        PBM();
        PBM(Type type, size_t width, size_t height);
        PBM(Type type, string description, size_t width, size_t height);
        PBM(Type type, vector<string> description, size_t width, size_t height);

        ~PBM() = default;

};