#include "pch.h"
#include "MyProjectCpp7.h"
#include <iostream>
using namespace std;

//9

//�����ڵ� �Լ��̹Ƿ� ���� ���� ����

class CMyData {
public:
	//����Ʈ �����ڴ� ����.
	//�Ű� ������ int �ϳ��� ������ �Լ� ���� �� ����
	CMyData(int nParam) : m_nData(nParam) { };

	//�Ű� ������ int �ΰ��� ������ �Լ� ���� ����
	CMyData(int x, int y) : m_nData(x + y) { };

	int GetData(void) { return m_nData; }

private:
	int m_nData;
};

// ������ ����

class CMyPoint {
public:
	CMyPoint(int x) {
		cout << "CMyPoint(int)" << endl;
		// x���� 100�� �Ѵ��� �˻��ϰ� ������ 100���� ����
		if (x > 100) {
			x = 100;
			m_x = 100;
		}
	}

	// x���� �˻��ϴ� �ڵ�� �̹� �����ϹǷ� ����
	CMyPoint(int x, int y) :CMyPoint(x) {
		cout << "CMyPoint(int,int)" << endl;

		//y���� 200�� �Ѵ��� �˻��ϰ� ������ 200���� �����.
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
	// ������ ���� ����
	// � �����ڸ� ȣ���� ���� �����Ϸ��� �Ű������� ���� �˾Ƽ� ������
	// �����ڸ� ���� ������ ��� ����ڴ� ���ϳ� �����ڴ� ���ŷο� ���� -> �ʱ�ȭ �ϴ� �ڵ带 ������ ����ؾ��� (������ ������ �� ���� ����)
	// -> " ������ ���� " �� ���� -> ������ �ʱ�ȭ ��Ͽ��� �ٸ� �����ڸ� �߰��� �θ� �� ����
	CMyData a(10);
	CMyData b(3, 4);

	cout << a.GetData() << endl;
	cout << b.GetData() << endl;


	//������ ����
	CMyPoint ptBegin(110);
	ptBegin.Print();

	CMyPoint ptEnd(50, 250);
	ptEnd.Print();

	return 0;
}