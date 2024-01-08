#include "stdafx.h"
#include "06_Constructor.h"

void Constructor()
{
	Sample* sample1 = new Sample();
	Sample* sample2 = new Sample("ö��", 2);
	Sample* sample3 = new Sample(*sample2);
	Sample* sample4 = move(sample3);

	delete(sample4);
	delete(sample2);
	delete(sample1);
}

Sample::Sample()
	: name("ȫ�浿"), number(0)
{
	cout << "�⺻������ ȣ��" << endl;
	cout << "name: " << name << endl;
	cout << "number: " << number << endl;
}

Sample::Sample(string name, int number)
	: name(name), number(number)
{
	cout << "�Ű����� ������ ȣ��" << endl;
	cout << "name: " << name << endl;
	cout << "number: " << number << endl;
}

Sample::Sample(const Sample& other)
{
	name = other.name;
	number = other.number;

	cout << "���� ������ ȣ��" << endl;
	cout << "name: " << name << endl;
	cout << "number: " << number << endl;
}

Sample::Sample(Sample&& other)
{
	cout << "�̵� ������ ȣ��" << endl;

	name = move(other.name);
	number = move(other.number);
	// move�� ���� rvalue�� ��ȯ�� ��. �̵�X

	cout << "name: " << name << endl;
	cout << "number: " << number << endl;
}

Sample::~Sample()
{
	cout << this << endl;
}