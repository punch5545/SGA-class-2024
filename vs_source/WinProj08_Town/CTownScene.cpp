#include "pch.h"
#include "CImageFile.h"
#include "CTownScene.h"
#include "resource.h"
#include "CSprite.h"


CTownScene::CTownScene()
{
    mTownTime = 50;

    mBackG = new CImageFile(MAKEINTRESOURCE(IDB_TOWN));
    mTreeFile = new CImageFile(MAKEINTRESOURCE(IDB_TREE));

    mBG.Set(0, 0, 0, 0, mBackG, 0, CSprite::DrawType_Draw);

    mTrees[0].Set(10, -40, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[1].Set(50, -40, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[2].Set(10, 10, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[3].Set(50, 10, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[4].Set(10, 50, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[5].Set(50, 50, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[6].Set(10, 100, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[7].Set(50, 100, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[8].Set(100, 100, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[9].Set(150, 100, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[10].Set(10, 150, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[11].Set(50, 150, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[12].Set(100, 150, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[13].Set(150, 150, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[14].Set(10, 200, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[15].Set(50, 200, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[16].Set(100, 200, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[17].Set(150, 200, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[18].Set(50, 250, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[19].Set(100, 250, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[20].Set(150, 250, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[21].Set(50, 300, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[22].Set(100, 300, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[23].Set(150, 300, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[24].Set(500, -50, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[25].Set(450, -50, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[26].Set(500, 0, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[27].Set(450, 0, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[28].Set(500, 50, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[29].Set(450, 50, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[30].Set(490, 100, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[31].Set(440, 100, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[32].Set(390, 100, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[33].Set(340, 100, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[34].Set(490, 150, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[35].Set(440, 150, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[36].Set(390, 150, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[37].Set(340, 150, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[38].Set(490, 190, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[39].Set(440, 190, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[40].Set(390, 190, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[41].Set(340, 190, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[42].Set(465, 250, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[43].Set(420, 250, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[44].Set(380, 250, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[45].Set(340, 250, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[46].Set(465, 300, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[47].Set(420, 300, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[48].Set(380, 300, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
    mTrees[49].Set(340, 300, 0, 0, mTreeFile, RGB(255, 0, 255), CSprite::DrawType_Transparent);
}

CTownScene::~CTownScene()
{
    delete mBackG;
    delete mTreeFile;
}

bool CTownScene::isChanged()
{
    return (mTownTime <= 0);
}

void CTownScene::onFrameMove()
{
    --mTownTime;
}

void CTownScene::onDraw(HDC hdc)
{
    mBG.Draw(hdc);
    for (int i = 0; i < 50; ++i) mTrees[i].Draw(hdc);
}
