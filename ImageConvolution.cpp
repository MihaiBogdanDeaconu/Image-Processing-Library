#include <iostream>
#include "ImageConvolution.h"

/**
 * @brief Constructor.
 *
 * @param kernel The convolution kernel.
 * @param w The width of the kernel.
 * @param h The height of the kernel.
 * @param scalingFunction The scaling function for post-processing.
 */
ImageConvolution::ImageConvolution(int **kernel, int w, int h, int (&scalingFunction)(int filteredValue))
{
    this->w = w;
    this->h = h;
    this->kernel = new int *[h];
    for (int i = 0; i < h; ++i)
    {
        this->kernel[i] = new int[w];
        for (int j = 0; j < w; ++j)
            this->kernel[i][j] = kernel[i][j];
    }
    this->scalingFunction = scalingFunction;
}

/**
 * @brief Destructor.
 */
ImageConvolution::~ImageConvolution()
{
    for (int i = 0; i < this->h; ++i)
    {
        delete[] this->kernel[i];
    }
    delete[] this->kernel;
    this->kernel = nullptr;
}

/**
 * Calculates the scaled value of a filtered pixel using mean blur scaling.
 *
 * @param filteredValue The filtered value of the pixel.
 * @return The scaled value of the pixel.
 */
int ImageConvolution::meanBlurScaling(int filteredValue)
{
    int scaledValue = filteredValue / 9;
    if (scaledValue > 255)
        scaledValue = 255;
    else if (scaledValue < 0)
        scaledValue = 0;
    return scaledValue;
}

/**
 * Scales the filtered value obtained from Gaussian blur operation.
 *
 * @param filteredValue The filtered value to be scaled.
 * @return The scaled value.
 */
int ImageConvolution::gaussianBlurScaling(int filteredValue)
{
    int scaledValue = filteredValue / 16;
    if (scaledValue > 255)
        scaledValue = 255;
    else if (scaledValue < 0)
        scaledValue = 0;
    return scaledValue;
}

/**
 * Applies horizontal Sobel scaling to the filtered value.
 *
 * @param filteredValue The filtered value to be scaled.
 * @return The scaled value after applying horizontal Sobel scaling.
 */
int ImageConvolution::horizontalSobelScaling(int filteredValue)
{
    double normalizedValue = (filteredValue + 4 * 255) / (8.0 * 255);
    double scaledValue = normalizedValue * 255;

    if (scaledValue < 0)
    {
        return 0;
    }
    else if (scaledValue > 255)
    {
        return 255;
    }
    else
    {
        return static_cast<int>(scaledValue);
    }
}

/**
 * Scales the filtered value obtained from vertical Sobel convolution.
 *
 * @param filteredValue The filtered value obtained from vertical Sobel convolution.
 * @return The scaled value.
 */
int ImageConvolution::verticalSobelScaling(int filteredValue)
{
    double normalizedValue = (filteredValue + 4 * 255) / (8.0 * 255);
    double scaledValue = normalizedValue * 255;

    if (scaledValue < 0)
    {
        return 0;
    }
    else if (scaledValue > 255)
    {
        return 255;
    }
    else
    {
        return static_cast<int>(scaledValue);
    }
}

/**
 * Applies convolution operation on the source image and stores the result in the destination image.
 *
 * @param src The source image on which the convolution operation is applied.
 * @param dst The destination image where the result of the convolution operation is stored.
 */
void ImageConvolution::process(const Image &src, Image &dst)
{
    int outputW = src.getWidth() - (src.getWidth() % this->w);
    int outputH = src.getHeight() - (src.getHeight() % this->h);
    Image output(outputW, outputH);

    int paddingW = this->w / 2;
    int paddingH = this->h / 2;

    for (int i = paddingH; i < outputH - paddingH; ++i)
    {
        for (int j = paddingW; j < outputW - paddingW; ++j)
        {
            int filteredValue = applyKernel(src, i, j);
            output.setPixel(i, j, this->scalingFunction(filteredValue));
        }
    }
    dst = output;
}

/**
 * Applies the convolution kernel to the specified pixel in the source image.
 *
 * @param src The source image.
 * @param row The row index of the pixel.
 * @param col The column index of the pixel.
 * @return The filtered value after applying the convolution kernel.
 */
int ImageConvolution::applyKernel(const Image &src, int row, int col) const
{
    int filteredValue = 0;
    int paddingW = this->w / 2;
    int paddingH = this->h / 2;

    for (int i = -paddingH; i <= paddingH; ++i)
    {
        for (int j = -paddingW; j <= paddingW; ++j)
        {
            filteredValue += src.at(row + i, col + j) * this->kernel[i + paddingH][j + paddingW];
        }
    }
    return filteredValue;
}