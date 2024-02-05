#pragma once

class IScene
{
public:
    virtual bool isFinished() = 0;
    virtual void onFrameMove() = 0;
    virtual void onDraw(HDC hdc) = 0;
};

