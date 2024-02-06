#pragma once
class IUserInterface
{
public:
	enum UIType
	{
		String,
		AnimatedString
	};

	IUserInterface(UIType type) : Type(type) {}
	
	virtual void Draw() = 0;

	UIType Type;
};

