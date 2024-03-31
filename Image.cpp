#include <iostream>
#include <fstream>
#include <exception>
#include "Image.h"

/**
 * @brief Default constructor for the Image class.
 *
 * This constructor initializes the Image object with default values.
 * The image data is set to nullptr, and the width and height are set to 0.
 */
Image::Image() : m_data{nullptr}, m_width{0}, m_height{0} {}

/**
 * @brief Constructs an Image object with the specified width and height.
 *
 * @param w The width of the image.
 * @param h The height of the image.
 */
Image::Image(unsigned int w, unsigned int h)
{
    this->m_width = w;
    this->m_height = h;
    this->m_data = new unsigned char *[h];
    for (int i = 0; i < h; ++i)
    {
        m_data[i] = new unsigned char[w];
        for (int j = 0; j < w; ++j)
            m_data[i][j] = 0;
    }
}

/**
 * @brief Get the width of the image.
 *
 * @return unsigned int The width of the image.
 */
unsigned int Image::getWidth() const
{
    return this->m_width;
}

/**
 * @brief Returns the height of the image.
 *
 * @return The height of the image.
 */
unsigned int Image::getHeight() const
{
    return this->m_height;
}

/**
 * @brief Get the data of the image.
 *
 * @return unsigned char** The data of the image.
 */
unsigned char **Image::getData() const
{
    return this->m_data;
}

/**
 * Returns the maximum pixel value in the image.
 *
 * @return The maximum pixel value.
 */
unsigned int Image::maxPixelValue() const
{
    unsigned int maxx = 0;
    for (int i = 0; i < this->m_height; ++i)
        for (int j = 0; j < this->m_width; ++j)
            if (this->m_data[i][j] > maxx)
                maxx = this->m_data[i][j];
    return maxx;
}

/**
 * @brief Sets the width of the image to the specified value.
 *
 * This function resizes the image width to the specified value. If the new width is smaller than the current width,
 * the image data will be truncated. If the new width is larger than the current width, the additional pixels will be
 * initialized with zero.
 *
 * @param newWidth The new width of the image.
 */
void Image::setWidth(unsigned int newWidth)
{
    unsigned char **newData = new unsigned char *[this->m_height];
    for (int i = 0; i < this->m_height; ++i)
    {
        newData[i] = new unsigned char[newWidth];
        if (newWidth < this->m_width)
        {
            for (int j = 0; j < newWidth; ++j)
                newData[i][j] = this->m_data[i][j];
        }
        else
        {
            for (int j = 0; j < this->m_width; ++j)
                newData[i][j] = this->m_data[i][j];
            for (int j = this->m_width; j < newWidth; ++j)
                newData[i][j] = 0;
        }
    }
    for (int i = 0; i < this->m_height; ++i)
        delete[] this->m_data[i];
    delete[] this->m_data;
    this->m_width = newWidth;
    this->m_data = newData;
}

/**
 * Sets the pixel value at the specified coordinates to a new value.
 *
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param newValue The new value to set for the pixel.
 *
 * @note The new value will be clamped between 0 and 255 to ensure it is within the valid range for pixel values.
 */
void Image::setPixel(int x, int y, int newValue)
{
    if (newValue > 255)
        newValue = 255;
    else if (newValue < 0)
        newValue = 0;
    this->m_data[x][y] = static_cast<unsigned char>(newValue);
}

/**
 * @brief Sets the height of the image.
 *
 * This function sets the height of the image to the specified value. If the new height is smaller than the current height,
 * the function will delete the rows from the bottom of the image data. If the new height is larger than the current height,
 * the function will allocate new memory for the additional rows and initialize them with zeros.
 *
 * @param newHeight The new height of the image.
 */
void Image::setHeight(unsigned int newHeight)
{
    if (newHeight < this->m_height)
    {
        for (int i = newHeight; i < this->m_height; ++i)
            delete[] this->m_data[i];
        this->m_height = newHeight;
    }
    else
    {
        unsigned char **newData = new unsigned char *[newHeight];
        for (int i = 0; i < newHeight; ++i)
        {
            newData[i] = new unsigned char[this->m_width];
            if (i < this->m_height)
            {
                for (int j = 0; j < this->m_width; ++j)
                    newData[i][j] = this->m_data[i][j];
            }
            else
            {
                for (int j = 0; j < this->m_width; ++j)
                    newData[i][j] = 0;
            }
        }
        delete[] this->m_data;
        this->m_height = newHeight;
        this->m_data = newData;
    }
}

