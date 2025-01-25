//5
#include "pch.h"
#include "MyProjectCpp4.h"
#include <iostream>

using namespace std;

namespace TEST {
	int g_nData = 100;

	void TestFunc(void) {
		std::cout << "TEST::TestFunc()" << std::endl;
	}
}

namespace TEST2 {
	int g_nData = 100;

	namespace DEV {
		int g_nData = 200;

		namespace WIN {
			int g_nData = 300;
		}
	}
}

// 네임스페이스 다중 정의

void TestFuncOver(void) {			// --> 해당 함수도 네임스페이스가 존재함 (전역)
	cout << "::TestFunc()" << endl;
}

namespace TESTOVER {
	void TestFuncOver(void) {
		cout << "TESTOVER::TestFunc()" << endl;
	}
}

namespace MYDATA {
	void TestFuncOver(void) {
		cout << "DATAOVER::TestFunc()" << endl;
	}
}

int tData = 200;

//namespace SearchTest {
//	int tData = 100;				// SearchTest 기준 네임스페이스 안에 있는 tData가 가장 최근에 생성됨
//	void TestFunc(void) {
//		std::cout << tData << std::endl;  // 그렇기에 100 출력
//	}
//}

namespace SearchTest {
	
	void TestFunc(void) {
		std::cout << tData << std::endl;  // SearchTest 기준 전역 변수가 가장 최근에 생성되었기에 200 출력
	}

	int tData = 100;				

}
//
//int tData2 = 200;	// 선언이 되지 않았다고 가정 (주석 처리 필수)
//namespace SearchTest {
//	
//	void TestFunc(void) {
//		std::cout << tData2 << std::endl;  // tData2 가 선언된 적이 없기에 컴파일 에러
//	}
//
//
//	int tData2 = 100;
//}

// 현재 블록 범위
int nData(20);

using namespace TEST;

// 메인 함수는 네임스페이스가 있으면 안됨
int main(void) {
	TEST::TestFunc();			// 네임스페이스가 존재할 경우 범위 지정 연산자 (::) 를 이용해 기술 
	std::cout << TEST::g_nData << std::endl;

	// using 예약어를 써서 미리 선언했기에 생략해도 가능하다.
	TestFunc();
	cout << g_nData << endl;

	// 네임스페이스의 중첩 : 네임스페이스 안에 여러개가 동시에 속할 수도 있고 하나의 네임스페이스 안에 또 다시 네임스페이스를 넣을 수도 있음.
	cout << TEST2::g_nData << endl;
	cout << TEST2::DEV::g_nData << endl;
	cout << TEST2::DEV::WIN::g_nData << endl;

	// 네임스페이스 다중 정의
	TestFuncOver();		// 묵시적 전역
	::TestFuncOver();	// 명시적 전역
	TESTOVER::TestFuncOver();
	MYDATA::TestFuncOver();


	// 첫 번째 순서 : 식별자 검색 순서

	//현재 블록 범위

	int nData(10);
	cout << nData << endl; // 전역으로 20을 선언했어도 10 출력됨 , 먼저 main 블록 범위에서 먼저 찾기 때문

	// 두 번째 순서 : 상위 블록 범위

	int nInput = 0;
	cout << "11 이상의 정수를 입력하세요." << endl;
	cin >> nInput;

	if (nInput > 10) {
		cout << nInput << endl;			// if 블럭에 없기 때문에 상위 블록인 main 에서 찾음 ( 최대 확장 범위는 함수 몸체까지로 제한 ) -> 만일 함수 몸체를 벗어나면 네임스페이스 혹은 클래스 범위까지 확장됨
	}
	else {
		cout << "ERROR" << endl;
	}


	// 세 번째 순서 : 가장 최근에 선언된 전역 변수 -> 네임스페이스보다 선언 위치가 더 우선이다.

	SearchTest::TestFunc();

	return 0;
}

