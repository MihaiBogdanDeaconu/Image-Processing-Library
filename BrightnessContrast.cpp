#include "BrightnessContrast.h"
#include "Image.h"
#include <iostream>

/**
 * @brief Default constructor for the BrightnessContrast class.
 *
 * This constructor initializes the gain and bias values to their default values.
 * The gain controls the contrast of the image, while the bias controls the brightness.
 *
 * @param None
 * @return None
 */
BrightnessContrast::BrightnessContrast() : gain{1}, bias{0} {}

/**
 * @brief Constructs a new BrightnessContrast object with the specified gain and bias.
 *
 * @param gain The gain value to be applied to the image pixels.
 * @param bias The bias value to be added to the image pixels.
 */
BrightnessContrast::BrightnessContrast(double gain, double bias)
{
    this->gain = gain;
    this->bias = bias;
}

/**
 * @brief Sets the gain value for adjusting the brightness.
 *
 * The gain value determines the amount of brightness adjustment to be applied.
 * A positive gain value increases the brightness, while a negative gain value decreases it.
 *
 * @param gain The gain value to be set. Should be positive.
 */
void BrightnessContrast::setGain(double gain)
{
    if (gain > 0)
        this->gain = gain;
    else
        std::cerr << "Gain should be positive!";
}

/**
 * @brief Get the gain value of the BrightnessContrast object.
 *
 * @return The gain value.
 */
double BrightnessContrast::getGain() const
{
    return this->gain;
}

/**
 * @brief Sets the bias value for adjusting the brightness and contrast.
 *
 * The bias value is used to adjust the brightness and contrast of an image.
 * A positive bias value increases the brightness and contrast, while a negative
 * bias value decreases them.
 *
 * @param bias The bias value to set.
 */
void BrightnessContrast::setBias(double bias)
{
    this->bias = bias;
}

/**
 * @brief Get the bias value of the BrightnessContrast object.
 *
 * @return The bias value.
 */
double BrightnessContrast::getBias() const
{
    return this->bias;
}

/**
 * Applies brightness and contrast adjustments to the source image and stores the result in the destination image.
 *
 * @param src The source image to be processed.
 * @param dst The destination image where the processed image will be stored.
 */
void BrightnessContrast::process(const Image &src, Image &dst)
{
    dst = src;
    dst = dst * gain;
    for (int i = 0; i < dst.getHeight(); ++i)
    {
        for (int j = 0; j < dst.getWidth(); ++j)
        {
            dst.setPixel(i, j, dst.at(i, j) + bias);
        }
    }
}
