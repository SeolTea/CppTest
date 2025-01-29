//7
#include "pch.h"
#include "MyProjectCpp5.h"
#include <iostream>
using namespace std;

// Ŭ���� �⺻ ���� : �Լ��� ������ �� �մ� ����ü
// ����ü�� �ٸ� �� : " ���� ���� ������ " ����, �Լ��� ����� ������ �� �ִ�.
class USERDATA {
public :		// ���� ���� ������
	// public : �⺻���� ����ü ��� (����)
	// ��� ���� ����
	int nAge;
	char szName[32];

	// ��� �Լ� ���� �� ����
	void Print(void) {
		printf("%d, %s\n", nAge, szName);
		// nAge �� szName �� Print �� ���� ������ �ƴ�
	}
};

//������ 
// ū Ư¡ : ��ȯ �ڷ����� ����, ȣ���ϴ� �Լ��� �ƴ϶� ������ �ñ⿡ ���ο��� �ڵ����� ȣ��Ǵ� �Լ�

class CTest {
public:

	// CTest Ŭ������ ' ������ �Լ�' ���� �� ����
	CTest() {
		// �ν��Ͻ��� �����Ǹ� ��� �����͸� ' �ڵ����� ' �ʱ�ȭ
		cout << "CTest() : ������ �Լ�" << endl;
		m_nData = 10;
	}

	// ��� ������ ����
	int m_nData;

	void PrintData(void){
		cout << m_nData << endl;
		cout << "- PrintData() -" << endl;
	}

	// ��� �Լ� ����, ���� �и�
	void PrintData2(void);
};

// ����Լ� ���� �и�
void CTest::PrintData2(void) {
	// CTest Ŭ������ ��� �����Ϳ� �����ϰ� ���� ���
	cout << m_nData << endl;
	cout << "- PrintData2() -" << endl;
}

class CTest2 {
public :
	// ������ �ʱ�ȭ ����� Ȱ���ص� �ʱ�ȭ ����
	// �ݵ�� �ݷ� ���
	// ��� ������ ������ �����̸� �ݵ�� �ʱ�ȭ ����� �̿��� �ʱ�ȭ�ؾ��Ѵ�.
	CTest2() : m_nData1(10), m_nData2(20) {
		// �ν��Ͻ��� �����Ǹ� ��� �����͸� ' �ڵ����� ' �ʱ�ȭ
		cout << "CTest2() : ������ �Լ�" << endl;
	}

	// ��� ������ ����
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
	// �Ϲ� �ʱ�ȭ ��ĵ� ����

	CTest3()  {
		// �ν��Ͻ��� �����Ǹ� ��� �����͸� ' �ڵ����� ' �ʱ�ȭ
		cout << "CTest3() : ������ �Լ�" << endl;
	}

	// ��� ������ ����
	int m_nData1 = 10;
	int m_nData2 = 20;

	void PrintData(void) {
		cout << m_nData1 << endl;
		cout << m_nData2 << endl;
		cout << "- PrintData() -" << endl;
	}

};



int main(void) {

	//��ü : ������� �׿� ���õ� �޼������ �𿩼� �̷� �ϳ��� �ٷ��� (� �����̳� ���¸� ��Ÿ���� ����)
	//Ŭ���� : ����ü���� Ȯ���� ����, ��ü, �Լ��� ������ �ϳ��� Ʋ

	/*C��� ����
	typedef struct USERDATA
	{
		int nAge;
		char szName[32];
	}USERDATA;

	int main(void) {
		USERDATA user = { 20, "ö��" };
		printf("%d, %s\n", user.nAge, user.szName);

		return 0;
	}*/

	// �̷� ��� ����ڴ� �����ڰ� ���� �ڷᱸ��(����ü)�� ��� �� ������ �˰� �־����.
	// �ڷᱸ���� ���� ������ ����ϰ� �ʹٸ�, ����� ������ ���� ����� �����ؾ��ϸ� ������ ��� ����� �����ؾ���.
	// ���� �����ڰ� �ڷᱸ���� �����Ѵٸ� ����ڴ� �������� �ڵ�� ���õ� �ڽ��� �ڵ带 ���� �����ؾ���.

	/*C��� ���� 2 (�ټ��� ����ڸ� ����� �ڵ�)
	
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
		USERDATA user = { 20, "ö��" };
		printf("%d, %s\n", user.nAge, user.szName);
		PrintData(&user);				// ����ü ����� ������ �������� �ʾƵ� ��(�����ڸ� ����-> ����ڴ� ���)
		// ����� ���� ��ü���� ����� ����ڰ� ���� �� �ʿ䰡 ������
		// -> �Լ��� �����޾� ����ϸ� �׸� => �̷� ������ ���� �Լ��� " �������̽� �Լ� "

		return 0;
	}*/

	
	//C ��� ���� 3 ( ����ü�� �Լ��� ���� ���� => ����ü �ȿ� �Լ��� ���� ����)

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
	//	USERDATA user = { 20, "ö��", PrintData };
	//	printf("%d, %s\n", user.nAge, user.szName);
	//	PrintData(&user);				// ����ü ����� ������ �������� �ʾƵ� ��(�����ڸ� ����-> ����ڴ� ���)
	//	// ����� ���� ��ü���� ����� ����ڰ� ���� �� �ʿ䰡 ������
	//	// -> �Լ��� �����޾� ����ϸ� �׸� => �̷� ������ ���� �Լ��� " �������̽� �Լ� "
	//	user.Print(&user);
	//  �Լ��� ����ü �ȿ� ����ν� ��

	// Ŭ���� �⺻ ����
	
	USERDATA user = { 10, "ö��" };			// ��� ���� �ʱ�ȭ (����ڰ� ������) -> �����ڷ� ���� �ذ� ����
	user.Print();

	cout << "main() �Լ� ����" << endl;

	CTest t;			// ������ ȣ�� (��ü ����)
	t.PrintData();
	t.PrintData2();

	CTest2 t2;
	t2.PrintData();

	CTest3 t3;
	t3.PrintData();

	cout << "main() �Լ� ��" << endl;


	return 0;
}

