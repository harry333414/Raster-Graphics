#include "UserInterface.hpp"

size_t UserInterface::session = 1;

UserInterface::UserInterface()
    : input(), images(), image_names(), converter() { this->session++; }

UserInterface::UserInterface(const string& input)
    : input(input), images(), image_names(), converter() { this->session++; }

Image& UserInterface::operator [] (size_t index) {

    if(index < 0 || index > this->images.size()) throw std::out_of_range("ERROR! There is no such image at this position!");

    return this->images[index];

}

const Image& UserInterface::operator [] (size_t index) const {

    if(index < 0 || index > this->images.size()) throw std::out_of_range("ERROR! There is no such image at this position!");

    return this->images[index];

}

const string& UserInterface::getInput() const { return this->input; }

const vector<Image> UserInterface::getImages() const { return this->images; }

const vector<string> UserInterface::getImageNames() const { return this->image_names; }

const FileReader& UserInterface::getConverter() const { return this->converter; }

void UserInterface::setInput(const string& input) { this->input = input; }

void UserInterface::setImages(const vector<Image> images) { this->images = images; }

void UserInterface::grayscale() {

    for(size_t i = 0; i < this->images.size(); i++) this->images[i].RGBToGrayscale();

}

void UserInterface::monochrome() {

    for(size_t i = 0; i < this->images.size(); i++) this->images[i].GrayscaleToMonochrome();

}

void UserInterface::negative() {

    for(size_t i = 0; i < this->images.size(); i++) this->images[i].negative();

}

void UserInterface::rotate(const string& direction) {

    vector<Image> temp(images);

    for(size_t i = 0; i < this->images.size(); i++) {



        for(size_t j = 0; j < this->images[i].getResolution().getHeight(); j++) {

            for(size_t k = 0; k < this->images[i + k].getResolution().getWidth(); j++) {

                

            }

        }

    }

}

void UserInterface::addImage(const Image& image) {

    // for(size_t i = 0; i < this->images.size(); i++) {

    //     if(this->images[i] == image) std::cerr << "Image is already put in, cannot put it again!" << std::endl;

    // }

    this->images.push_back(image);

}

void UserInterface::collage(const string& direction, const Image& image1, const Image& image2, const string& name) {

    Image collage;

    // If false = right, else true = down
    bool rightOrDown = false;

    if(direction == "RIGHT") rightOrDown = false;
    else if(direction == "DOWN") rightOrDown = true;
    else throw std::invalid_argument("ERROR! Collage cannot be made in this direction!");

    if(image1.getType() != image2.getType()) throw std::invalid_argument("ERROR! Images are not the same types!");
    if(image1.getResolution() != image2.getResolution()) throw std::invalid_argument("ERROR! Images don't have the same resolution!");

    size_t width, height;

    if(!rightOrDown) {

        width = image1.getResolution().getWidth();

        height = image1.getResolution().getHeight() + image2.getResolution().getHeight();

        collage.setResolution(width, height);

        collage.setGridResolution(width, height);

        size_t counter = 0;

        for(size_t i = 0; i < width * height; i++) {

            if(counter > image1.getResolution().getHeight()) collage.setGridAt(i, image2.getGrid().getGrid()[i].getRed(), image2.getGrid().getGrid()[i].getGreen(), image2.getGrid().getGrid()[i].getBlue());
            else collage.setGridAt(i, image1.getGrid().getGrid()[i].getRed(), image1.getGrid().getGrid()[i].getGreen(), image1.getGrid().getGrid()[i].getBlue());
            
            if(height == counter) counter = 0;
            else counter++;

        }

    }else {

        width = image1.getResolution().getWidth() + image2.getResolution().getWidth();

        height = image1.getResolution().getHeight();

        collage.setResolution(width, height);

        collage.setGridResolution(width, height);

        collage.addToGrid(image1.getGrid());
        collage.addToGrid(image2.getGrid());

    }

    this->images.push_back(collage);

}

// void UserInterface::collage(const string& direction, const Image& image1, const Image& image2, const string& name) {

//     if (image1.getType() != image2.getType()) throw std::invalid_argument("ERROR! Images are not the same types!");
//     if (image1.getResolution() != image2.getResolution()) throw std::invalid_argument("ERROR! Images don't have the same resolution!");

//     size_t width, height;

//     if (direction == "RIGHT") {
//         width = image1.getResolution().getWidth() + image2.getResolution().getWidth();
//         height = image1.getResolution().getHeight();
//     }
//     else if (direction == "DOWN") {
//         width = image1.getResolution().getWidth();
//         height = image1.getResolution().getHeight() + image2.getResolution().getHeight();
//     }
//     else {
//         throw std::invalid_argument("ERROR! Collage cannot be made in this direction!");
//     }

//     Image collage;
//     collage.setResolution(width, height);
//     collage.setGridResolution(width, height);

//     const Grid& grid1 = image1.getGrid();
//     const Grid& grid2 = image2.getGrid();
//     Grid collageGrid = collage.getGrid();

//     if (direction == "RIGHT") {

//         // Copy pixels from image1
//         for (size_t y = 0; y < image1.getResolution().getHeight(); y++) {
//             for (size_t x = 0; x < image1.getResolution().getWidth(); x++) {
//                 const RGB& pixel = grid1.getGridAt(x, y);
//                 collageGrid.setGridAt(x + y, pixel.getRed(), pixel.getGreen(), pixel.getBlue());
//             }
//         }

//         // Copy pixels from image2
//         for (size_t y = 0; y < image2.getResolution().getHeight(); y++) {
//             for (size_t x = 0; x < image2.getResolution().getWidth(); x++) {
//                 const RGB& pixel = grid2.getGridAt(x, y);
//                 collageGrid.setGridAt(x + image1.getResolution().getWidth() + y, pixel.getRed(), pixel.getGreen(), pixel.getBlue());
//             }
//         }
//     }
//     else if (direction == "DOWN") {

//         // Copy pixels from image1
//         for (size_t y = 0; y < image1.getResolution().getHeight(); y++) {
//             for (size_t x = 0; x < image1.getResolution().getWidth(); x++) {
//                 const RGB& pixel = grid1.getGridAt(x, y);
//                 collageGrid.setGridAt(x + y, pixel.getRed(), pixel.getGreen(), pixel.getBlue());
//             }
//         }

//         // Copy pixels from image2
//         for (size_t y = 0; y < image2.getResolution().getHeight(); y++) {
//             for (size_t x = 0; x < image2.getResolution().getWidth(); x++) {
//                 const RGB& pixel = grid2.getGridAt(x, y);
//                 collageGrid.setGridAt(x + y + image1.getResolution().getHeight(), pixel.getRed(), pixel.getGreen(), pixel.getBlue());
//             }
//         }
//     }

//     this->images.push_back(collage);
// }


void UserInterface::print() {}