#pragma once

class CScene
{
public:
    virtual bool isChanged() = 0;
    virtual void onFrameMove() = 0;
    virtual void onDraw(HDC hdc) = 0;
};

