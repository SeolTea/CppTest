//12
#include "pch.h"
#include "MyProjectCpp9.h"
#include <iostream>
using namespace std;

// 상수 메서드는 멤버 변수에 읽기 접근은 가능하지만 쓰기는 허용되지 않는 메서드
// -> 쓰기 : 대입 연산자나 단항 연산자를 사용하는 것
class CTestConst {
public :
	CTestConst(int nParam) : m_nData(nParam) {	};
	~CTestConst() { } ;

	// 상수형 메서드로 선언 및 정의
	int GetData() const {
		// 멤버 변수의 값을 읽을 수는 있지만 쓸 수는 없다.

		// 상수형 메서드라도 mutable 멤버 변수에는 값을 쓸 수 있다.
		m_nData2 = 20;

		return m_nData + m_nData2;
	}

	//int GetData() const {
	// 
	//	m_nData = 20;  -> 쓰기가 불가능하기에 오류 발생
	//  SetData(20);   -> 쓰기가 불가능하기에 오류 발생
	//  
	// //  비상수형 멤버 함수를 호출할 수 없다. -> 객체가 바뀌면 안됨
	//	// 멤버 변수의 값을 읽을 수는 있지만 쓸 수는 없다.
	//	return m_nData;
	//}

	int SetData(int nParam) { m_nData = nParam; }

private :
	int m_nData = 0;
	
	mutable int m_nData2 = 0;
};

class CMyDataOver {
public : 
	CMyDataOver() : m_nData(0) {};

	int GetData(void) { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	// 매개변수가 double 인 경우로 다중 정의 시
	// 값만 변경
	void SetData(double dParam) { m_nData = 0; }
	// 컴파일 오류 발생
	//void SetData(double dParam) = delete;

private :
	int m_nData;
};

// 정적 멤버
// 변수든 함수든 ' 정적 멤버 ' 는 사실상 전역 변수나 함수와 같다.
// this 포인터를 사용할 수 없으며, 정적 변수는 반드시 선언과 정의를 분리해야함
class CTestStatic {
public :
	CTestStatic(int nParam) : m_nData(nParam) { m_nCount++; }
	int GetData() { return m_nData; }
	void ResetCount() { m_nCount = 0; }

	static int GetCount() {
		return m_nCount;
	}

private :
	int m_nData;

	// 정적 멤버 변수 선언 (정의가 아님)
	static int m_nCount;
};

// 정적 멤버 변수 정의
int CTestStatic::m_nCount = 0;

void TestFuncCast(const int &nParam){
	// 상수형 참조였으나 일반 참조로 형변환
	int& nNewParam = const_cast<int&>(nParam);

	// 따라서 l-value 가 될 수 있다.
	nNewParam = 20;
}

int main(void) {

	CTestConst a(10);
	cout << a.GetData() << endl;

	int nData = 10;
	TestFuncCast(nData);
	cout << nData << endl;

	CMyDataOver aa;

	aa.SetData(10);
	cout << aa.GetData() << endl;

	CMyDataOver bb;

	bb.SetData(5.5);
	cout << bb.GetData() << endl;

	CTestStatic aaa(5), bbb(10);

	// 정적 멤버에 접근
	cout << aaa.GetCount() << endl;
	bbb.ResetCount();

	// 정적 멤버에 접근. 인스턴스 없이도 접근 가능
	cout << CTestStatic::GetCount() << endl;

	return 0;
}