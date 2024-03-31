#pragma once
#include "Size.h"
#include "Point.h"
#include "Rectangle.h"
#include <string>

class Image
{
public:
    /**
     * @brief Default constructor for the Image class.
     * Initializes an empty image.
     */
    Image();

    /**
     * @brief Parameterized constructor for the Image class.
     * Creates an image with the specified width and height.
     *
     * @param w Width of the image.
     * @param h Height of the image.
     */
    Image(unsigned int w, unsigned int h);

    /**
     * @brief Copy constructor for the Image class.
     * Creates a new image that is a copy of the given image.
     *
     * @param other Another Image object to copy from.
     */
    Image(const Image &other);

    /**
     * @brief Assignment operator for the Image class.
     * Assigns the contents of another Image object to this object.
     *
     * @param other Another Image object to assign from.
     * @return A reference to this Image object after assignment.
     */
    Image &operator=(const Image &other);

    /**
     * @brief Destructor for the Image class.
     * Deallocates memory allocated for the image data.
     */
    ~Image();

    /**
     * @brief Loads an image from the specified file.
     *
     * @param imagePath Path to the image file.
     * @return True if the image was successfully loaded, false otherwise.
     */
    bool load(std::string imagePath);

    /**
     * @brief Saves the image to the specified file.
     *
     * @param imagePath Path to save the image file.
     * @return True if the image was successfully saved, false otherwise.
     */
    bool save(std::string imagePath) const;

    /**
     * @brief Performs element-wise addition of two images.
     *
     * @param i Another Image object to add.
     * @return A new Image object resulting from the addition.
     */
    Image operator+(const Image &i);

    /**
     * @brief Performs element-wise subtraction of two images.
     *
     * @param i Another Image object to subtract.
     * @return A new Image object resulting from the subtraction.
     */
    Image operator-(const Image &i);

    /**
     * @brief Performs scalar multiplication of the image.
     *
     * @param s Scalar value to multiply.
     * @return A new Image object resulting from the multiplication.
     */
    Image operator*(double s);

    /**
     * @brief Retrieves a region of interest (ROI) from the image.
     *
     * @param roiImg Output parameter to store the ROI image.
     * @param roiRect Rectangle specifying the region of interest.
     * @return True if the ROI was successfully retrieved, false otherwise.
     */
    bool getROI(Image &roiImg, Rectangle roiRect);

    /**
     * @brief Retrieves a region of interest (ROI) from the image.
     *
     * @param roiImg Output parameter to store the ROI image.
     * @param x X-coordinate of the top-left corner of the ROI.
     * @param y Y-coordinate of the top-left corner of the ROI.
     * @param width Width of the ROI.
     * @param height Height of the ROI.
     * @return True if the ROI was successfully retrieved, false otherwise.
     */
    bool getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);

    /**
     * @brief Checks if the image is empty (has zero width or height).
     *
     * @return True if the image is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Returns the size (width and height) of the image.
     *
     * @return Size object representing the size of the image.
     */
    Size size() const;

    /**
     * @brief Returns the width of the image.
     *
     * @return Width of the image.
     */
    unsigned int getWidth() const;

    /**
     * @brief Returns the height of the image.
     *
     * @return Height of the image.
     */
    unsigned int getHeight() const;

    /**
     * @brief Returns a pointer to the raw pixel data of the image.
     *
     * @return Pointer to the raw pixel data.
     */
    unsigned char **getData() const;

    /**
     * @brief Sets the width of the image.
     *
     * @param newWidth New width of the image.
     */
    void setWidth(unsigned int newWidth);

    /**
     * @brief Sets the height of the image.
     *
     * @param newHeight New height of the image.
     */
    void setHeight(unsigned int newHeight);

    /**
     * @brief Sets the pixel value at the specified coordinates.
     *
     * @param x X-coordinate of the pixel.
     * @param y Y-coordinate of the pixel.
     * @param newValue New value to set for the pixel.
     */
    void setPixel(int x, int y, int newValue);

    /**
     * @brief Sets the pixel value at the specified point.
     *
     * @param point Point object representing the pixel coordinates.
     * @param newValue New value to set for the pixel.
     */
    void setPixel(Point point, unsigned int newValue);

    /**
     * @brief Accesses the pixel value at the specified coordinates.
     *
     * @param x X-coordinate of the pixel.
     * @param y Y-coordinate of the pixel.
     * @return Reference to the pixel value.
     */
    unsigned char &at(int x, int y) const;

    /**
     * @brief Accesses the pixel value at the specified point.
     *
     * @param pt Point object representing the pixel coordinates.
     * @return Reference to the pixel value.
     */
    unsigned char &at(Point pt);

    /**
     * @brief Returns a pointer to the pixel data of the specified row.
     *
     * @param y Y-coordinate of the row.
     * @return Pointer to the pixel data of the row.
     */
    unsigned char *row(int y);

    /**
     * @brief Releases the memory allocated for the image data.
     */
    void release();

    /**
     * @brief Overloaded stream insertion operator for writing image data to an output stream.
     *
     * @param os Output stream to write the image data to.
     * @param dt Image object to write.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Image &dt);

    /**
     * @brief Overloaded stream extraction operator for reading image data from an input stream.
     *
     * @param is Input stream to read the image data from.
     * @param dt Image object to populate.
     * @return Reference to the input stream.
     */
    friend std::istream &operator>>(std::istream &is, Image &dt);

    /**
     * @brief Creates an image filled with zeros.
     *
     * @param width Width of the image.
     * @param height Height of the image.
     * @return Image object filled with zeros.
     */
    static Image zeros(unsigned int width, unsigned int height);

    /**
     * @brief Creates an image filled with ones.
     *
     * @param width Width of the image.
     * @param height Height of the image.
     * @return Image object filled with ones.
     */
    static Image ones(unsigned int width, unsigned int height);

    /**
     * @brief Returns the maximum pixel value in the image.
     *
     * @return Maximum pixel value.
     */
    unsigned int maxPixelValue() const;

private:
    unsigned char **m_data; ///< Pointer to the raw pixel data of the image.
    unsigned int m_width;   ///< Width of the image.
    unsigned int m_height;  ///< Height of the image.
};
