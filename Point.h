#pragma once

/**
 * @class Point
 * @brief Represents a point in a 2D coordinate system.
 */
class Point{

private:
    int x; /**< The x-coordinate of the point. */
    int y; /**< The y-coordinate of the point. */

public:
    /**
     * @brief Default constructor for the Point class.
     * Initializes the point with coordinates (0, 0).
     */
    Point();

    /**
     * @brief Constructor for the Point class.
     * Initializes the point with the specified coordinates.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     */
    Point(int x, int y);

    /**
     * @brief Get the x-coordinate of the point.
     * @return The x-coordinate of the point.
     */
    int getX() const;

    /**
     * @brief Get the y-coordinate of the point.
     * @return The y-coordinate of the point.
     */
    int getY() const;

    /**
     * @brief Set the x-coordinate of the point.
     * @param newX The new x-coordinate of the point.
     */
    void setX(int newX);

    /**
     * @brief Set the y-coordinate of the point.
     * @param newY The new y-coordinate of the point.
     */
    void setY(int newY);

};