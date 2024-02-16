#include "pch.h"
#include "CMainStoryScene.h"

#include "CImageFile.h"
#include "Resource.h"

CMainStoryScene::CMainStoryScene()
{
    mImages.insert(std::pair<std::string, CImageFile*>("바르시아성 왕실", new CImageFile(MAKEINTRESOURCE(IDB_CASTEL))));
    mImages.insert(std::pair<std::string, CImageFile*>("MB_SYS", new CImageFile(MAKEINTRESOURCE(IDB_MB_SYS))));
    mImages.insert(std::pair<std::string, CImageFile*>("MB_NPC", new CImageFile(MAKEINTRESOURCE(IDB_MB_NPC))));
    mImages.insert(std::pair<std::string, CImageFile*>("INTERFACE", new CImageFile(MAKEINTRESOURCE(IDB_INTERFACE))));


    for (auto& image : mImages)
    {
        mSprites.insert(std::pair<std::string, CSprite>(image.first, CSprite()));
        mSprites.end()->second.Set(0, 0, 0, 0, image.second, 0, CSprite::DrawType_AlphaBlend);
        mSprites.end()->second.mAlpha = 255;
    }
}

CMainStoryScene::~CMainStoryScene()
{
}

bool CMainStoryScene::isFinished()
{
    return false;
}

void CMainStoryScene::onFrameMove()
{
}

void CMainStoryScene::onDraw(HDC hdc)
{
    mSprites.find("바르시아성 왕실")->second.Draw(hdc);
}
