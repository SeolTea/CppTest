//14
#include "pch.h"
#include "MyProjectCpp10.h"
#include <iostream>
using namespace std;

// 복사 생성자
class CMyDataCopy {
public:
	CMyDataCopy() { cout << "CMyDataCopy" << endl; }

	// 복사 생성자 선언 및 정의
	CMyDataCopy(const CMyDataCopy& rhs) 
		// : m_nData(rhs.m_nData)
	{
		this->m_nData = rhs.m_nData;
		cout << "CMyDataCopy(const CMyDataCopy &)" << endl;
	}

	int GetData(void) const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private :
	int m_nData = 0;
};

// 함수 호출과 복사 생성자
// 함수 형태로 호출할 때는 클래스가 매개변수로 사용되는 경우, 반환 형식으로 사용되는 경우 로 나누어짐

class CTestDataCopy {
public :
	CTestDataCopy(int nParam) : m_nData(nParam) { cout << "CTestDataCopy(int)" << endl; }
	CTestDataCopy(const CTestDataCopy& rhs) : m_nData(rhs.m_nData) { cout << "CTestDataCopy(const CTestDataCopy &)" << endl; }

	// 읽기 전용인 상수형 메서드
	int GetData() const { return m_nData; }

	// 멤버 변수에 쓰기를 시도하는 메서드
	void SetData(int nParam) { m_nData = nParam; }
private :
	int m_nData = 0;
};

// 복사 생성자 삭제

class CTestDataCopyDel {
public:
	CTestDataCopyDel(int nParam) : m_nData(nParam) { cout << "CTestDataCopyDel(int)" << endl; }
	//CTestDataCopyDel(const CTestDataCopy& rhs) : m_nData(rhs.m_nData) { cout << "CTestDataCopyDel(const CTestDataCopy &)" << endl; }

	CTestDataCopyDel(const CTestDataCopyDel& rhs) = delete;

	// 읽기 전용인 상수형 메서드
	int GetData() const { return m_nData; }

	// 멤버 변수에 쓰기를 시도하는 메서드
	void SetData(int nParam) { m_nData = nParam; }
private:
	int m_nData = 0;
};

// 매개변수가 CTestDataCopy 클래스 형식이므로 복사 생성자가 호출
void TestFunc(CTestDataCopy param) {
	cout << "TestFunc()" << endl;

	// 피호출자 함수에서 매개변수 인스턴스의 값을 변경.
	param.SetData(20);
}

// 복사 생성자 삭제
void TestFuncDel(CTestDataCopyDel param) {
	cout << "TestFuncDel()" << endl;

	// 피호출자 함수에서 매개변수 인스턴스의 값을 변경.
	param.SetData(20);
}

int main(void) {

	// 복사 생성자 : 객체의 복사본을 생성할 때 호출되는 생성자
	// 클래스를 작성할 때 복사 생성자를 생략하면 디폴트 생성자처럼 컴파일러가 알아서 만들어줌 ( 꼭 필요한 거 아니면 정의할 필요 없음 )
	// 복사 생성자를 적용하지 않으면 심각한 문제 발생
	// -> 클래스 내부에서 메모리를 동적 할당 및 해제하고 이를 멤버 포인터 변수로 관리하고 있는 경우

	// 디폴트 생성자 호출
	CMyDataCopy a;
	a.SetData(10);

	// 복사 생성자 호출
	CMyDataCopy b(a);
	cout << b.GetData() << endl;
	// 복사 원본 : a

	// 함수 호출 및 복사 생성자
	cout << "***** Begin *****" << endl;
	CTestDataCopy aa(10);
	TestFunc(aa);
	// 객체가 두개 생성됨 -> 성능 나빠짐 -> 한 객체로 할 수 있는 일은 무조건 하나로 끝내야함

	// 함수 호출 후 aa 값을 출력
	cout << "aa : " << aa.GetData() << endl;

	cout << "***** End *****" << endl;

	// 복사 생성자 삭제

	cout << "***** Begin *****" << endl;
	CTestDataCopyDel aaa(10);
	//TestFuncDel(aaa);
	// 복사 생성자를 사용할 경우 삭제 처리가 되버림

	// 함수 호출 후 aa 값을 출력
	cout << "aaa : " << aaa.GetData() << endl;

	cout << "***** End *****" << endl;

	return 0;
}