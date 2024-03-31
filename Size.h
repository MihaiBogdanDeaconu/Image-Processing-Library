#pragma once

/**
 * @class Size
 * @brief Represents the size of an object or image in terms of width and height.
 *
 * The Size class provides a convenient way to store and manipulate the dimensions
 * of an object or image. It encapsulates the width and height values and provides
 * various methods and operators for comparison and modification.
 *
 * @note The width and height values must be non-negative integers.
 */
class Size
{
private:
    unsigned int width;  /**< The width of the object or image. */
    unsigned int height; /**< The height of the object or image. */

public:
    /**
     * @brief Default constructor.
     *
     * Initializes a Size object with width and height set to 0.
     */
    Size();

    /**
     * @brief Parameterized constructor.
     *
     * Initializes a Size object with the specified width and height.
     *
     * @param width The width of the object or image.
     * @param height The height of the object or image.
     */
    Size(unsigned int width, unsigned int height);

    /**
     * @brief Get the width of the object or image.
     *
     * @return The width of the object or image.
     */
    unsigned int getWidth() const;

    /**
     * @brief Get the height of the object or image.
     *
     * @return The height of the object or image.
     */
    unsigned int getHeight() const;

    /**
     * @brief Set the width of the object or image.
     *
     * @param newWidth The new width value.
     */
    void setWidth(unsigned int newWidth);

    /**
     * @brief Set the height of the object or image.
     *
     * @param newHeight The new height value.
     */
    void setHeight(unsigned int newHeight);

    /**
     * @brief Equality comparison operator.
     *
     * Compares two Size objects for equality. Two Size objects are considered equal
     * if their width and height values are the same.
     *
     * @param other The Size object to compare with.
     * @return True if the Size objects are equal, false otherwise.
     */
    bool operator==(const Size &other) const;

    /**
     * @brief Less than comparison operator.
     *
     * Compares two Size objects to determine if the calling object is less than the
     * specified Size object. The comparison is based on the area of the Size objects,
     * i.e., width * height.
     *
     * @param other The Size object to compare with.
     * @return True if the calling object is less than the specified Size object, false otherwise.
     */
    bool operator<(const Size &other) const;

    /**
     * @brief Less than or equal to comparison operator.
     *
     * Compares two Size objects to determine if the calling object is less than or equal to
     * the specified Size object. The comparison is based on the area of the Size objects,
     * i.e., width * height.
     *
     * @param other The Size object to compare with.
     * @return True if the calling object is less than or equal to the specified Size object, false otherwise.
     */
    bool operator<=(const Size &other) const;

    /**
     * @brief Greater than comparison operator.
     *
     * Compares two Size objects to determine if the calling object is greater than the
     * specified Size object. The comparison is based on the area of the Size objects,
     * i.e., width * height.
     *
     * @param other The Size object to compare with.
     * @return True if the calling object is greater than the specified Size object, false otherwise.
     */
    bool operator>(const Size &other) const;

    /**
     * @brief Greater than or equal to comparison operator.
     *
     * Compares two Size objects to determine if the calling object is greater than or equal to
     * the specified Size object. The comparison is based on the area of the Size objects,
     * i.e., width * height.
     *
     * @param other The Size object to compare with.
     * @return True if the calling object is greater than or equal to the specified Size object, false otherwise.
     */
    bool operator>=(const Size &other) const;
};