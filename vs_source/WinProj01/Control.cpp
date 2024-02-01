#include "pch.h"
#include "EventArgs.h"
#include "Control.h"

Form::Control::Control()
{
	this->Position = { 0, 0, 0, 0 };
	this->Enabled = false;
	this->Visible = false;
}

Form::Control::Control(Coordinate position, bool enabled, bool visible)
	:Position(position), Enabled(enabled), Visible(visible)
{
}
