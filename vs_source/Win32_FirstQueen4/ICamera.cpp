#include "pch.h"
#include "ICamera.h"

ICamera::ICamera()
{
	this->mPosition = { 0, 0, 0 };
	this->mTransform = { 0, WINDOW_WIDTH, 0, WINDOW_HEIGHT };
}

ICamera::~ICamera()
{
}
