#pragma once
#include "IScene.h"
#include "CSprite.h"



class CLobbyScene : public IScene
{
public:
    CLobbyScene();
    ~CLobbyScene();

    virtual bool isFinished() override;
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;

public:
    CImageFile*             mImageFile;
    CImageFile*             mSelectImageFile;
    CSprite                 mBG;
    std::vector<CSprite>    mSelectBGs;

    struct SaveFile
    {
        LPCWSTR path;
        LPCWSTR saveName;
        int playTime;

        SaveFile(LPCWSTR path, LPCWSTR saveName, int playTime) : path(path), saveName(saveName), playTime(playTime) {}
    };

    HFONT mFont;

    std::vector<SaveFile> saveFiles;

    int sleepTime = 1;
    float timeDelta = 0.0f;
    bool goNext = false;
    bool showText = false;
};

