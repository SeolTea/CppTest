//7
#include "pch.h"
#include "MyProjectCpp5.h"
#include <iostream>
using namespace std;

// 클래스 기본 문법 : 함수를 포함할 수 잇는 구조체
// 구조체와 다른 점 : " 접근 제어 지시자 " 선언, 함수를 멤버로 포함할 수 있다.
class USERDATA {
public :		// 접근 제어 지시자
	// public : 기본적인 구조체 사용 (전역)
	// 멤버 변수 선언
	int nAge;
	char szName[32];

	// 멤버 함수 선언 및 정의
	void Print(void) {
		printf("%d, %s\n", nAge, szName);
		// nAge 와 szName 은 Print 의 지역 변수가 아님
	}
};

//생성자 
// 큰 특징 : 반환 자료형이 없다, 호출하는 함수가 아니라 적절한 시기에 내부에서 자동으로 호출되는 함수

class CTest {
public:

	// CTest 클래스의 ' 생성자 함수' 선언 및 정의
	CTest() {
		// 인스턴스가 생성되면 멤버 데이터를 ' 자동으로 ' 초기화
		cout << "CTest() : 생성자 함수" << endl;
		m_nData = 10;
	}

	// 멤버 데이터 선언
	int m_nData;

	void PrintData(void){
		cout << m_nData << endl;
		cout << "- PrintData() -" << endl;
	}

	// 멤버 함수 선언, 정의 분리
	void PrintData2(void);
};

// 멤버함수 정의 분리
void CTest::PrintData2(void) {
	// CTest 클래스의 멤버 데이터에 접근하고 값을 출력
	cout << m_nData << endl;
	cout << "- PrintData2() -" << endl;
}

class CTest2 {
public :
	// 생성자 초기화 목록을 활용해도 초기화 가능
	// 반드시 콜론 기술
	// 멤버 변수가 참조자 형식이면 반드시 초기화 목록을 이용해 초기화해야한다.
	CTest2() : m_nData1(10), m_nData2(20) {
		// 인스턴스가 생성되면 멤버 데이터를 ' 자동으로 ' 초기화
		cout << "CTest2() : 생성자 함수" << endl;
	}

	// 멤버 데이터 선언
	int m_nData1;
	int m_nData2;

	void PrintData(void) {
		cout << m_nData1 << endl;
		cout << m_nData2 << endl;
		cout << "- PrintData() -" << endl;
	}

};

class CTest3 {
public:
	// 일반 초기화 방식도 가능

	CTest3()  {
		// 인스턴스가 생성되면 멤버 데이터를 ' 자동으로 ' 초기화
		cout << "CTest3() : 생성자 함수" << endl;
	}

	// 멤버 데이터 선언
	int m_nData1 = 10;
	int m_nData2 = 20;

	void PrintData(void) {
		cout << m_nData1 << endl;
		cout << m_nData2 << endl;
		cout << "- PrintData() -" << endl;
	}

};



int main(void) {

	//객체 : 변수들과 그와 관련된 메서드들이 모여서 이룬 하나의 꾸러미 (어떤 동작이나 상태를 나타내는 단위)
	//클래스 : 구조체에서 확정된 변수, 객체, 함수를 포함한 하나의 틀

	/*C언어 예시
	typedef struct USERDATA
	{
		int nAge;
		char szName[32];
	}USERDATA;

	int main(void) {
		USERDATA user = { 20, "철수" };
		printf("%d, %s\n", user.nAge, user.szName);

		return 0;
	}*/

	// 이럴 경우 사용자는 제작자가 만든 자료구조(구조체)의 멤버 및 구성을 알고 있어야함.
	// 자료구조에 대한 정보를 출력하고 싶다면, 사용자 스스로 직접 멤버에 접근해야하며 적절한 출력 방법도 생각해야함.
	// 만일 제작자가 자료구조를 변경한다면 사용자는 제작자의 코드와 관련된 자신의 코드를 전부 수정해야함.

	/*C언어 예시 2 (다수의 사용자를 배려한 코드)
	
	typedef struct USERDATA
	{
		int nAge;
		char szName[32];
	}USERDATA;

	void PrintData(USERDATE *pUser)
	{
		printf("%d, %s\n", pUser.nAge, pUser.szName);
	}

	int main(void) {
		USERDATA user = { 20, "철수" };
		printf("%d, %s\n", user.nAge, user.szName);
		PrintData(&user);				// 구조체 멤버에 일일이 변경하지 않아도 됨(제작자만 힘듦-> 사용자는 편안)
		// 출력을 위한 구체적인 방법을 사용자가 굳이 알 필요가 없어짐
		// -> 함수를 제공받아 사용하면 그만 => 이런 역할을 위한 함수가 " 인터페이스 함수 "

		return 0;
	}*/

	
	//C 언어 예시 3 ( 구조체와 함수의 관계 형성 => 구조체 안에 함수를 집어 넣음)

	//typedef struct USERDATA
	//{
	//	int nAge;
	//	char szName[32];
	//  void(*Print)(struct USERDATA *);
	//}USERDATA;

	//void PrintData(USERDATE * pUser)
	//{
	//	printf("%d, %s\n", pUser.nAge, pUser.szName);
	//}

	//int main(void) {
	//	USERDATA user = { 20, "철수", PrintData };
	//	printf("%d, %s\n", user.nAge, user.szName);
	//	PrintData(&user);				// 구조체 멤버에 일일이 변경하지 않아도 됨(제작자만 힘듦-> 사용자는 편안)
	//	// 출력을 위한 구체적인 방법을 사용자가 굳이 알 필요가 없어짐
	//	// -> 함수를 제공받아 사용하면 그만 => 이런 역할을 위한 함수가 " 인터페이스 함수 "
	//	user.Print(&user);
	//  함수가 구조체 안에 멤버로써 들어감

	// 클래스 기본 문법
	
	USERDATA user = { 10, "철수" };			// 멤버 변수 초기화 (사용자가 불편함) -> 생성자로 문제 해결 가능
	user.Print();

	cout << "main() 함수 시작" << endl;

	CTest t;			// 생성자 호출 (객체 선언)
	t.PrintData();
	t.PrintData2();

	CTest2 t2;
	t2.PrintData();

	CTest3 t3;
	t3.PrintData();

	cout << "main() 함수 끝" << endl;


	return 0;
}

