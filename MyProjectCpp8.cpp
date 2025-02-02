//10
#include "pch.h"
#include "MyProjectCpp8.h"
#include <iostream>
using namespace std;

// ����� ����Ʈ ������
class CTest8 {
public :
	//CTest8(void);
	// => �̷� ��� default ���� ����ϸ� ��
	CTest8(void) = default;
	int m_nData = 5;
};

// �޼��� : Ŭ���� ��� �Լ� = Ŭ������ �����ϴ� ����� �����ϴ� ����̶�� �����ϸ� ����
// ����Լ��� ���� " �������̽� �Լ� " ��� �Ҹ�

//CTest8::CTest8(void) {}
//=> �̷� ��� default ����� ����ϸ� ��.


// this ������
class CMyDataThis {
public :

	CMyDataThis(int nParam) : m_nData(nParam) {};

	void PrintData() 
	{
		// �Ű����� : CMyDataThis *pData
		//CMyDataThis *this = pData
		// �ش� �ڵ尡 �����Ǿ� �ִ�.

		// m_nData ���� ����Ѵ�.
		cout << m_nData << endl;
		
		//CMyDataThis Ŭ������ ����� m_nData �� ����Ѵ�.
		cout << CMyDataThis::m_nData << endl;

		// �޼��带 ȣ���� �ν��Ͻ��� m_nData ��� ���� ����Ѵ�.
		cout << this->m_nData << endl;

		// �޼��带 ȣ���� �ν��Ͻ��� CMyDataThis Ŭ���� ��� m_nData�� ����Ѵ�.
		// �̷��� �ۼ��ϴ°� ����
		// why ? ) ���� ���� �����ڸ� ���� m_nData�� �Ҽ��� ��Ȯ�ϰ� ��� ����
		//			this �����͸� ���� ���� ����
		cout << this->CMyDataThis::m_nData << endl;

		
	}

private:
	int m_nData;
};

int main(void) {

	// ����� ����Ʈ ������
	// �Լ� : ���� ������ ������ �� ��� ����� ���ǰ� �и� =  ���� ���� Ŭ�������� ����
	// Default  ���� ����ϸ� ����� ���Ǹ� �� ���� ���� �� ����

	CTest8 a;
	cout << a.m_nData << endl;

	// this ������

	CMyDataThis at(5), bt(10);
	at.PrintData();
	bt.PrintData();

	return 0;
}