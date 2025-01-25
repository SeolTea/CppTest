//5
#include "pch.h"
#include "MyProjectCpp4.h"
#include <iostream>

using namespace std;

namespace TEST {
	int g_nData = 100;

	void TestFunc(void) {
		std::cout << "TEST::TestFunc()" << std::endl;
	}
}

namespace TEST2 {
	int g_nData = 100;

	namespace DEV {
		int g_nData = 200;

		namespace WIN {
			int g_nData = 300;
		}
	}
}

// ���ӽ����̽� ���� ����

void TestFuncOver(void) {			// --> �ش� �Լ��� ���ӽ����̽��� ������ (����)
	cout << "::TestFunc()" << endl;
}

namespace TESTOVER {
	void TestFuncOver(void) {
		cout << "TESTOVER::TestFunc()" << endl;
	}
}

namespace MYDATA {
	void TestFuncOver(void) {
		cout << "DATAOVER::TestFunc()" << endl;
	}
}

int tData = 200;

//namespace SearchTest {
//	int tData = 100;				// SearchTest ���� ���ӽ����̽� �ȿ� �ִ� tData�� ���� �ֱٿ� ������
//	void TestFunc(void) {
//		std::cout << tData << std::endl;  // �׷��⿡ 100 ���
//	}
//}

namespace SearchTest {
	
	void TestFunc(void) {
		std::cout << tData << std::endl;  // SearchTest ���� ���� ������ ���� �ֱٿ� �����Ǿ��⿡ 200 ���
	}

	int tData = 100;				

}
//
//int tData2 = 200;	// ������ ���� �ʾҴٰ� ���� (�ּ� ó�� �ʼ�)
//namespace SearchTest {
//	
//	void TestFunc(void) {
//		std::cout << tData2 << std::endl;  // tData2 �� ����� ���� ���⿡ ������ ����
//	}
//
//
//	int tData2 = 100;
//}

// ���� ��� ����
int nData(20);

using namespace TEST;

// ���� �Լ��� ���ӽ����̽��� ������ �ȵ�
int main(void) {
	TEST::TestFunc();			// ���ӽ����̽��� ������ ��� ���� ���� ������ (::) �� �̿��� ��� 
	std::cout << TEST::g_nData << std::endl;

	// using ���� �Ἥ �̸� �����߱⿡ �����ص� �����ϴ�.
	TestFunc();
	cout << g_nData << endl;

	// ���ӽ����̽��� ��ø : ���ӽ����̽� �ȿ� �������� ���ÿ� ���� ���� �ְ� �ϳ��� ���ӽ����̽� �ȿ� �� �ٽ� ���ӽ����̽��� ���� ���� ����.
	cout << TEST2::g_nData << endl;
	cout << TEST2::DEV::g_nData << endl;
	cout << TEST2::DEV::WIN::g_nData << endl;

	// ���ӽ����̽� ���� ����
	TestFuncOver();		// ������ ����
	::TestFuncOver();	// ����� ����
	TESTOVER::TestFuncOver();
	MYDATA::TestFuncOver();


	// ù ��° ���� : �ĺ��� �˻� ����

	//���� ��� ����

	int nData(10);
	cout << nData << endl; // �������� 20�� �����߾ 10 ��µ� , ���� main ��� �������� ���� ã�� ����

	// �� ��° ���� : ���� ��� ����

	int nInput = 0;
	cout << "11 �̻��� ������ �Է��ϼ���." << endl;
	cin >> nInput;

	if (nInput > 10) {
		cout << nInput << endl;			// if ���� ���� ������ ���� ����� main ���� ã�� ( �ִ� Ȯ�� ������ �Լ� ��ü������ ���� ) -> ���� �Լ� ��ü�� ����� ���ӽ����̽� Ȥ�� Ŭ���� �������� Ȯ���
	}
	else {
		cout << "ERROR" << endl;
	}


	// �� ��° ���� : ���� �ֱٿ� ����� ���� ���� -> ���ӽ����̽����� ���� ��ġ�� �� �켱�̴�.

	SearchTest::TestFunc();

	return 0;
}

