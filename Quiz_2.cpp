#include "pch.h"
#include "Quiz_2.h"
#include <iostream>

using namespace std;

int nDataQuiz = 200;

namespace TESTQuiz {
	int nData = 100;
	void TestFunc(void) {
		cout << nDataQuiz << endl;
	}
}

int main(void) {

	//Quiz - 1
	//int TestFunc(int nParam1 = 5, int nParam2, int nParam3 = 10)
	//	=> 중간 매개변수는 디폴트값으로 둘 수 없다.
	//int TestFunc(int nParam1 = 5, int nParam2)
	//	=> 오른쪽 매개변수부터 디폴트값으로 둬야한다.

	//Quiz - 2
	//b가 디폴트값이라 서로 a 값만 받으면 되서 모호해진다.

	//Quiz - 3
	// 여러 타입을 하나의 함수에 사용할 수 있기 때문에

	// Quiz - 4
	// 함수 호출로 인한 오버헤드 극복

	// Quiz - 5
	// 네임스페이스를 매번 작성하기 싫다면 미리 ( using ) 선언을 하는 것이 좋습니다.

	// Quiz -6
	TESTQuiz::TestFunc();

	return 0;
}


