#include "pch.h"
#include "Quiz_2.h"
#include <iostream>

using namespace std;

int nDataQuiz = 200;

namespace TESTQuiz {
	int nData = 100;
	void TestFunc(void) {
		cout << nDataQuiz << endl;
	}
}

int main(void) {

	//Quiz - 1
	//int TestFunc(int nParam1 = 5, int nParam2, int nParam3 = 10)
	//	=> �߰� �Ű������� ����Ʈ������ �� �� ����.
	//int TestFunc(int nParam1 = 5, int nParam2)
	//	=> ������ �Ű��������� ����Ʈ������ �־��Ѵ�.

	//Quiz - 2
	//b�� ����Ʈ���̶� ���� a ���� ������ �Ǽ� ��ȣ������.

	//Quiz - 3
	// ���� Ÿ���� �ϳ��� �Լ��� ����� �� �ֱ� ������

	// Quiz - 4
	// �Լ� ȣ��� ���� ������� �غ�

	// Quiz - 5
	// ���ӽ����̽��� �Ź� �ۼ��ϱ� �ȴٸ� �̸� ( using ) ������ �ϴ� ���� �����ϴ�.

	// Quiz -6
	TESTQuiz::TestFunc();

	return 0;
}


