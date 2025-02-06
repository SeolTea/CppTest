//14
#include "pch.h"
#include "MyProjectCpp10.h"
#include <iostream>
using namespace std;

// ���� ������
class CMyDataCopy {
public:
	CMyDataCopy() { cout << "CMyDataCopy" << endl; }

	// ���� ������ ���� �� ����
	CMyDataCopy(const CMyDataCopy& rhs) 
		// : m_nData(rhs.m_nData)
	{
		this->m_nData = rhs.m_nData;
		cout << "CMyDataCopy(const CMyDataCopy &)" << endl;
	}

	int GetData(void) const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private :
	int m_nData = 0;
};

// �Լ� ȣ��� ���� ������
// �Լ� ���·� ȣ���� ���� Ŭ������ �Ű������� ���Ǵ� ���, ��ȯ �������� ���Ǵ� ��� �� ��������

class CTestDataCopy {
public :
	CTestDataCopy(int nParam) : m_nData(nParam) { cout << "CTestDataCopy(int)" << endl; }
	CTestDataCopy(const CTestDataCopy& rhs) : m_nData(rhs.m_nData) { cout << "CTestDataCopy(const CTestDataCopy &)" << endl; }

	// �б� ������ ����� �޼���
	int GetData() const { return m_nData; }

	// ��� ������ ���⸦ �õ��ϴ� �޼���
	void SetData(int nParam) { m_nData = nParam; }
private :
	int m_nData = 0;
};

// ���� ������ ����

class CTestDataCopyDel {
public:
	CTestDataCopyDel(int nParam) : m_nData(nParam) { cout << "CTestDataCopyDel(int)" << endl; }
	//CTestDataCopyDel(const CTestDataCopy& rhs) : m_nData(rhs.m_nData) { cout << "CTestDataCopyDel(const CTestDataCopy &)" << endl; }

	CTestDataCopyDel(const CTestDataCopyDel& rhs) = delete;

	// �б� ������ ����� �޼���
	int GetData() const { return m_nData; }

	// ��� ������ ���⸦ �õ��ϴ� �޼���
	void SetData(int nParam) { m_nData = nParam; }
private:
	int m_nData = 0;
};

// �Ű������� CTestDataCopy Ŭ���� �����̹Ƿ� ���� �����ڰ� ȣ��
void TestFunc(CTestDataCopy param) {
	cout << "TestFunc()" << endl;

	// ��ȣ���� �Լ����� �Ű����� �ν��Ͻ��� ���� ����.
	param.SetData(20);
}

// ���� ������ ����
void TestFuncDel(CTestDataCopyDel param) {
	cout << "TestFuncDel()" << endl;

	// ��ȣ���� �Լ����� �Ű����� �ν��Ͻ��� ���� ����.
	param.SetData(20);
}

int main(void) {

	// ���� ������ : ��ü�� ���纻�� ������ �� ȣ��Ǵ� ������
	// Ŭ������ �ۼ��� �� ���� �����ڸ� �����ϸ� ����Ʈ ������ó�� �����Ϸ��� �˾Ƽ� ������� ( �� �ʿ��� �� �ƴϸ� ������ �ʿ� ���� )
	// ���� �����ڸ� �������� ������ �ɰ��� ���� �߻�
	// -> Ŭ���� ���ο��� �޸𸮸� ���� �Ҵ� �� �����ϰ� �̸� ��� ������ ������ �����ϰ� �ִ� ���

	// ����Ʈ ������ ȣ��
	CMyDataCopy a;
	a.SetData(10);

	// ���� ������ ȣ��
	CMyDataCopy b(a);
	cout << b.GetData() << endl;
	// ���� ���� : a

	// �Լ� ȣ�� �� ���� ������
	cout << "***** Begin *****" << endl;
	CTestDataCopy aa(10);
	TestFunc(aa);
	// ��ü�� �ΰ� ������ -> ���� ������ -> �� ��ü�� �� �� �ִ� ���� ������ �ϳ��� ��������

	// �Լ� ȣ�� �� aa ���� ���
	cout << "aa : " << aa.GetData() << endl;

	cout << "***** End *****" << endl;

	// ���� ������ ����

	cout << "***** Begin *****" << endl;
	CTestDataCopyDel aaa(10);
	//TestFuncDel(aaa);
	// ���� �����ڸ� ����� ��� ���� ó���� �ǹ���

	// �Լ� ȣ�� �� aa ���� ���
	cout << "aaa : " << aaa.GetData() << endl;

	cout << "***** End *****" << endl;

	return 0;
}