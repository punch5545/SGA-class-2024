#pragma once
#include "CScene.h"
#include "CSprite.h"
#include "CString.h"
//#include "CImageFile.h"
class CImageFile;


class CIntroScene :
    public CScene
{
public:
    CIntroScene();
    ~CIntroScene();

    bool isChanged() override;
    void onFrameMove() override;
    void onDraw(HDC hdc) override;

public:
    CImageFile* mLionFile;
    CSprite     mLionSprite;
    CString*    mString;

    int mIntroTime;
};

