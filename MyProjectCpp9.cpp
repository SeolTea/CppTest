//12
#include "pch.h"
#include "MyProjectCpp9.h"
#include <iostream>
using namespace std;

// ��� �޼���� ��� ������ �б� ������ ���������� ����� ������ �ʴ� �޼���
// -> ���� : ���� �����ڳ� ���� �����ڸ� ����ϴ� ��
class CTestConst {
public :
	CTestConst(int nParam) : m_nData(nParam) {	};
	~CTestConst() { } ;

	// ����� �޼���� ���� �� ����
	int GetData() const {
		// ��� ������ ���� ���� ���� ������ �� ���� ����.

		// ����� �޼���� mutable ��� �������� ���� �� �� �ִ�.
		m_nData2 = 20;

		return m_nData + m_nData2;
	}

	//int GetData() const {
	// 
	//	m_nData = 20;  -> ���Ⱑ �Ұ����ϱ⿡ ���� �߻�
	//  SetData(20);   -> ���Ⱑ �Ұ����ϱ⿡ ���� �߻�
	//  
	// //  ������ ��� �Լ��� ȣ���� �� ����. -> ��ü�� �ٲ�� �ȵ�
	//	// ��� ������ ���� ���� ���� ������ �� ���� ����.
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

	// �Ű������� double �� ���� ���� ���� ��
	// ���� ����
	void SetData(double dParam) { m_nData = 0; }
	// ������ ���� �߻�
	//void SetData(double dParam) = delete;

private :
	int m_nData;
};

// ���� ���
// ������ �Լ��� ' ���� ��� ' �� ��ǻ� ���� ������ �Լ��� ����.
// this �����͸� ����� �� ������, ���� ������ �ݵ�� ����� ���Ǹ� �и��ؾ���
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

	// ���� ��� ���� ���� (���ǰ� �ƴ�)
	static int m_nCount;
};

// ���� ��� ���� ����
int CTestStatic::m_nCount = 0;

void TestFuncCast(const int &nParam){
	// ����� ���������� �Ϲ� ������ ����ȯ
	int& nNewParam = const_cast<int&>(nParam);

	// ���� l-value �� �� �� �ִ�.
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

	// ���� ����� ����
	cout << aaa.GetCount() << endl;
	bbb.ResetCount();

	// ���� ����� ����. �ν��Ͻ� ���̵� ���� ����
	cout << CTestStatic::GetCount() << endl;

	return 0;
}