/**
 * Sets the pixel value at the specified point in the image.
 *
 * @param point The point representing the location of the pixel.
 * @param newValue The new value to set for the pixel.
 */
void Image::setPixel(Point point, unsigned int newValue)
{
    this->m_data[point.getX()][point.getY()] = newValue;
}

/**
 * Returns a reference to the pixel value at the specified coordinates.
 *
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @return A reference to the pixel value at the specified coordinates.
 */
unsigned char &Image::at(int x, int y) const
{
    return this->m_data[x][y];
}

/**
 * Returns a reference to the pixel value at the specified point.
 *
 * @param point The point representing the location of the pixel.
 * @return A reference to the pixel value at the specified point.
 */
unsigned char &Image::at(Point point)
{
    return this->m_data[point.getX()][point.getY()];
}

/**
 * Returns a pointer to the specified row in the image.
 *
 * @param y The y-coordinate of the row.
 * @return A pointer to the specified row in the image.
 */
unsigned char *Image::row(int y)
{
    return this->m_data[y];
}

/**
 * Retrieves the region of interest (ROI) from the given image and places it into another image.
 *
 * @param roiImg The image where the ROI will be stored.
 * @param roiRect The rectangle defining the region of interest.
 * @return True if the operation was successful, false otherwise.
 */
bool Image::getROI(Image &roiImg, Rectangle roiRect)
{

    if (roiRect.getX() + roiRect.getWidth() > roiImg.getWidth() || roiRect.getY() + roiRect.getHeight() > roiImg.getHeight())
        return false;

    Image cropped(roiRect.getWidth(), roiRect.getHeight());
    for (int i = 0; i < cropped.getHeight(); ++i)
    {
        for (int j = 0; j < cropped.getWidth(); ++j)
            cropped.setPixel(i, j, roiImg.at(i + roiRect.getY(), j + roiRect.getX()));
    }
    roiImg = cropped;
    return true;
}

/**
 * Retrieves the region of interest (ROI) from the given image and places it into another image.
 *
 * @param roiImg The image where the ROI will be stored.
 * @param x The x-coordinate of the top-left corner of the ROI.
 * @param y The y-coordinate of the top-left corner of the ROI.
 * @param width The width of the ROI.
 * @param height The height of the ROI.
 * @return True if the operation was successful, false otherwise.
 */
bool Image::getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{

    if (x + width > roiImg.getWidth() || y + height > roiImg.getHeight())
        return false;

    Image cropped(width, height);
    for (int i = 0; i < cropped.getHeight(); ++i)
    {
        for (int j = 0; j < cropped.getWidth(); ++j)
            cropped.setPixel(i, j, roiImg.at(i + y, j + x));
    }
    roiImg = cropped;
    return true;
}

// Rule of three: destructor, copy constructor, assignment operator
/**
 * Releases the memory allocated for the image data.
 */
void Image::release()
{
    for (int i = 0; i < this->m_height; ++i)
    {
        delete[] this->m_data[i];
        this->m_data[i] = nullptr;
    }
    delete[] this->m_data;
    this->m_data = nullptr;
}

/**
 * Destructor for the Image class. Releases allocated memory.
 */
Image::~Image()
{
    release();
}

/**
 * Copy constructor for the Image class.
 *
 * @param other The image to be copied.
 */
Image::Image(const Image &other)
{
    this->m_width = other.getWidth();
    this->m_height = other.getHeight();
    this->m_data = new unsigned char *[this->m_height];
    for (int i = 0; i < this->m_height; ++i)
    {
        this->m_data[i] = new unsigned char[this->m_width];
        for (int j = 0; j < this->m_width; ++j)
            m_data[i][j] = other.m_data[i][j];
    }
}

/**
 * Assignment operator for the Image class.
 *
 * @param other The image to be assigned.
 * @return Reference to the assigned image.
 */
Image &Image::operator=(const Image &other)
{
    if (this != &other)
    {
        release();
        m_width = other.getWidth();
        m_height = other.getHeight();
        m_data = new unsigned char *[m_height];
        for (int i = 0; i < m_height; ++i)
        {
            m_data[i] = new unsigned char[m_width];
            for (int j = 0; j < m_width; ++j)
                m_data[i][j] = other.m_data[i][j];
        }
    }
    return *this;
}

/**
 * Overloaded addition operator that adds pixel values of two images element-wise.
 *
 * @param i The image to be added.
 * @return The resulting image after addition.
 * @throws std::invalid_argument if the images have different dimensions.
 */
