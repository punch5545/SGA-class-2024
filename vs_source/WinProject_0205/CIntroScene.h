#pragma once
#include "IScene.h"
#include "CSprite.h"
#include <vector>

class CImageFile;

class CIntroScene : public IScene
{
public:
    CIntroScene();
    ~CIntroScene();

    virtual bool isFinished() override;
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;

public:
    CImageFile* mLionFile;
    CSprite     mBG;

    std::vector<LPCWSTR> strList = {
        L"-아-아-! 으~! ···괴, 괴롭다~!",
        L"내 혼에 열을 불어넣지 않으면",
        L"이 몸은 곧 사라져 버릴텐데···",
        L"···오! 북쪽에서 열기가 느껴 지는군!",
        L"서둘러야겠다. 열기를 따라 내 혼을 북쪽으로···!"
    };

    HFONT font;
    HFONT oldfont;

    float timeDelta = 0.0f;

    int current_x;
    int current_y;

    int dest_x;
    int dest_y;
};

