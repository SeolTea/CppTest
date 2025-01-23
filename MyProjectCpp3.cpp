//4
#include "pch.h"
#include <iostream>
#include <cstdio>
#include "MyProjectCpp3.h"

#define MYTYPE_A 100
#define MYTYPE_B 200

#define ADD(a,b)((a)+(b))

int main(void) {
	
	// �Ű����� �ϳ� ����Ʈ
	
	//ȣ���ڰ� ���μ�(=�μ�)�� ������� �ʾ����Ƿ� ����Ʈ�� ����
	std::cout << TestFuncDef() << std::endl;

	//ȣ���ڰ� ���μ�(=�μ�)�� ����Ͽ����Ƿ� �μ��� ����
	std::cout << TestFuncDef(20) << std::endl;

	// �Ű����� �� ����Ʈ
	// ��ȣ���� �Լ��� �Ű������� ����Ʈ ���� ������ �Ű��������� ����ؾ���
	   // => ��, ���� �Ű������� ����Ʈ ������ ����Ϸ��� ������ ������ �Ű������� ���� ����Ʈ������ �����������.( �߰��� �������� ���� �ȵ� )
	std::cout << TestFuncDef2(10) << std::endl;
	std::cout << TestFuncDef2(10, 5) << std::endl;

	std::cout << CalcLayout(10, 5, MYTYPE_A) << std::endl;


	// �Լ� ���� ���� (overloading = �����ε�)
	// ȣ�� �Լ��� �����Ϸ��� ���� �ڵ� ����

	std::cout << Add(3, 4) << std::endl;
	std::cout << Add(3, 4, 5) << std::endl;
	std::cout << Add(3.3, 4.5) << std::endl;

	//��ȯ ���ĸ� �ٸ� ��� ���� ���� �Ұ���
	// int Add(int a, int b)
	// double Add(int a, int b) 
	// �� �� �� ������

	// ȣ�� ��Ģ�� �ٸ� ��� ���� ���� �Ұ���
	// int _cdecl Add(int a, int b)
	// int _stdcall Add(int a, int b)



	// ���� ���ǿ� ����Ʈ �Ű����� ���� ��� �� ��ȣ�� �׽�Ʈ
	//TestError(10); -> ��ȣ�ϱ⿡ ���� �߻�


	// �Լ� ���ø�
	std::cout << "int/t " << TestFuncTemp(3) << std::endl;
	std::cout << "int/t " << TestFuncTemp(3.3) << std::endl;
	std::cout << "int/t " << TestFuncTemp('A') << std::endl;
	std::cout << "int/t " << TestFuncTemp("TestString") << std::endl;
	// ���� ������ �������� �ʾƵ� ���� �ڵ带 Ȯ���� �� ����. 

	std::cout << "add1 " << AddTmp(3,4) << std::endl;
	std::cout << "add2 " << AddTmp(3.3,4.4) << std::endl;
	std::cout << "add3 " << AddTmp<int>(3, 4) << std::endl; // ����ȯ�� ����


	// �ζ��� �Լ� = ��ũ���� ������ �Լ��� ������ ��Ƴ���
	// �Լ��̹Ƿ� �Ű������� ���� ���� ����
	// ������ �ſ� ����
	// ���������� ��ũ��ó�� �Լ� ȣ�� ���� ����

	int a, b;
	scanf_s("%d%d", &a, &b);

	printf("ADD(): %d", ADD(a, b));
	printf("ADD(): %d", Add2(a, b));
	printf("ADD(): %d", AddNew(a, b));


	return 0;
}

// �Ű������� ����Ʈ ���� 10 �̴�.
// ����Ʈ�� ���� �� ��� ���� - �Լ� ���𿡼� ����Ʈ���� �ۼ��ϰ� �ҽ� ���� - �Լ� ���ǿ��� ����Ʈ ���� �ۼ����� �ʴ´�. - �ۼ��ϸ� ������
int TestFuncDef(int nParam) {
	return nParam;
}

//�Ű�����
int TestFuncDef2(int nParam1, int nParam2)
{
	return nParam1 * nParam2;
}

int CalcLayout(int nWidth, int nHeight, int nType) {
	return nWidth * nHeight + nType;
}

int Add(int a, int b, int c) {
	std::cout << "Add(int, int, int) : ";
	return a + b + c;
}

int Add(int a, int b) {
	std::cout << "Add(int, int) : ";
		return a + b;
}

double Add(double a, double b) {
	std::cout << "Add(double double) : ";
	return a + b;
}


// ���� ���ǿ� ����Ʈ �Ű����� ���� ��� �� ��ȣ�� �׽�Ʈ
//void TestError(int a) {
//	std::cout << "TestFunc(int)" << std::endl;
//}
//
//void TestError(int a, int b) {
//	std::cout << "TestFunc(int int)" << std::endl;
//}

template <typename T>
T TestFuncTemp(T a)
{
	std::cout << "�Ű����� a : " << a << std::endl;
	return a;
}

template <typename T>
T AddTmp(T a, T b) {
	return a + b;
}

int Add2(int a, int b) {
	return a + b;
}

inline int AddNew(int a, int b) {
	return a + b;
}
