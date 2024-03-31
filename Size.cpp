#include <iostream>
#include "Size.h"

Size::Size() : width{0}, height{0} {}

/**
 * @brief Constructs a Size object with the specified width and height.
 *
 * This constructor initializes a Size object with the given width and height values.
 *
 * @param width The width of the Size object.
 * @param height The height of the Size object.
 */
/**
 * @brief Constructs a Size object with the specified width and height.
 *
 * This constructor initializes a Size object with the given width and height values.
 * The width and height must be non-negative integers.
 *
 * @param width The width of the Size object.
 * @param height The height of the Size object.
 */
Size::Size(unsigned int width, unsigned int height)
{
    this->width = width;
    this->height = height;
}

/**
 * @brief Get the width of the Size object.
 *
 * This function returns the width of the Size object. The width represents the horizontal dimension of the object.
 *
 * @return The width of the Size object.
 */
unsigned int Size::getWidth() const
{
    return this->width;
}

/**
 * @brief Get the height of the Size object.
 *
 * This function returns the height value of the Size object.
 *
 * @return The height of the Size object.
 */
unsigned int Size::getHeight() const
{
    return this->height;
}

/**
 * @brief Sets the width of the Size object.
 *
 * This function sets the width of the Size object to the specified value.
 *
 * @param newWidth The new width value to be set.
 */
void Size::setWidth(unsigned int newWidth)
{
    this->width = newWidth;
}

/**
 * @brief Sets the height of the Size object.
 *
 * This function sets the height of the Size object to the specified value.
 *
 * @param newHeight The new height value to be set.
 */
void Size::setHeight(unsigned int newHeight)
{
    this->height = newHeight;
}

/**
 * @brief Checks if the current Size object is equal to another Size object.
 *
 * This operator compares the width and height of the current Size object with the width and height of the other Size object.
 * If both the width and height are equal, the operator returns true; otherwise, it returns false.
 *
 * @param other The Size object to compare with.
 * @return true if the current Size object is equal to the other Size object, false otherwise.
 */
bool Size::operator==(const Size &other) const
{
    return this->width == other.getWidth() && this->height == other.getHeight();
}

/**
 * @brief Overloaded less than operator for comparing the size of two Size objects.
 *
 * This operator compares the size of two Size objects based on their total area (width * height).
 *
 * @param other The Size object to compare with.
 * @return True if the size of the current Size object is less than the size of the other Size object, false otherwise.
 */
bool Size::operator<(const Size &other) const
{
    return (this->width * this->height) < (other.getWidth() * other.getHeight());
}

/**
 * @brief Checks if the current Size object is less than or equal to the provided Size object.
 *
 * The operator compares the area of the current Size object (width * height) with the area of the provided Size object (other.getWidth() * other.getHeight()).
 * If the area of the current Size object is less than or equal to the area of the provided Size object, the function returns true; otherwise, it returns false.
 *
 * @param other The Size object to compare with.
 * @return True if the current Size object is less than or equal to the provided Size object, false otherwise.
 */
bool Size::operator<=(const Size &other) const
{
    return (this->width * this->height) <= (other.getWidth() * other.getHeight());
}

/**
 * @brief Overloaded greater-than operator for comparing the size of two Size objects.
 *
 * This operator compares the size of the current Size object with the size of the other Size object.
 * The size of a Size object is determined by multiplying its width and height values.
 *
 * @param other The Size object to compare with.
 * @return True if the size of the current Size object is greater than the size of the other Size object, false otherwise.
 */
bool Size::operator>(const Size &other) const
{
    return (this->width * this->height) > (other.getWidth() * other.getHeight());
}

/**
 * @brief Checks if the current Size object is greater than or equal to the provided Size object.
 *
 * The operator compares the area of the current Size object with the area of the provided Size object.
 * The area of a Size object is calculated by multiplying its width and height.
 *
 * @param other The Size object to compare with.
 * @return True if the current Size object is greater than or equal to the provided Size object, false otherwise.
 */
bool Size::operator>=(const Size &other) const
{
    return (this->width * this->height) >= (other.getWidth() * other.getHeight());
}