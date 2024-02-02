#include "pch.h"
#include "EventArgs.h"
#include "Control.h"

Form::MainForm* Form::MainForm::mainFrm = NULL;

Form::MainForm::MainForm()
{
	mainHandle = NULL;
	mainFrm = this;
}

Form::MainForm::MainForm(HWND mainHandle)
	:mainHandle(mainHandle)
{
	mainFrm = this;
}

Form::MainForm::~MainForm()
{
}


bool Form::MainForm::SetHandle(HWND handle)
{
	if (mainHandle != NULL) return false;

	mainHandle = handle;

}

HWND Form::MainForm::GetHandle()
{
	return mainHandle;
}


Form::Control::Control()
{
	this->Position = { 0, 0, 0, 0 };
	this->Enabled = false;
	this->Visible = false;
	this->mHandle = NULL;

}

HWND Form::Control::GetHandle()
{
	return this->mHandle;
}

Form::Control::Control(LPCWSTR ClassName, LPCWSTR Text, Coordinate position, bool enabled, bool visible)
	:ClassName(ClassName), Text(Text), Position(position), Enabled(enabled), Visible(visible), mHandle(NULL)
{
	this->mHandle = NULL;
}

