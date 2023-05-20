#include "PBM.hpp"

void PBM::pop_back_at(size_t index) {

    if(index < 0 || index > this->images.size()) throw "ERROR! Cannot move this image as there aren't that many images stored!";

    for(size_t i = index; i < this->images.size() - 1; i++) std::swap(this->images[i], this->images[i + 1]);

}

PBM::PBM() { this->images.resize(2); }

PBM::PBM(Type type, size_t width, size_t height)
    : images(2, Image(type, width, height, 1)) {}

PBM::PBM(Type type, vector<string> description, size_t width, size_t height)
    : images(2, Image(type, description, width, height, 1)) {}

void PBM::addImage(Image image) { 
    
    for(size_t i = 0; i < this->images.size(); i++) {

        if(this->images[i] == image) throw "ERROR! This image has already been added to the editor!";

    }

    images.push_back(image);

}

void PBM::removeImage(Image image) {

    if(this->images.size() <= 0) throw "ERROR! There are no images in this session!";
    
    bool found = false;

    for(size_t i = 0; i < this->images.size(); i++) {

        if(this->images[i] == image) {

            this->pop_back_at(i); 
            
            found = true;

            break;

        }    

    }

    if(found == true) this->images.pop_back();
    else throw "ERROR! No such image in this session!";

}
 
/// ???????????????????????????????????????????????? 
void PBM::uploadImages(const string& start) const {

    for(size_t i = 0; i < this->images.size(); i++) {

        this->images[i].writeTo(start);

    }

}