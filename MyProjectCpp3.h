#pragma once
#define MYTYPE_A 100
#define MYTYPE_B 200
// �Ű����� �ϳ�
// 
//int TestFuncDef(int nParam = 10);
int TestFuncDef(int = 10);
// �� �Ʒ� TestFuncDef ��� ���� �ǹ�.
// �Ʒ��� ���� ���� �� �Լ� ����(���� �κ�)�� ���� �� ���� ���� - �ǵ��� �Ⱦ��°� ��õ

//�Ű����� ��

int TestFuncDef2(int nParam1, int nParam2 = 2);

int CalcLayout(int nWidth, int nHeight, int nType = MYTYPE_A);

int Add(int a, int b, int c);
int Add(int a, int b);
double Add(double a, double b);

//void TestError(int a);
//void TestError(int a, int b = 10);

template <typename T>
T TestFuncTemp(T a);

template <typename T>
T AddTmp(T a, T b);

int Add2(int a, int b);
inline int AddNew(int a, int b);12