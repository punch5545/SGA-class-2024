#include "stdafx.h"
#include "06_Constructor.h"

void Constructor()
{
	Sample* sample1 = new Sample();
	Sample* sample2 = new Sample("철수", 2);
	Sample* sample3 = new Sample(*sample2);
	Sample* sample4 = move(sample3);

	delete(sample4);
	delete(sample2);
	delete(sample1);
}

Sample::Sample()
	: name("홍길동"), number(0)
{
	cout << "기본생성자 호출" << endl;
	cout << "name: " << name << endl;
	cout << "number: " << number << endl;
}

Sample::Sample(string name, int number)
	: name(name), number(number)
{
	cout << "매개변수 생성자 호출" << endl;
	cout << "name: " << name << endl;
	cout << "number: " << number << endl;
}

Sample::Sample(const Sample& other)
{
	name = other.name;
	number = other.number;

	cout << "복사 생성자 호출" << endl;
	cout << "name: " << name << endl;
	cout << "number: " << number << endl;
}

Sample::Sample(Sample&& other)
{
	cout << "이동 생성자 호출" << endl;

	name = move(other.name);
	number = move(other.number);
	// move는 값을 rvalue로 반환만 함. 이동X

	cout << "name: " << name << endl;
	cout << "number: " << number << endl;
}

Sample::~Sample()
{
	cout << this << endl;
}