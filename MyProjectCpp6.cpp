#include "pch.h"
#include "MyProjectCpp6.h"
#include <iostream>
using namespace std;

class CMyData {
	// 기본 접근 제어 지시자 'private'
	int m_nData;

public :
	int GetData(void) { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	// Get/ Set 으로만 m_nData 값이 변경될 수 있음을 나타냄 - 사용자는 Get,Set만 사용해야함
};

class CTestConstrutor {
public :
	CTestConstrutor(){
		cout << "CTestConstrutor()" << endl;
	}

	~CTestConstrutor() {
		cout << "~CTestConstrutor()" << endl;
	}
};

// 디폴트 생성자의 생략
class CTestParam {
	int m_nData;
public:
	CTestParam(int nParam) : m_nData(nParam) {
		cout << "CTestParam()" << endl;
	}
	~CTestParam() {
		cout << "~CTestParam" << m_nData << endl;
	}
};

class CTestNewDel {
	int m_nData;
public:
	CTestNewDel() {
		cout << "CTestNewDel" << endl;
	}

	~CTestNewDel() {
		cout << "~CTestNewDel" << endl;
	}
};

class CTestRef {
	
public:
	CTestRef(int &rParam) : m_nData(rParam) { };
	int GetData(void) { return m_nData; }

private:
	int& m_nData;
};
//CTestConstrutor a;
// 전역 변수로 설정 시 main 함수보다 먼저 생성자가 실행된다.


//8
int main(void) {

	//접근 제어 지시자 : 제작자가 사용자가 이용할 수 있는 코드를 제한하는 용도로 활용
	//Why ? : 사용자는 클래스의 구조를 제작자보다 상대적으로 모르기에 필요한 부분만 제어할 수 있도록 하기 위함
	//Public : 멤버에 관한 모든 외부 접근이 허용
	//Protected : 멤버에 관한 외부 접근이 차단되나, 상속 관계에 있는 파생 클래스에서의 접근은 허용
	//Private : 멤버에 관한 외부 접근 및 파생 클래스에서의 접근도 모두 차단 (기본값)
	CMyData data;
	data.SetData(10);
	cout << data.GetData() << endl;

	//data.m_nData; : private 이기 때문에 오류 발생

	// 생성자 , 소멸자 : 객체가 생성 및 소멸될 때 ' 자동으로 ' 호출
	// -> 함수임에도 불구하고 ' 반환 형식이 없다 '
	// 생성자는 다중 정의 가능 , 소멸자는 불가능
	// 
	// 매개변수가 하나도 없는 생성자 = 디폴트 생성자
	// -> 디폴트 생성자는 기술하지 않아도 컴파일러가 알아서 넣음 (즉, 아무런 코드도 추가되지 않음) => 생성자, 소멸자가 없는 클래스는 없다.

	
	CTestConstrutor a;				// 객체 생성 시점
	cout << "Begin a" << endl;

	// 지역 변수는 선언된 블록 범위가 끝나면 자동 소멸

	CTestConstrutor b;				// 생성자 다중 정의
	cout << "Begin b" << endl;

	cout << "End" << endl;

	// 디폴트 생성자의 생략
	cout << "Begin 1" << endl;
	CTestParam a1(1);
	cout << "Begin 2" << endl;
	CTestParam b1(2);
	cout << "End" << endl;

	// 소멸자가 생성시 가장 최근에 만들어진 객체부터 소멸시킨다 ( b1 소멸 이후 a1 소멸 )

	// 동적 객체의 생성과 소멸
	// 클래스의 인스턴스는 선언해서 생성 -> new 연산을 통해 동적 생성 가능
	// -> 동적 생성된 객체는 Delete 연산자로 삭제해야함

	cout << "Begin" << endl;

	CTestNewDel* pData = new CTestNewDel;
	cout << "Test" << endl;
	delete pData;
	cout << "End" << endl;

	// Delete 시 배열로 생성한 객체는 반드시 배열로 삭제해야함.

	CTestNewDel* pData2 = new CTestNewDel[3];
	delete[] pData2;
	cout << "End" << endl;
	//delete pData2;
	// 배열로 생성한 객체를 배열로 삭제하지 않으면 하나만 소멸하고 나머지는 메모리에 그대로 남아버림
	// -> 매우 주의해야할 사항
	//  => 이 문제로 메모리 릭(leak 3) 버그를 만듦 ( 클래스가 아닌 기본 자료형의 배열은 배열로 삭제하지 않아도 오류가 발생하지는 않으나, 주의해야함)


	// 참조형식 멤버 초기화
	// 클래스의 멤버 변수는 참조 형식으로 선언할 수 있음 -> 반드시 선언과 동시에 초기화를 해줘야함 (생성자 초기화 목록을 이용)


	return 0;
}