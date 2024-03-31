#include <iostream>
#include "Rectangle.h"

/**
 * @brief Default constructor for the Rectangle class.
 * Initializes all attributes to zero.
 */
Rectangle::Rectangle() : x{0}, y{0}, width{0}, height{0} {}

/**
 * @brief Parameterized constructor for the Rectangle class.
 *
 * @param x The x-coordinate of the top-left corner of the rectangle.
 * @param y The y-coordinate of the top-left corner of the rectangle.
 * @param width The width of the rectangle.
 * @param height The height of the rectangle.
 */
Rectangle::Rectangle(int x, int y, unsigned int width, unsigned int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

/**
 * @brief Getter method for the x-coordinate of the top-left corner of the rectangle.
 *
 * @return The x-coordinate of the top-left corner of the rectangle.
 */
int Rectangle::getX() const
{
    return this->x;
}

/**
 * @brief Getter method for the y-coordinate of the top-left corner of the rectangle.
 *
 * @return The y-coordinate of the top-left corner of the rectangle.
 */
int Rectangle::getY() const
{
    return this->y;
}

/**
 * @brief Getter method for the width of the rectangle.
 *
 * @return The width of the rectangle.
 */
unsigned int Rectangle::getWidth() const
{
    return this->width;
}

/**
 * @brief Getter method for the height of the rectangle.
 *
 * @return The height of the rectangle.
 */
unsigned int Rectangle::getHeight() const
{
    return this->height;
}

/**
 * @brief Setter method for the x-coordinate of the top-left corner of the rectangle.
 *
 * @param newX The new x-coordinate of the top-left corner of the rectangle.
 */
void Rectangle::setX(int newX)
{
    this->x = newX;
}

/**
 * @brief Setter method for the y-coordinate of the top-left corner of the rectangle.
 *
 * @param newY The new y-coordinate of the top-left corner of the rectangle.
 */
void Rectangle::setY(int newY)
{
    this->y = newY;
}

/**
 * @brief Setter method for the width of the rectangle.
 *
 * @param newWidth The new width of the rectangle.
 */
void Rectangle::setWidth(unsigned int newWidth)
{
    this->width = newWidth;
}

/**
 * @brief Setter method for the height of the rectangle.
 *
 * @param newHeight The new height of the rectangle.
 */
void Rectangle::setHeight(unsigned int newHeight)
{
    this->height = newHeight;
}

/**
 * @brief Overloaded addition operator for translating the Rectangle by a Point.
 *
 * Adds the x-coordinate and y-coordinate of the Point to the x-coordinate and y-coordinate of the Rectangle, respectively.
 *
 * @param point The Point to add.
 */
void Rectangle::operator+(const Point &point)
{
    this->x += point.getX();
    this->y += point.getY();
}

/**
 * @brief Overloaded subtraction operator for translating the Rectangle by a Point.
 *
 * Subtracts the x-coordinate and y-coordinate of the Point from the x-coordinate and y-coordinate of the Rectangle, respectively.
 *
 * @param point The Point to subtract.
 */
void Rectangle::operator-(const Point &point)
{
    this->x -= point.getX();
    this->y -= point.getY();
}

/**
 * @brief Overloaded bitwise AND operator for finding the intersection of two Rectangles.
 *
 * Computes the intersection of the current Rectangle and another Rectangle and returns the resulting Rectangle.
 * The intersection is a Rectangle that represents the overlapping area of the two Rectangles.
 *
 * @param rtg The Rectangle to intersect with.
 * @return The Rectangle representing the intersection of the two Rectangles.
 */
Rectangle Rectangle::operator&(const Rectangle &rtg)
{
    if (this->x + this->getWidth() <= rtg.getX() ||
        this->y - this->height >= rtg.getY() ||
        this->x >= rtg.getX() + rtg.getWidth() ||
        this->y <= rtg.getY() - rtg.getHeight())
    {
        return Rectangle(0, 0, 0, 0);
    }
    int xIntersect = std::max(this->x, rtg.getX());
    int yIntersect = std::min(this->y, rtg.getY());
    int widthIntersect = std::min(this->x + this->width, rtg.getX() + rtg.getWidth()) - xIntersect;
    int heightIntersect = yIntersect - std::max(this->y - this->height, rtg.getY() - rtg.getHeight());
    return Rectangle(xIntersect, yIntersect, widthIntersect, heightIntersect);
}

/**
 * @brief Overloaded bitwise OR operator for finding the union of two Rectangles.
 *
 * Computes the union of the current Rectangle and another Rectangle and returns the resulting Rectangle.
 * The union is a Rectangle that represents the combined area of the two Rectangles.
 *
 * @param rtg The Rectangle to union with.
 * @return The Rectangle representing the union of the two Rectangles.
 */
Rectangle Rectangle::operator|(const Rectangle &rtg)
{
    int xReunion = std::min(this->x, rtg.getX());
    int yReunion = std::max(this->y, rtg.getY());
    int widthReunion = std::max(this->x + this->width, rtg.getX() + rtg.getWidth()) - xReunion;
    int heightReunion = yReunion - std::min(this->y - this->height, rtg.getY() - rtg.getHeight());
    return Rectangle(xReunion, yReunion, widthReunion, heightReunion);
}