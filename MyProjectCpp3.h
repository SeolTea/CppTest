#pragma once
#define MYTYPE_A 100
#define MYTYPE_B 200
// 매개변수 하나
// 
//int TestFuncDef(int nParam = 10);
int TestFuncDef(int = 10);
// 위 아래 TestFuncDef 모두 같은 의미.
// 아래와 같이 선언 시 함수 원형(정의 부분)이 뭔지 알 수가 없음 - 되도록 안쓰는걸 추천

//매개변수 둘

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
inline int AddNew(int a, int b);
