#include "pch.h"
#include <iostream>
#include "MyProjectCpp2.h"

int main(void) {

	// 인스턴스만 동적으로 생성하는 경우
	// 동적 생성 : 필요할때마다 생성한다.
	int* pData = new int;

	// 초깃값을 기술하는 경우
	int* oData = new int(10);

	*pData = 5;

	std::cout << *pData << "+" << *oData << std::endl;
	// 포인터 + 포인터 = 사라진다.

	delete pData;
	delete oData;


	int* arr = new int[5];
	for (int i = 0; i < 5; ++i) {
		arr[i] = (i + 1) * 10;
	}

	for (int i = 0; i < 5; ++i) {
		std::cout << arr[i] << std::endl;
	}

	delete[] arr;

	// 상수와 참조자, 포인터를 선언할 수 없다.
	// int *pData = &3; - 불가능
	// int &pData = 3; - 상수에 대한 참조 불가능
	// int &pData; - 참조 원본이 없으므로 불가능

	// 참조형 변수 사용

	int nData = 10;

	// nData 에 대한 참조자 선언
	int& ref = nData;

	//참조자의 값을 변경하면 원본도 변경됨.
	ref = 20;
	std::cout << nData << std::endl;

	// 포인터랑 참조자랑 비슷
	int* pnData = &nData;
	*pnData = 30;

	std::cout << nData << std::endl;

	int lData = 0;
	TestFunc(lData);

	std::cout << lData << std::endl;

	// & 는 주소 연산자일 수도 있고 참조자일 수도 있음.
	// 참조자일 경우 변수를 담는다.

	int x = 10, y = 20;
	Swap(x, y);

	std::cout << x << "/" << y << std::endl;

	// c++ 에서는 가급적 참조 형식을 사용하자.

	//r-value 참조 관련
	int nInput = 0;
	std::cout << "Input Number : ";
	std::cin >> nInput;

	// 산술 연산으로 만들어진 임시 객체에 대한 r-value 참조
	int&& rdata = nInput + 5;
	std::cout << rdata << std::endl;

	// 함수 반환으로 만들어진 임시 객체에 대한 r-value 참조
	int&& result = TestFunc2(10);
	std::cout << result << std::endl;

	result += 10;
	std::cout << result << std::endl;

	//r-value 는 임시 결과이다.
	// 연산에 활용한 직후 소멸한다.
	// 곧 사라질 대상에게 참조자 부여가 가능하다.
	// 3+4+5 에서 3+4 의 결과값이 임시결과이고 그 임시결과에 +5 를 하는 것이다.

	// 범위기반 for 문
	// 기존 for 문은 횟수를 중심으로 반복 => 배열 요소의 개수가 변경될 경우 for 문을 수정해야하는 경우 존재
	// 범위기반 for 문은 요소 변수를 통해 접근하기에 요소 개수가 자동으로 맞춰짐.

	int aList[5] = { 10,20,30,40,50 };

	// 기존 for 문
	for (int i = 0; i < 5; i++) {
		std::cout << aList[i] << std::endl;
	}

	std::cout << std::endl;

	//범위 기반 for 문
	// n에 aList 요소의 값을 복사한다.
	for (auto n : aList) {
		std::cout << n << std::endl;
	}

	std::cout << std::endl;

	// n 은 각 요소에 대한 참조다.
	for (auto& n : aList) {
		std::cout << n << std::endl;
	}

	return 0;
}

void TestFunc(int& rParam) {
	rParam = 100;
}

void Swap(int& a, int& b) {
	int nTmp = a;
	a = b;
	b = nTmp;
}

int TestFunc2(int nParam) {
	int nResult = nParam * 2;
	return nResult;
}