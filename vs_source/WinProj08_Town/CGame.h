#pragma once

class CIntroScene;
class CTownScene;
class CScene;

class CGame
{
public:
    void onCreate();
    void onFrameMove();
    void onDestroy();
    void onDraw(HDC hdc);

public:
    CIntroScene* mIntroScene;
    CTownScene* mTownScene;
    CScene* mCurrent;
};

