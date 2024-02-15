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
	   L"-��-��-! ��~! ��������, ���Ӵ�~!",
	   L"�� ȥ�� ���� �Ҿ���� ������",
	   L"�� ���� �� ����� �����ٵ�������",
	   L"��������! ���ʿ��� ���Ⱑ ���� ���±�!",
	   L"���ѷ��߰ڴ�. ���⸦ ���� �� ȥ�� �������Ρ�����!"
	});
	mIntroScene->setTextCoordinate(WINDOW_INTERNAL_CENTER_X, (WINDOW_INTERNAL_CENTER_Y) + 80);
	mCurrent = mIntroScene;


	mIntroScene = new CIntroScene(MAKEINTRESOURCE(IDB_INTRO2), {
	   L"������ �α׸����� õ���� ��ȥ���� �ٽ��ȴ�.",
	   L"�׷��� �ΰ����� ������ ����,",
	   L"���� �����̴� ��ȥ���� ���� ���� �����."
	});
	mIntroScene->setTextCoordinate(WINDOW_INTERNAL_CENTER_X, (WINDOW_INTERNAL_CENTER_Y)-20);
	SceneManager::Manager->SceneList.push_back(mIntroScene);


	mIntroScene = new CIntroScene(MAKEINTRESOURCE(IDB_INTRO3), {
		L"���並 �ѷ��� ������� ������ ������ �ʾ�����",
		L"���� �����ϰ� �����ϸ� ��ȭ�� ���Ѱ��� �־���."
	});
	mIntroScene->setTextCoordinate(WINDOW_INTERNAL_CENTER_X, (WINDOW_INTERNAL_CENTER_Y)-40);

	SceneManager::Manager->SceneList.push_back(mIntroScene);


	mIntroScene = new CIntroScene(MAKEINTRESOURCE(IDB_INTRO4), {
	   L"�׸��� �� ��� ���� �����ϴ� ��ǥ�μ�",
	   L"�ٸ��þ��� �� [���ڷ�]�� ������.",
	   L" ",
	   L"�ٸ��þƴ� �α׸��� �߾Ӱ� ���ʿ�",
	   L"�Ŵ��� ���並 ���� �뱹�̾���."
	});
	mIntroScene->setTextCoordinate(WINDOW_INTERNAL_CENTER_X, (WINDOW_INTERNAL_CENTER_Y)+80);
	SceneManager::Manager->SceneList.push_back(mIntroScene);

	mIntroScene = new CIntroScene(MAKEINTRESOURCE(IDB_INTRO5), {
		L"�׷��� ���� ������ ���� �α��� ������",
		L"�� ħ���� ������ ���縮�� �־���.",
		L" ",
		L"������ ���ڷ�� ������ �̿��� ���� ���� ����� ",
		L"���� ���� �װ� ���並 �ܴ��� ���״�."
	});
	mIntroScene->setTextCoordinate(WINDOW_INTERNAL_CENTER_X, (WINDOW_INTERNAL_CENTER_Y)-40);
	SceneManager::Manager->SceneList.push_back(mIntroScene);

	mIntroScene = new CIntroScene(MAKEINTRESOURCE(IDB_INTRO6), {
	   L"�׷� ���ڷ� ���� �µ��� ������ ���� ������� �ǳʿ�",
	   L"������ [�ڴ�]�� ���� �ǰ���� ����.",
	   L" ",
	   L"����� [�ٸ��þ�]�� ����� �ް��� �þ��."
		});
	mIntroScene->setTextCoordinate(WINDOW_INTERNAL_CENTER_X, (WINDOW_INTERNAL_CENTER_Y)+80);
	SceneManager::Manager->SceneList.push_back(mIntroScene);

	mIntroScene = new CIntroScene(MAKEINTRESOURCE(IDB_INTRO7), {
	   L"�ٸ��þ��� �ֹ��� �ֺ������� Ż���ϱ� �����ߴ�.",
	   L"�׵��� ���ƴ�.",
	   L"\"���� �Ǹ����� ������ �Ⱦ� ���� ���ȴ�!\" �������"
	});
	mIntroScene->setTextCoordinate(WINDOW_INTERNAL_CENTER_X, (WINDOW_INTERNAL_CENTER_Y)+80);
	SceneManager::Manager->SceneList.push_back(mIntroScene);

	mIntroScene = new CIntroScene(MAKEINTRESOURCE(IDB_INTRO8), {
	   L"�ٸ��þ� �������� ��ħ�� �Ҹ��� ������",
	   L"�� �Ҹ��� ��� �ִ� �͵��� ��ġ�� �ߴ�.",
	   L" ",
	   L"���ڷ�� ������� �ڿ��� �����ϰ�,",
	   L"������ ������ ���縦 ����� ���� �� �����ߴ�."
	});
	mIntroScene->setTextCoordinate(WINDOW_INTERNAL_CENTER_X, (WINDOW_INTERNAL_CENTER_Y)-40);
	SceneManager::Manager->SceneList.push_back(mIntroScene);

	mIntroScene = new CIntroScene(MAKEINTRESOURCE(IDB_BLACK), {
	   L"�� ���ֵ��� ���ѷ� ���並 ��Ű�µ�������������"
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