Image Image::operator+(const Image &i)
{
    try
    {
        if (this->m_width != i.getWidth() || this->m_height != i.getHeight())
            throw std::invalid_argument("Not the same size!");
        Image result(this->m_width, this->m_height);
        for (int k = 0; k < this->m_height; ++k)
            for (int j = 0; j < this->m_width; ++j)
                result.setPixel(k, j, static_cast<unsigned int>(this->m_data[k][j] + i.at(k, j)));
        return result;
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
        throw;
    }
}

/**
 * Overloaded subtraction operator that subtracts pixel values of two images element-wise.
 *
 * @param i The image to be subtracted.
 * @return The resulting image after subtraction.
 * @throws std::invalid_argument if the images have different dimensions.
 */
Image Image::operator-(const Image &i)
{
    try
    {
        if (this->m_width != i.getWidth() || this->m_height != i.getHeight())
            throw std::invalid_argument("Not the same size!");
        Image result(this->m_width, this->m_height);
        for (int k = 0; k < this->m_height; ++k)
            for (int j = 0; j < this->m_width; ++j)
                result.setPixel(k, j, static_cast<unsigned int>(this->m_data[k][j] - i.at(k, j)));
        return result;
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
        throw;
    }
}

/**
 * Overloaded multiplication operator that multiplies all pixel values of an image by a scalar value.
 *
 * @param s The scalar value to multiply the image with.
 * @return The resulting image after multiplication.
 */
Image Image::operator*(double s)
{
    Image result(this->m_width, this->m_height);
    for (int i = 0; i < this->m_height; ++i)
        for (int j = 0; j < this->m_width; ++j)
            result.setPixel(i, j, static_cast<int>(this->m_data[i][j] * s));
    return result;
}

/**
 * Returns the size of the image.
 *
 * @return Size object representing the width and height of the image.
 */
Size Image::size() const
{
    return Size(this->m_width, this->m_height);
}

/**
 * Checks if the image is empty.
 *
 * @return True if the image is empty, false otherwise.
 */
bool Image::isEmpty() const
{
    return m_data == nullptr && m_width == 0 && m_height == 0;
}

/**
 * Overloaded output stream operator for printing the image in PGM format.
 *
 * @param os The output stream.
 * @param dt The Image object to be printed.
 * @return The output stream.
 */
std::ostream &operator<<(std::ostream &os, const Image &dt)
{
    os << "P2" << std::endl;
    os << "# This is a pgm format" << std::endl;
    os << dt.getWidth() << " " << dt.getHeight() << std::endl;
    os << dt.maxPixelValue() << std::endl;
    for (int i = 0; i < dt.getHeight(); ++i)
    {
        for (int j = 0; j < dt.getWidth(); ++j)
        {
            os << static_cast<int>(dt.m_data[i][j]) << "  ";
        }
        os << std::endl;
    }
    return os;
}

/**
 * Overloaded input stream operator for reading the image in PGM format.
 *
 * @param is The input stream.
 * @param dt The Image object to store the read image.
 * @return The input stream.
 */
std::istream &operator>>(std::istream &is, Image &dt)
{
    std::string format, comment;
    unsigned int width, height, maxPixelValue, value;

    is >> format;
    std::getline(is >> std::ws, comment);
    is >> width;
    is >> height;
    is >> maxPixelValue;
    Image img(width, height);

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            is >> value;
            img.setPixel(i, j, value);
        }
    }
    dt = img;
    return is;
}

/**
 * Loads an image from a file.
 *
 * @param imagePath The path to the image file.
 * @return True if the image is successfully loaded, false otherwise.
 */
bool Image::load(const std::string imagePath)
{
    std::ifstream file(imagePath);
    if (!file.is_open())
        return false;

    file >> *this;
    file.close();
    return true;
}

/**
 * Saves the image to a file in PGM format.
 *
 * @param imagePath The path to save the image.
 * @return True if the image is successfully saved, false otherwise.
 */
bool Image::save(const std::string imagePath) const
{
    std::ofstream file(imagePath);
    if (!file.is_open())
        return false;
    file << *this;
    file.close();
    return true;
}

/**
 * Creates a new image filled with zeros.
 *
 * @param width The width of the new image.
 * @param height The height of the new image.
 * @return The created image.
 */
Image Image::zeros(unsigned int width, unsigned int height)
{
    Image img(width, height);
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
            img.setPixel(i, j, 0);
    }
    return img;
}

/**
 * Creates a new image filled with ones.
 *
 * @param width The width of the new image.
 * @param height The height of the new image.
 * @return The created image.
 */
Image Image::ones(unsigned int width, unsigned int height)
{
    Image img(width, height);
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
            img.setPixel(i, j, 1);
    }
    return img;
}