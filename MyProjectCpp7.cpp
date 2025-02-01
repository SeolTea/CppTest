#include "pch.h"
#include "MyProjectCpp7.h"
#include <iostream>
using namespace std;

//9

//생성자도 함수이므로 다중 정의 가능

class CMyData {
public:
	//디폴트 생성자는 없다.
	//매개 변수가 int 하나인 생성자 함수 선언 및 정의
	CMyData(int nParam) : m_nData(nParam) { };

	//매개 변수가 int 두개인 생성자 함수 다중 정의
	CMyData(int x, int y) : m_nData(x + y) { };

	int GetData(void) { return m_nData; }

private:
	int m_nData;
};

// 생성자 위임

class CMyPoint {
public:
	CMyPoint(int x) {
		cout << "CMyPoint(int)" << endl;
		// x값이 100이 넘는지 검사하고 넘으면 100으로 맞춤
		if (x > 100) {
			x = 100;
			m_x = 100;
		}
	}

	// x값을 검사하는 코드는 이미 존재하므로 재사용
	CMyPoint(int x, int y) :CMyPoint(x) {
		cout << "CMyPoint(int,int)" << endl;

		//y값이 200이 넘는지 검사하고 넘으면 200으로 맞춘다.
		if (y > 200) {
			y = 200;
			m_y = 200;
		}
	}

	void Print() {
		cout << "X:" << m_x << endl;
		cout << "Y:" << m_y << endl;
	}

private :
	int m_x = 0;
	int m_y = 0;
};

int main(void) {
	// 생성자 다중 정의
	// 어떤 생성자를 호출할 지는 컴파일러가 매개변수를 보고 알아서 결정함
	// 생성자를 다중 정의할 경우 사용자는 편하나 제작자는 번거로움 존재 -> 초기화 하는 코드를 여러번 기술해야함 (버그의 원인이 될 수도 있음)
	// -> " 생성자 위임 " 이 지원 -> 생성자 초기화 목록에서 다른 생성자를 추가로 부를 수 있음
	CMyData a(10);
	CMyData b(3, 4);

	cout << a.GetData() << endl;
	cout << b.GetData() << endl;


	//생성자 위임
	CMyPoint ptBegin(110);
	ptBegin.Print();

	CMyPoint ptEnd(50, 250);
	ptEnd.Print();

	return 0;
}