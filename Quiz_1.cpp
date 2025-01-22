#include "pch.h"
#include <iostream>
#include "Quiz_1.h"
//3
int main(void) {

	// Quiz 1
	std::string myName;
	int age = 0;

	std::cout << "자신의 이름 : ";
	std::cin >> myName;

	std::cout << "자신의 나이 : ";
	std::cin >> age;

	std::cout << "나의 이름은 " << myName << "이고, " << age << "살입니다." << std::endl;

	//Quiz 2
	//auto 예약어 : 초깃값의 형식에 맞춰 선언하는 인스턴스의 형식이 자동으로 결정됨 ( = 타입 추론 ) - 타입을 추론해 컴파일러에 지시
	//				생성 시 변수를 초기화 할때만 동작함. - 이미 생성된 변수에는 사용할 수 없음.
	//				함수 매개 변수와 함께 사용할 수 없다.

	int a = 10;
	int b(a);
	auto c(b);
	// auto 가 타입을 추론해 자동으로 결정해준다.

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
	// && 이런식으로 사용해서 선언
	// 기존 C언어에서 참조방식 : 주소를 통해서 참조
	// C++ 에 추가된 상수형 참조 : 연산의 임시 결과를 나타내는 상수를 참조할 수 있게 됨.

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