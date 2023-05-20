#pragma once

#include "../Image/Image.hpp"

class PBM {

    private:

        vector<Image> images;

        void pop_back_at(size_t index);

    public:

        PBM();
        PBM(Type type, size_t width, size_t height);
        PBM(Type type, vector<string> description, size_t width, size_t height);

        void addImage(Image image);
        void removeImage(Image image);

        void uploadImages(const string& start) const;

        ~PBM() = default;

};