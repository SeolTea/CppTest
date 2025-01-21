#include "pch.h"
#include <iostream>
#include "MyProjectCpp2.h"

int main(void) {

	// �ν��Ͻ��� �������� �����ϴ� ���
	// ���� ���� : �ʿ��Ҷ����� �����Ѵ�.
	int* pData = new int;

	// �ʱ갪�� ����ϴ� ���
	int* oData = new int(10);

	*pData = 5;

	std::cout << *pData << "+" << *oData << std::endl;
	// ������ + ������ = �������.

	delete pData;
	delete oData;


	int* arr = new int[5];
	for (int i = 0; i < 5; ++i) {
		arr[i] = (i + 1) * 10;
	}

	for (int i = 0; i < 5; ++i) {
		std::cout << arr[i] << std::endl;
	}

	delete[] arr;

	// ����� ������, �����͸� ������ �� ����.
	// int *pData = &3; - �Ұ���
	// int &pData = 3; - ����� ���� ���� �Ұ���
	// int &pData; - ���� ������ �����Ƿ� �Ұ���

	// ������ ���� ���

	int nData = 10;

	// nData �� ���� ������ ����
	int& ref = nData;

	//�������� ���� �����ϸ� ������ �����.
	ref = 20;
	std::cout << nData << std::endl;

	// �����Ͷ� �����ڶ� ���
	int* pnData = &nData;
	*pnData = 30;

	std::cout << nData << std::endl;

	int lData = 0;
	TestFunc(lData);

	std::cout << lData << std::endl;

	// & �� �ּ� �������� ���� �ְ� �������� ���� ����.
	// �������� ��� ������ ��´�.

	int x = 10, y = 20;
	Swap(x, y);

	std::cout << x << "/" << y << std::endl;

	// c++ ������ ������ ���� ������ �������.

	//r-value ���� ����
	int nInput = 0;
	std::cout << "Input Number : ";
	std::cin >> nInput;

	// ��� �������� ������� �ӽ� ��ü�� ���� r-value ����
	int&& rdata = nInput + 5;
	std::cout << rdata << std::endl;

	// �Լ� ��ȯ���� ������� �ӽ� ��ü�� ���� r-value ����
	int&& result = TestFunc2(10);
	std::cout << result << std::endl;

	result += 10;
	std::cout << result << std::endl;

	//r-value �� �ӽ� ����̴�.
	// ���꿡 Ȱ���� ���� �Ҹ��Ѵ�.
	// �� ����� ��󿡰� ������ �ο��� �����ϴ�.
	// 3+4+5 ���� 3+4 �� ������� �ӽð���̰� �� �ӽð���� +5 �� �ϴ� ���̴�.

	// ������� for ��
	// ���� for ���� Ƚ���� �߽����� �ݺ� => �迭 ����� ������ ����� ��� for ���� �����ؾ��ϴ� ��� ����
	// ������� for ���� ��� ������ ���� �����ϱ⿡ ��� ������ �ڵ����� ������.

	int aList[5] = { 10,20,30,40,50 };

	// ���� for ��
	for (int i = 0; i < 5; i++) {
		std::cout << aList[i] << std::endl;
	}

	std::cout << std::endl;

	//���� ��� for ��
	// n�� aList ����� ���� �����Ѵ�.
	for (auto n : aList) {
		std::cout << n << std::endl;
	}

	std::cout << std::endl;

	// n �� �� ��ҿ� ���� ������.
	for (auto& n : aList) {
		std::cout << n << std::endl;
	}

	return 0;
}

void TestFunc(int& rParam) {
	rParam = 100;
}

void Swap(int& a, int& b) {
	int nTmp = a;
	a = b;
	b = nTmp;
}

int TestFunc2(int nParam) {
	int nResult = nParam * 2;
	return nResult;
}