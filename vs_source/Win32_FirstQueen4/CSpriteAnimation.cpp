#include "pch.h"
#include "CSpriteAnimation.h"

CSpriteAnimation::~CSpriteAnimation()
{
	//for (auto& anim : mFrameAnims)
	//{
	//	delete anim;
	//}
}

void CSpriteAnimation::CreateSample()
{

	int w = 260 * 0.25;
	int h = 200 * 0.25;
	
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			FrameAnim* fa = new FrameAnim();
			fa->Frames.push_back(Frame(w * x, h * y, w, h));
			fa->Keys.push_back(AnimKeys(x + y, 500));

			fa->Name = L"Character";
			mFrameAnims.push_back(fa);
		}
	}

	mFrameAnims[0]->Name = L"CharacterF";
	mFrameAnims[1]->Name = L"CharacterL";
	mFrameAnims[2]->Name = L"CharacterR";
	mFrameAnims[3]->Name = L"CharacterB";

}

FrameAnim* CSpriteAnimation::Find(std::wstring& name)
{
	for (auto& anim : mFrameAnims)
	{
		if (anim->Name == name)
		{
			return anim;
		}
	}
}

CSpriteAnimation::CSpriteAnimation()
{
	mFrameAnims.clear();
}

void CFrameSprite::Set(std::wstring& name, int dx, int dy, CImageFile* img, UINT color, TDrawType dt)
{
	__super::Set(dx, dy, 0, 0, img, color, dt);

	mCurrentFA = mAnim->Find(name);

	AnimKeys key = mCurrentFA->Keys[0];

	mAnimInst.KeyFrameIdx = 0;
	mAnimInst.CurrentTime = 0;
	mAnimInst.DelayTime = key.Delay;
	mAnimInst.CurrentFrame = mCurrentFA->Frames[key.Idx];
}

void CFrameSprite::Update(int dt)
{
	mAnimInst.CurrentTime += dt;
	mAnimInst.DelayTime -= dt;

	mCurrentFA->UpdateInstance(mAnimInst);

	mSrcX	   = mAnimInst.CurrentFrame.X;
	mSrcY	   = mAnimInst.CurrentFrame.Y;
	mSrcWidth  = mAnimInst.CurrentFrame.Width;
	mSrcHeight = mAnimInst.CurrentFrame.Height;
}

void FrameAnim::UpdateInstance(FrameAnimInstance& inst)
{
	if (inst.DelayTime > 0) return;

	inst.KeyFrameIdx++;
	if (inst.KeyFrameIdx >= Keys.size()) inst.KeyFrameIdx = 0;
}
