#pragma once
#include "ImageProcessing.h"

/**
 * @brief The BrightnessContrast class represents an image processing operation that adjusts the brightness and contrast of an image.
 */
class BrightnessContrast : public ImageProcessing
{

private:
    double gain; /**< The gain value for adjusting the image's brightness. */
    double bias; /**< The bias value for adjusting the image's contrast. */

public:
    /**
     * @brief Constructs a BrightnessContrast object with default gain and bias values.
     */
    BrightnessContrast();

    /**
     * @brief Constructs a BrightnessContrast object with the specified gain and bias values.
     * @param gain The gain value for adjusting the image's brightness.
     * @param bias The bias value for adjusting the image's contrast.
     */
    BrightnessContrast(double gain, double bias);

    /**
     * @brief Gets the gain value for adjusting the image's brightness.
     * @return The gain value.
     */
    double getGain() const;

    /**
     * @brief Gets the bias value for adjusting the image's contrast.
     * @return The bias value.
     */
    double getBias() const;

    /**
     * @brief Sets the gain value for adjusting the image's brightness.
     * @param gain The new gain value.
     */
    void setGain(double gain);

    /**
     * @brief Sets the bias value for adjusting the image's contrast.
     * @param bias The new bias value.
     */
    void setBias(double bias);

    /**
     * @brief Applies the brightness and contrast adjustment to the source image and stores the result in the destination image.
     * @param src The source image.
     * @param dst The destination image.
     */
    void process(const Image &src, Image &dst) override;
};