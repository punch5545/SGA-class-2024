#include "stdafx.h"
#include "08_Inheritance.h"

Life::Life(float energy, string name)
	:energy(energy), name(name)
{
	cout << "Life::持失切" << endl;
}

Life::~Life()
{
	cout << "Life::社瑚切" << endl;
}

void Animal::AddEnergy(float energy)
{
	this->energy += energy;

	cout << "Animal::AddEnergy() : " << this->energy << endl;
}

void Animal::PrintName()
{
	cout << "Animal::PrintName() : " << this->name << endl;
}

void Life::PrintName()
{
	cout << "Life::PrintName() : " << this->name << endl;
}

Animal::Animal(float energy, string name, float moveSpeed)
	:Life(energy, name), moveSpeed(moveSpeed)
{
	cout << "Animal::持失切" << endl;
}

Animal::~Animal()
{
	cout << "Animal::社瑚切" << endl;
}

void Animal::Eat()
{
	
	AddEnergy(2.0f);
}

Vehicle::Vehicle(string name, int weight)
	:name(name), weight(weight)
{
}

Vehicle::~Vehicle()
{
}


OnTheGround::OnTheGround(string name, int weight, float speed)
	:Vehicle(name, weight), speed(speed)
{

}

OnTheGround::~OnTheGround()
{
}

string OnTheGround::GetSound()
{
	return this->sound;

}

void OnTheGround::SetSound(string sound)
{
	this->sound = sound;
}

float OnTheGround::GetSpeed()
{
	return this->speed;
}

void OnTheGround::AddSpeed(float speed)
{
	this->speed += speed;
}
