#pragma once
#include "ImageProcessing.h"

class ImageConvolution : public ImageProcessing
{
private:
    int **kernel;                              /**< The convolution kernel */
    int w;                                     /**< The width of the kernel */
    int h;                                     /**< The height of the kernel */
    int (*scalingFunction)(int filteredValue); /**< The scaling function for post-processing */
public:
    /**
     * @brief Constructor.
     *
     * @param kernel The convolution kernel.
     * @param w The width of the kernel.
     * @param h The height of the kernel.
     * @param scalingFunction The scaling function for post-processing.
     */
    ImageConvolution(int **kernel, int w, int h, int (&scalingFunction)(int filteredValue));

    /**
     * @brief Destructor.
     */
    ~ImageConvolution();

    /**
     * @brief Applies the convolution kernel to the specified pixel in the source image.
     *
     * @param src The source image.
     * @param row The row index of the pixel.
     * @param col The column index of the pixel.
     * @return The filtered value after applying the kernel.
     */
    int applyKernel(const Image &src, int row, int col) const;

    /**
     * @brief Processes the source image by applying convolution.
     *
     * @param src The source image to be processed.
     * @param dst The resulting image after convolution.
     */
    void process(const Image &src, Image &dst) override;

    /**
     * @brief Static method for mean blur scaling.
     *
     * @param filteredValue The filtered value to be scaled.
     * @return The scaled value.
     */
    static int meanBlurScaling(int filteredValue);

    /**
     * @brief Static method for Gaussian blur scaling.
     *
     * @param filteredValue The filtered value to be scaled.
     * @return The scaled value.
     */
    static int gaussianBlurScaling(int filteredValue);

    /**
     * @brief Static method for horizontal Sobel scaling.
     *
     * @param filteredValue The filtered value to be scaled.
     * @return The scaled value.
     */
    static int horizontalSobelScaling(int filteredValue);

    /**
     * @brief Static method for vertical Sobel scaling.
     *
     * @param filteredValue The filtered value to be scaled.
     * @return The scaled value.
     */
    static int verticalSobelScaling(int filteredValue);
};