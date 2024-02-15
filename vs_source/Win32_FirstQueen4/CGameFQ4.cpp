#include "pch.h"
#include "CGameFQ4.h"
#include "CIntroScene.h"
#include "CTitleScene.h"
#include "CLobbyScene.h"
#include "SceneManager.h"
#include "Resource.h"

#include <vector>

void CGameFQ4::onCreate()
{
	CIntroScene* mIntroScene = new CIntroScene(MAKEINTRESOURCE(IDB_INTRO1), {
	   L"-아-아-! 으~! ···괴, 괴롭다~!",
	   L"내 혼에 열을 불어넣지 않으면",
	   L"이 몸은 곧 사라져 버릴텐데···",
	   L"···오! 북쪽에서 열기가 느껴 지는군!",
	   L"서둘러야겠다. 열기를 따라 내 혼을 북쪽으로···!"
	});
	mIntroScene->setTextCoordinate(WINDOW_INTERNAL_CENTER_X, (WINDOW_INTERNAL_CENTER_Y) + 80);
	mCurrent = mIntroScene;


	mIntroScene = new CIntroScene(MAKEINTRESOURCE(IDB_INTRO2), {
	   L"옛날에 로그리스는 천지의 영혼들이 다스렸다.",
	   L"그러나 인간들이 들어오게 되자,",
	   L"원래 주인이던 영혼들은 차츰 몸을 숨겼다."
	});
	mIntroScene->setTextCoordinate(WINDOW_INTERNAL_CENTER_X, (WINDOW_INTERNAL_CENTER_Y)-20);
	SceneManager::Manager->SceneList.push_back(mIntroScene);


	mIntroScene = new CIntroScene(MAKEINTRESOURCE(IDB_INTRO3), {
		L"영토를 둘러싼 사람들의 분쟁은 끊이지 않았으나",
		L"서로 협력하고 자제하며 평화를 지켜가고 있었다."
	});
	mIntroScene->setTextCoordinate(WINDOW_INTERNAL_CENTER_X, (WINDOW_INTERNAL_CENTER_Y)-40);

	SceneManager::Manager->SceneList.push_back(mIntroScene);


	mIntroScene = new CIntroScene(MAKEINTRESOURCE(IDB_INTRO4), {
	   L"그리고 이 모든 나라를 통합하는 대표로서",
	   L"바르시아의 왕 [제넬루]가 뽑혔다.",
	   L" ",
	   L"바르시아는 로그리스 중앙과 북쪽에",
	   L"거대한 영토를 가진 대국이었다."
	});
	mIntroScene->setTextCoordinate(WINDOW_INTERNAL_CENTER_X, (WINDOW_INTERNAL_CENTER_Y)+80);
	SceneManager::Manager->SceneList.push_back(mIntroScene);

	mIntroScene = new CIntroScene(MAKEINTRESOURCE(IDB_INTRO5), {
		L"그러나 나라 면적에 비해 인구가 부족해",
		L"늘 침략의 위험이 도사리고 있었다.",
		L" ",
		L"하지만 제넬루는 마법을 이용해 강한 성과 요새를 ",
		L"여러 곳에 쌓고 영토를 단단히 지켰다."
	});
	mIntroScene->setTextCoordinate(WINDOW_INTERNAL_CENTER_X, (WINDOW_INTERNAL_CENTER_Y)-40);
	SceneManager::Manager->SceneList.push_back(mIntroScene);

	mIntroScene = new CIntroScene(MAKEINTRESOURCE(IDB_INTRO6), {
	   L"그런 제넬루 왕의 태도가 돌변한 것은 대륙에서 건너온",
	   L"마법사 [자닐]이 참모가 되고부터 였다.",
	   L" ",
	   L"어느새 [바르시아]의 병사는 급격히 늘어났다."
		});
	mIntroScene->setTextCoordinate(WINDOW_INTERNAL_CENTER_X, (WINDOW_INTERNAL_CENTER_Y)+80);
	SceneManager::Manager->SceneList.push_back(mIntroScene);

	mIntroScene = new CIntroScene(MAKEINTRESOURCE(IDB_INTRO7), {
	   L"바르시아의 주민은 주변국가로 탈출하기 시작했다.",
	   L"그들은 외쳤다.",
	   L"\"왕은 악마에게 마음을 팔아 변해 버렸다!\" 라고···"
	});
	mIntroScene->setTextCoordinate(WINDOW_INTERNAL_CENTER_X, (WINDOW_INTERNAL_CENTER_Y)+80);
	SceneManager::Manager->SceneList.push_back(mIntroScene);

	mIntroScene = new CIntroScene(MAKEINTRESOURCE(IDB_INTRO8), {
	   L"바르시아 성에서는 음침한 소리가 퍼지고",
	   L"그 소리는 살아 있는 것들을 미치게 했다.",
	   L" ",
	   L"제넬루는 사람들을 뒤에서 조종하고,",
	   L"마법의 힘으로 병사를 만들어 내는 데 성공했다."
	});
	mIntroScene->setTextCoordinate(WINDOW_INTERNAL_CENTER_X, (WINDOW_INTERNAL_CENTER_Y)-40);
	SceneManager::Manager->SceneList.push_back(mIntroScene);

	mIntroScene = new CIntroScene(MAKEINTRESOURCE(IDB_BLACK), {
	   L"각 영주들은 서둘러 영토를 지키는데······"
	});
	mIntroScene->setTextCoordinate(WINDOW_INTERNAL_CENTER_X, WINDOW_INTERNAL_CENTER_Y);
	SceneManager::Manager->SceneList.push_back(mIntroScene);

	CTitleScene* titleScene = new CTitleScene();
	SceneManager::Manager->SceneList.push_back(titleScene);

	CLobbyScene* lobby = new CLobbyScene();
	SceneManager::Manager->SceneList.push_back(lobby);
}

void CGameFQ4::onDestroy()
{
	// OutputDebugString(L"Game Destroyed\n");
	for(auto& scene : SceneManager::Manager->SceneList)
		delete scene;

	SceneManager::Manager->SceneList.clear();
}

void CGameFQ4::onFrameMove()
{
	// OutputDebugString(L"Game Frame Moved\n");
	__super::onFrameMove();
}

void CGameFQ4::onDraw(HDC hdc)
{
	// OutputDebugString(L"Game Drawed\n");
	__super::onDraw(hdc);
}
