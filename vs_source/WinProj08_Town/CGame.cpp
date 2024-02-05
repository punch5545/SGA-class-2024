#include "pch.h"
#include "CIntroScene.h"
#include "CTownScene.h"
#include "CGame.h"
#include "CApplication.h"

void CGame::onCreate()
{
    mIntroScene = new CIntroScene();
    mTownScene = new CTownScene;

    mCurrent = mIntroScene;
}

void CGame::onFrameMove()
{
    mCurrent->onFrameMove();

    if (mCurrent->isChanged()) {
        if (mCurrent == mIntroScene) {
            mCurrent = mTownScene;
            mTownScene->mTownTime = 50;
            CApplication::theApp->ȭ�鰻��();
        }
        else if (mCurrent == mTownScene) {
            mCurrent = mIntroScene;
            mIntroScene->mIntroTime = 50;
            CApplication::theApp->ȭ�鰻��();
        }

    }
}

void CGame::onDestroy()
{
    delete mIntroScene;
    delete mTownScene;
}

void CGame::onDraw(HDC hdc)
{
    mCurrent->onDraw(hdc);
}
