//10
#include "pch.h"
#include "MyProjectCpp8.h"
#include <iostream>
using namespace std;

// 명시적 디폴트 생성자
class CTest8 {
public :
	//CTest8(void);
	// => 이런 경우 default 예약어를 사용하면 됨
	CTest8(void) = default;
	int m_nData = 5;
};

// 메서드 : 클래스 멤버 함수 = 클래스가 제공하는 기능을 실행하는 방법이라고 생각하면 좋음
// 멤버함수는 때로 " 인터페이스 함수 " 라고도 불림

//CTest8::CTest8(void) {}
//=> 이런 경우 default 예약어 사용하면 됨.


// this 포인터
class CMyDataThis {
public :

	CMyDataThis(int nParam) : m_nData(nParam) {};

	void PrintData() 
	{
		// 매개변수 : CMyDataThis *pData
		//CMyDataThis *this = pData
		// 해당 코드가 생략되어 있다.

		// m_nData 값을 출력한다.
		cout << m_nData << endl;
		
		//CMyDataThis 클래스의 멤버인 m_nData 를 출력한다.
		cout << CMyDataThis::m_nData << endl;

		// 메서드를 호출한 인스턴스의 m_nData 멤버 값을 출력한다.
		cout << this->m_nData << endl;

		// 메서드를 호출한 인스턴스의 CMyDataThis 클래스 멤버 m_nData를 출력한다.
		// 이렇게 작성하는게 좋음
		// why ? ) 범위 지정 연산자를 통해 m_nData의 소속을 정확하게 명시 가능
		//			this 포인터를 통해 접근 가능
		cout << this->CMyDataThis::m_nData << endl;

		
	}

private:
	int m_nData;
};

int main(void) {

	// 명시적 디폴트 생성자
	// 함수 : 원형 선언을 별도로 할 경우 성언과 정의가 분리 =  같은 논리가 클래스에도 적용
	// Default  예약어를 사용하면 선언과 정의를 한 번에 끝낼 수 있음

	CTest8 a;
	cout << a.m_nData << endl;

	// this 포인터

	CMyDataThis at(5), bt(10);
	at.PrintData();
	bt.PrintData();

	return 0;
}