#pragma once

void Constructor();

class Sample
{
public:
	Sample();
	Sample(string name, int number);
	Sample(const Sample& other);
	Sample(Sample&& other);

	~Sample();
private:
	string name;
	int number;
};