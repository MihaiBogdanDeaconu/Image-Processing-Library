#pragma once
#include "Image.h"

/**
 * @brief The ImageProcessing class is an abstract base class that defines the interface for image processing operations.
 */
class ImageProcessing
{
public:
    /**
     * @brief This pure virtual function is used to process the source image and store the result in the destination image.
     *
     * @param src The source image to be processed.
     * @param dst The destination image where the processed result will be stored.
     */
    virtual void process(const Image &src, Image &dst) = 0;
};