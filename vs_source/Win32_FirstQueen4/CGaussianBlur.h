#pragma once
#include "IShader.h"
#include <vector>

class CGaussianBlur :
    public IShader
{
public:
    CGaussianBlur(HBITMAP hBitmap, UINT32* Color, int imgWidth, int imgHeight , UINT BlurSze)
        :IShader(hBitmap, Color, imgWidth, imgHeight), mBlurSize(BlurSze)
    {
        kernel = this->GenerateGaussianKernel1D(BlurSze, 1);
    }
public:
    UINT mBlurSize;

public:
    virtual UINT32* Execute() override;

private:
    double M_PI = 3.1415926525;
    std::vector<float> GenerateGaussianKernel1D(UINT blurSize, float sigma) {
        std::vector<float> kernel(blurSize);
        float sum = 0.0f;
        int halfSize = blurSize / 2;
        for (int i = -1*halfSize; i <= halfSize; i++) {
            float value = exp(-(i * i) / (2 * sigma * sigma)) / (sqrt(2 * M_PI) * sigma);
            kernel[i + halfSize] = value;
            sum += value;
        }
        // 커널 정규화
        for (auto& val : kernel) val /= sum;
        return kernel;
    }

    std::vector<float> kernel;
};

