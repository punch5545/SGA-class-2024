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

    std::vector<LPCWSTR> strList;

    float timeDelta = 0.0f;

    int current_x;
    int current_y;

    int dest_x;
    int dest_y;
};

