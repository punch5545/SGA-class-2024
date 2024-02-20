#pragma once
#include "CSprite.h"

struct Frame
{
	Frame() : X(0), Y(0), Width(0), Height(0) {}
	Frame(int x, int y, int width, int height) : X(x), Y(y), Width(width), Height(height) {}
	int X;
	int Y;
	int Width;
	int Height;
};

struct AnimKeys
{
	AnimKeys() : Idx(0), Delay(0) {}
	AnimKeys(int idx, int delay) : Idx(idx), Delay(delay) {}
	int Idx;
	int Delay;
};

struct FrameAnimInstance
{
	Frame CurrentFrame;

	int CurrentTime;
	int DelayTime;
	int KeyFrameIdx;
};

struct FrameAnim
{
	std::wstring Name;
	std::vector<AnimKeys> Keys;
	std::vector<Frame> Frames;

	void UpdateInstance(FrameAnimInstance& inst);
};

class CSpriteAnimation
{

public:
	CSpriteAnimation();
	~CSpriteAnimation();
	void CreateSample();
	FrameAnim* Find(std::wstring& name);

public:
	std::vector<FrameAnim*> mFrameAnims;
};

struct AnimFile
{
	CImageFile* ImgFile;
	CSpriteAnimation* Anim;
};

class CFrameSprite: public CSprite
{
public:
	CSpriteAnimation* mAnim;
	FrameAnim* mCurrentFA;

	FrameAnimInstance mAnimInst;

	void Set(std::wstring& name, int dx, int dy, CImageFile* img, UINT color, TDrawType dt);
	void Update(int dt);
};