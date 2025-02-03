#include "pch.h"
#include "MyString.h"
#include <iostream>
using namespace std;

CMyString::CMyString() : m_pszData(nullptr), m_nLength(0)
{

}

CMyString::~CMyString() {

}

int CMyString::SetString(const char* pszParam) {
	return 0;
}

const char* CMyString::GetString() {
	return nullptr;
}

void CMyString::Release() {

}
//11
int main(void) {
	CMyString strData;
	strData.SetString("Hello");
	cout << strData.GetString() << endl;

	return 0;
}
