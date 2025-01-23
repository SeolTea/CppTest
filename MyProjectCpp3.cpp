//4
#include "pch.h"
#include <iostream>
#include <cstdio>
#include "MyProjectCpp3.h"

#define MYTYPE_A 100
#define MYTYPE_B 200

#define ADD(a,b)((a)+(b))

int main(void) {
	
	// 매개변수 하나 디폴트
	
	//호출자가 실인수(=인수)를 기술하지 않았으므로 디폴트값 적용
	std::cout << TestFuncDef() << std::endl;

	//호출자가 실인수(=인수)를 기술하였으므로 인수값 적용
	std::cout << TestFuncDef(20) << std::endl;

	// 매개변수 둘 디폴트
	// 피호출자 함수의 매개변수의 디폴트 값은 오른쪽 매개변수부터 기술해야함
	   // => 즉, 왼쪽 매개변수를 디폴트 값으로 기술하려면 오른쪽 나머지 매개변수도 전부 디폴트값으로 선언해줘야함.( 중간에 빼먹으면 절대 안됨 )
	std::cout << TestFuncDef2(10) << std::endl;
	std::cout << TestFuncDef2(10, 5) << std::endl;

	std::cout << CalcLayout(10, 5, MYTYPE_A) << std::endl;


	// 함수 다중 정의 (overloading = 오버로딩)
	// 호출 함수가 컴파일러에 의해 자동 결정

	std::cout << Add(3, 4) << std::endl;
	std::cout << Add(3, 4, 5) << std::endl;
	std::cout << Add(3.3, 4.5) << std::endl;

	//반환 형식만 다른 경우 다중 정의 불가능
	// int Add(int a, int b)
	// double Add(int a, int b) 
	// 두 개 다 오류임

	// 호출 규칙만 다른 경우 다중 정의 불가능
	// int _cdecl Add(int a, int b)
	// int _stdcall Add(int a, int b)



	// 다중 정의와 디폴트 매개변수 동시 사용 시 모호성 테스트
	//TestError(10); -> 모호하기에 에러 발생


	// 함수 탬플릿
	std::cout << "int/t " << TestFuncTemp(3) << std::endl;
	std::cout << "int/t " << TestFuncTemp(3.3) << std::endl;
	std::cout << "int/t " << TestFuncTemp('A') << std::endl;
	std::cout << "int/t " << TestFuncTemp("TestString") << std::endl;
	// 굳이 형식을 지정하지 않아도 쉽게 코드를 확장할 수 있음. 

	std::cout << "add1 " << AddTmp(3,4) << std::endl;
	std::cout << "add2 " << AddTmp(3.3,4.4) << std::endl;
	std::cout << "add3 " << AddTmp<int>(3, 4) << std::endl; // 형변환도 가능


	// 인라인 함수 = 매크로의 장점과 함수의 장점을 모아놓음
	// 함수이므로 매개변수에 형식 지정 가능
	// 문법도 매우 간단
	// 내부적으로 매크로처럼 함수 호출 하지 않음

	int a, b;
	scanf_s("%d%d", &a, &b);

	printf("ADD(): %d", ADD(a, b));
	printf("ADD(): %d", Add2(a, b));
	printf("ADD(): %d", AddNew(a, b));


	return 0;
}

// 매개변수의 디폴트 값은 10 이다.
// 디폴트값 선언 시 헤더 파일 - 함수 선언에서 디폴트값을 작성하고 소스 파일 - 함수 정의에선 디폴트 값을 작성하지 않는다. - 작성하면 에러남
int TestFuncDef(int nParam) {
	return nParam;
}

//매개변수
int TestFuncDef2(int nParam1, int nParam2)
{
	return nParam1 * nParam2;
}

int CalcLayout(int nWidth, int nHeight, int nType) {
	return nWidth * nHeight + nType;
}

int Add(int a, int b, int c) {
	std::cout << "Add(int, int, int) : ";
	return a + b + c;
}

int Add(int a, int b) {
	std::cout << "Add(int, int) : ";
		return a + b;
}

double Add(double a, double b) {
	std::cout << "Add(double double) : ";
	return a + b;
}


// 다중 정의와 디폴트 매개변수 동시 사용 시 모호성 테스트
//void TestError(int a) {
//	std::cout << "TestFunc(int)" << std::endl;
//}
//
//void TestError(int a, int b) {
//	std::cout << "TestFunc(int int)" << std::endl;
//}

template <typename T>
T TestFuncTemp(T a)
{
	std::cout << "매개변수 a : " << a << std::endl;
	return a;
}

template <typename T>
T AddTmp(T a, T b) {
	return a + b;
}

int Add2(int a, int b) {
	return a + b;
}

inline int AddNew(int a, int b) {
	return a + b;
}
