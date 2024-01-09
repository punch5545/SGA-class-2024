#pragma once

class Life
{

protected:
	float energy;
	string name;

public:
	Life(float energy, string name);
	~Life();

	virtual void AddEnergy(float energy) = 0;
	virtual void PrintName();

};


class Animal : public Life
{
	float moveSpeed;

public:
	Animal(float energy, string name, float moveSpeed);
	~Animal();

	virtual void AddEnergy(float energy) override;
	virtual void PrintName() override;

	void Eat();
};



class Vehicle
{
public:
	Vehicle(string name, int weight);
	virtual ~Vehicle();

	virtual string GetSound() = 0;
	virtual void SetSound(string sound) = 0;

protected:
	string name;
	string sound;

	int weight; 
};

class OnTheGround : public Vehicle
{
public:
	OnTheGround(string name, int weight, float speed);
	~OnTheGround();


	virtual string GetSound() override;
	virtual void SetSound(string sound) override;

	string GetName() { return this->name; }
	float GetSpeed();
	void AddSpeed(float speed);

private:
	float speed;
};