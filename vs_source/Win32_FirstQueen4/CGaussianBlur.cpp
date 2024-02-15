#include "pch.h"
#include "CGaussianBlur.h"

UINT32* CGaussianBlur::Execute()
{

    UINT32* Pixel = new UINT32[imgHeight * imgWidth];
    //Pixel = mPixel;

    for (int y = 0; y < imgHeight; y++) {
        for (int x = 0; x < imgWidth; x++) {
            float sum = 0.0f;
            float weightSum = 0.0f;
            for (int k = -1*(mBlurSize / 2); k <= mBlurSize / 2; k++) {
                int currentX = min(max(x + k, 0), imgWidth - 1);

                sum += mPixel[y * imgWidth + currentX] * kernel[k + mBlurSize / 2];
                weightSum += kernel[k + mBlurSize / 2];
            }
            Pixel[y * imgWidth + x] = static_cast<UINT32>(sum / weightSum);
        }
    }

    for (int x = 0; x < imgWidth; x++) {
        for (int y = 0; y < imgHeight; y++) {
            float sum = 0.0f;
            float weightSum = 0.0f;
            for (int k = -1 * (mBlurSize / 2); k <= mBlurSize / 2; k++) {
                int currentY = min(max(y + k, 0), imgHeight - 1);
                //int currentY = y + k < 0 ? 0 : y + k;
                //currentY = currentY > imgHeight - 1 ? imgHeight - 1 : currentY;
                sum += mPixel[currentY * imgWidth + x] * kernel[k + mBlurSize / 2];
                weightSum += kernel[k + mBlurSize / 2];
            }
            Pixel[y * imgWidth + x] = static_cast<UINT32>(sum / weightSum);
        }
    }


    return Pixel;
}
