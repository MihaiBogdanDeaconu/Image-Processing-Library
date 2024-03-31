#pragma once
#include "ImageProcessing.h"

/**
 * @class Gamma
 * @brief A class that represents a gamma correction operation for image processing.
 *
 * The Gamma class is a subclass of the ImageProcessing class and provides functionality
 * to perform gamma correction on images. Gamma correction is a non-linear operation that
 * adjusts the brightness and contrast of an image by applying a power-law transformation.
 *
 * The gamma value determines the shape of the transformation curve. A gamma value less than
 * 1.0 will darken the image, while a gamma value greater than 1.0 will brighten the image.
 *
 * This class provides methods to get and set the gamma value, as well as to process an input
 * image and produce an output image with gamma correction applied.
 */
class Gamma : public ImageProcessing
{
private:
    double gamma; /**< The gamma value for gamma correction. */

public:
    /**
     * @brief Default constructor.
     *
     * Initializes the gamma value to 1.0.
     */
    Gamma();

    /**
     * @brief Constructor with gamma value.
     *
     * Initializes the gamma value to the specified value.
     *
     * @param gamma The gamma value for gamma correction.
     */
    Gamma(double gamma);

    /**
     * @brief Get the current gamma value.
     *
     * @return The current gamma value.
     */
    double getGamma();

    /**
     * @brief Set a new gamma value.
     *
     * @param newGamma The new gamma value for gamma correction.
     */
    void setGamma(double newGamma);

    /**
     * @brief Process the input image with gamma correction.
     *
     * Applies gamma correction to the input image and produces an output image with the
     * corrected gamma values.
     *
     * @param src The input image to be processed.
     * @param dst The output image with gamma correction applied.
     */
    void process(const Image &src, Image &dst) override;
};