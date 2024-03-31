#pragma once
#include "Image.h"
#include "Point.h"
#include "Rectangle.h"

/**
 * @brief The Draw class provides static methods for drawing shapes on an Image.
 */
class Draw
{
public:
    /**
     * @brief Draws a circle on the given Image.
     *
     * @param img The Image on which to draw the circle.
     * @param center The center point of the circle.
     * @param radius The radius of the circle.
     * @param color The color of the circle.
     */
    static void drawCircle(Image &img, Point center, int radius, unsigned char color);

    /**
     * @brief Draws a line on the given Image.
     *
     * @param img The Image on which to draw the line.
     * @param p1 The starting point of the line.
     * @param p2 The ending point of the line.
     * @param color The color of the line.
     */
    static void drawLine(Image &img, Point p1, Point p2, unsigned char color);

    /**
     * @brief Draws a rectangle on the given Image.
     *
     * @param img The Image on which to draw the rectangle.
     * @param r The Rectangle object representing the rectangle.
     * @param color The color of the rectangle.
     */
    static void drawRectangle(Image &img, Rectangle r, unsigned char color);

    /**
     * @brief Draws a rectangle on the given Image.
     *
     * @param img The Image on which to draw the rectangle.
     * @param tl The top-left point of the rectangle.
     * @param br The bottom-right point of the rectangle.
     * @param color The color of the rectangle.
     */
    static void drawRectangle(Image &img, Point tl, Point br, unsigned char color);
};