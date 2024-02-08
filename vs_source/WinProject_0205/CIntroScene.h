#pragma once
#include "IScene.h"
#include "CSprite.h"
#include <vector>

class CImageFile;

class CIntroScene : public IScene
{
public:
    CIntroScene(const WCHAR* ResourceFilename, std::vector<LPCWSTR> strList);
    ~CIntroScene();

    virtual bool isFinished() override;
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;

    void setTextCoordinate(int x, int y)
    {
        TEXT_X = x;
        TEXT_Y = y;

        OUTLINE_X = x + 1;
        OUTLINE_Y = y + 1;
    }

public:
    CImageFile* mLionFile;
    CSprite     mBG;

    std::vector<LPCWSTR> strList;

    HFONT mFont;

    int sleepTime = 1;
    float timeDelta = 0.0f;
    bool goNext = false;
    bool showText = true;

    int TEXT_X;
    int TEXT_Y;
    int OUTLINE_X;
    int OUTLINE_Y;

    int current_x;
    int current_y;

    int dest_x;
    int dest_y;
};

