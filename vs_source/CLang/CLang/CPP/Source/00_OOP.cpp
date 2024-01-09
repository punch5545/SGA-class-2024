#include "stdafx.h"
#include "00_OOP.h"
#include "06_Constructor.h"
#include "08_Inheritance.h"

int main()
{
	OnTheGround* car = new OnTheGround("�ƹݶ�", 1, 0.0f);

	car->SetSound("�θ��θ�");
	car->AddSpeed(60.0f);

	cout <<
		"Name  : " << car->GetName() << endl <<
		"Sound : " << car->GetSound() << endl <<
		"Speed : " << car->GetSpeed() << "km/h" << endl;

	delete(car);

	return 0;
}