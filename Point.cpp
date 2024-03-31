#include <iostream>
#include "Point.h"

/**
 * @brief Default constructor for the Point class.
 * Initializes both x and y coordinates to zero.
 */
Point::Point() : x{0}, y{0} {}

/**
 * @brief Parameterized constructor for the Point class.
 *
 * @param x The x-coordinate of the point.
 * @param y The y-coordinate of the point.
 */
Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

/**
 * @brief Getter method for the x-coordinate of the point.
 *
 * @return The x-coordinate of the point.
 */
int Point::getX() const
{
    return this->x;
}

/**
 * @brief Getter method for the y-coordinate of the point.
 *
 * @return The y-coordinate of the point.
 */
int Point::getY() const
{
    return this->y;
}

/**
 * @brief Setter method for the x-coordinate of the point.
 *
 * @param newX The new x-coordinate of the point.
 */
void Point::setX(int newX)
{
    this->x = newX;
}

/**
 * @brief Setter method for the y-coordinate of the point.
 *
 * @param newY The new y-coordinate of the point.
 */
void Point::setY(int newY)
{
    this->y = newY;
}