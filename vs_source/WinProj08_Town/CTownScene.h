#pragma once
#include "CSprite.h"
#include "CScene.h"

class CImageFile;

class CTownScene : public CScene
{
public:
    CTownScene();
    ~CTownScene();

    bool isChanged() override;
    void onFrameMove() override;
    void onDraw(HDC hdc) override;

public:
    CImageFile* mBackG;
    CImageFile* mTreeFile;

    CSprite  mBG;
    CSprite  mTrees[50];

    int mTownTime;
};

