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
        L"-��-��-! ��~! ��������, ���Ӵ�~!",
        L"�� ȥ�� ���� �Ҿ���� ������",
        L"�� ���� �� ����� �����ٵ�������",
        L"��������! ���ʿ��� ���Ⱑ ���� ���±�!",
        L"���ѷ��߰ڴ�. ���⸦ ���� �� ȥ�� �������Ρ�����!"
    };

    HFONT font;
    HFONT oldfont;

    float timeDelta = 0.0f;

    int current_x;
    int current_y;

    int dest_x;
    int dest_y;
};

