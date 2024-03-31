#pragma once
#include "Point.h"

/**
 * @class Rectangle
 * @brief Represents a rectangle in a 2D space.
 *
 * The Rectangle class provides functionality to manipulate and perform operations on rectangles.
 * It stores the position of the top-left corner, as well as the width and height of the rectangle.
 */
class Rectangle
{
private:
    int x;               ///< The x-coordinate of the top-left corner of the rectangle.
    int y;               ///< The y-coordinate of the top-left corner of the rectangle.
    unsigned int width;  ///< The width of the rectangle.
    unsigned int height; ///< The height of the rectangle.

public:
    /**
     * @brief Default constructor.
     *
     * Initializes a rectangle with default values (x = 0, y = 0, width = 0, height = 0).
     */
    Rectangle();

    /**
     * @brief Parameterized constructor.
     *
     * Initializes a rectangle with the specified values.
     *
     * @param x The x-coordinate of the top-left corner of the rectangle.
     * @param y The y-coordinate of the top-left corner of the rectangle.
     * @param width The width of the rectangle.
     * @param height The height of the rectangle.
     */
    Rectangle(int x, int y, unsigned int width, unsigned int height);

    /**
     * @brief Get the x-coordinate of the top-left corner of the rectangle.
     *
     * @return The x-coordinate of the top-left corner.
     */
    int getX() const;

    /**
     * @brief Get the y-coordinate of the top-left corner of the rectangle.
     *
     * @return The y-coordinate of the top-left corner.
     */
    int getY() const;

    /**
     * @brief Get the width of the rectangle.
     *
     * @return The width of the rectangle.
     */
    unsigned int getWidth() const;

    /**
     * @brief Get the height of the rectangle.
     *
     * @return The height of the rectangle.
     */
    unsigned int getHeight() const;

    /**
     * @brief Set the x-coordinate of the top-left corner of the rectangle.
     *
     * @param newX The new x-coordinate.
     */
    void setX(int newX);

    /**
     * @brief Set the y-coordinate of the top-left corner of the rectangle.
     *
     * @param newY The new y-coordinate.
     */
    void setY(int newY);

    /**
     * @brief Set the width of the rectangle.
     *
     * @param newWidth The new width.
     */
    void setWidth(unsigned int newWidth);

    /**
     * @brief Set the height of the rectangle.
     *
     * @param newHeight The new height.
     */
    void setHeight(unsigned int newHeight);

    /**
     * @brief Translate the rectangle by adding the coordinates of a point.
     *
     * @param point The point to be added to the rectangle's coordinates.
     */
    void operator+(const Point &point);

    /**
     * @brief Translate the rectangle by subtracting the coordinates of a point.
     *
     * @param point The point to be subtracted from the rectangle's coordinates.
     */
    void operator-(const Point &point);

    /**
     * @brief Calculate the intersection of two rectangles.
     *
     * @param rtg The rectangle to intersect with.
     * @return The resulting rectangle after the intersection.
     */
    Rectangle operator&(const Rectangle &rtg);

    /**
     * @brief Calculate the union of two rectangles.
     *
     * @param rtg The rectangle to union with.
     * @return The resulting rectangle after the union.
     */
    Rectangle operator|(const Rectangle &rtg);
};