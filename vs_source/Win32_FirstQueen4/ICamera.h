#pragma once
class ICamera
{
public:
	ICamera();
	~ICamera();

public:
	Vector3 mPosition;
	RectTransform mTransform;
};

