#include "pch.h"
#include <iostream>
#include "Quiz_1.h"
//3
int main(void) {

	// Quiz 1
	std::string myName;
	int age = 0;

	std::cout << "�ڽ��� �̸� : ";
	std::cin >> myName;

	std::cout << "�ڽ��� ���� : ";
	std::cin >> age;

	std::cout << "���� �̸��� " << myName << "�̰�, " << age << "���Դϴ�." << std::endl;

	//Quiz 2
	//auto ����� : �ʱ갪�� ���Ŀ� ���� �����ϴ� �ν��Ͻ��� ������ �ڵ����� ������ ( = Ÿ�� �߷� ) - Ÿ���� �߷��� �����Ϸ��� ����
	//				���� �� ������ �ʱ�ȭ �Ҷ��� ������. - �̹� ������ �������� ����� �� ����.
	//				�Լ� �Ű� ������ �Բ� ����� �� ����.

	int a = 10;
	int b(a);
	auto c(b);
	// auto �� Ÿ���� �߷��� �ڵ����� �������ش�.

	std::cout << a + b + c << std::endl;

	//Quiz 3
	char* newArray = new char[12];

	for (int i = 0; i < 12; i++) {
		newArray[i] = i;
	}

	for (int i = 0; i < 12; i++) {
		std::cout << static_cast<int>(newArray[i]) << std::endl;
	}
	delete[] newArray;

	//Quiz 4
	int x = 10;
	int y = 20;
	Swap2(x, y);

	std::cout << x << "/" << y << std::endl;

	//Quiz 5
	// && �̷������� ����ؼ� ����
	// ���� C���� ������� : �ּҸ� ���ؼ� ����
	// C++ �� �߰��� ����� ���� : ������ �ӽ� ����� ��Ÿ���� ����� ������ �� �ְ� ��.

	int nInput = 0;
	int&& rData = nInput + 5;
	std::cout << rData << std::endl;
	
	//Quiz 6
	int aList[5] = { 10,20,30,40,50 };
	for (int i = 0; i < sizeof(aList) / sizeof(int); i++)
	{
		for (int j = 0; j < sizeof(aList) / sizeof(int); j++)
		{
			if (aList[i] > aList[j])
				Swap2(aList[i], aList[j]);
		}
	}

	for (int m : aList)
	{
		std::cout << m << std::endl;
	}

	return 0;
}

void Swap2(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}