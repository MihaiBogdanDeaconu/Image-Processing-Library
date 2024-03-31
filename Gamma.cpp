#include "Gamma.h"
#include <math.h>

/**
 * @brief Constructs a Gamma object with the specified gamma value.
 *
 * The gamma value determines the amount of gamma correction to be applied to an image.
 * A gamma value less than 1.0 will darken the image, while a gamma value greater than 1.0 will lighten the image.
 *
 * @param gamma The gamma value to be used for gamma correction.
 */
/**
 * @brief Default constructor for the Gamma class.
 * Initializes the `gamma` member variable to 0.
 */
Gamma::Gamma() : gamma{0} {}

/**
 * @brief Constructs a Gamma object with the specified gamma value.
 *
 * @param gamma The gamma value to set.
 */
Gamma::Gamma(double gamma)
{
    this->gamma = gamma;
}

/**
 * @brief Get the gamma value.
 *
 * @return The gamma value.
 */
double Gamma::getGamma()
{
    return this->gamma;
}

/**
 * @brief Sets the gamma value for the Gamma object.
 *
 * @param newGamma The new gamma value to be set.
 */
void Gamma::setGamma(double newGamma)
{
    this->gamma = newGamma;
}

/**
 * Applies gamma correction to the source image and stores the result in the destination image.
 * Gamma correction is a non-linear adjustment to the image's brightness values.
 *
 * @param src The source image to be processed.
 * @param dst The destination image where the processed result will be stored.
 */
void Gamma::process(const Image &src, Image &dst)
{
    dst = src;
    for (int i = 0; i < dst.getHeight(); ++i)
    {
        for (int j = 0; j < dst.getWidth(); ++j)
        {
            int newValue = pow(dst.at(i, j), this->gamma);
            if (newValue > 255)
                newValue = 255;
            else if (newValue < 0)
                newValue = 0;
            dst.setPixel(i, j, newValue);
        }
    }
}