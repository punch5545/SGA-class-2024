#pragma once
#include "IScene.h"
#include "CSprite.h"
#include <vector>
#include <map>

class CLobbyScene : public IScene
{
public:
    CLobbyScene();
    ~CLobbyScene();

    virtual bool isFinished() override;
    virtual void onFrameMove() override;
    virtual void onDraw(HDC hdc) override;

public:
    CImageFile* mImageFile;
    CSprite     mBG;

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

