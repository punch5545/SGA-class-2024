#include "pch.h"
#include "EventArgs.h"
#include "Control.h"

Form::Control::Control()
{
}

Form::Control::Control(Coordinate position, bool enabled, bool visible)
	:Position(position), Enabled(enabled), Visible(visible)
{
}
