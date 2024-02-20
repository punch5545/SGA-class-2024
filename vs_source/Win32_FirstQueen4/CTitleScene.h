#pragma once
#include "IScene.h"
#include "CSprite.h"


class CTitleScene :
    public IScene
{
public:
    CTitleScene();
    ~CTitleScene();

    virtual bool isFinished() override;
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;


public:
    CImageFile* mTitleFile;
    CSprite     mBG;


    HFONT mFont;

    int sleepTime = 1;
    float timeDelta = 0.0f;
    bool goNext = false;
    bool showText = false;
};