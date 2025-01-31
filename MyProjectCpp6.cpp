#include "pch.h"
#include "MyProjectCpp6.h"
#include <iostream>
using namespace std;

class CMyData {
	// �⺻ ���� ���� ������ 'private'
	int m_nData;

public :
	int GetData(void) { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	// Get/ Set ���θ� m_nData ���� ����� �� ������ ��Ÿ�� - ����ڴ� Get,Set�� ����ؾ���
};

class CTestConstrutor {
public :
	CTestConstrutor(){
		cout << "CTestConstrutor()" << endl;
	}

	~CTestConstrutor() {
		cout << "~CTestConstrutor()" << endl;
	}
};

// ����Ʈ �������� ����
class CTestParam {
	int m_nData;
public:
	CTestParam(int nParam) : m_nData(nParam) {
		cout << "CTestParam()" << endl;
	}
	~CTestParam() {
		cout << "~CTestParam" << m_nData << endl;
	}
};

class CTestNewDel {
	int m_nData;
public:
	CTestNewDel() {
		cout << "CTestNewDel" << endl;
	}

	~CTestNewDel() {
		cout << "~CTestNewDel" << endl;
	}
};

class CTestRef {
	
public:
	CTestRef(int &rParam) : m_nData(rParam) { };
	int GetData(void) { return m_nData; }

private:
	int& m_nData;
};
//CTestConstrutor a;
// ���� ������ ���� �� main �Լ����� ���� �����ڰ� ����ȴ�.


//8
int main(void) {

	//���� ���� ������ : �����ڰ� ����ڰ� �̿��� �� �ִ� �ڵ带 �����ϴ� �뵵�� Ȱ��
	//Why ? : ����ڴ� Ŭ������ ������ �����ں��� ��������� �𸣱⿡ �ʿ��� �κи� ������ �� �ֵ��� �ϱ� ����
	//Public : ����� ���� ��� �ܺ� ������ ���
	//Protected : ����� ���� �ܺ� ������ ���ܵǳ�, ��� ���迡 �ִ� �Ļ� Ŭ���������� ������ ���
	//Private : ����� ���� �ܺ� ���� �� �Ļ� Ŭ���������� ���ٵ� ��� ���� (�⺻��)
	CMyData data;
	data.SetData(10);
	cout << data.GetData() << endl;

	//data.m_nData; : private �̱� ������ ���� �߻�

	// ������ , �Ҹ��� : ��ü�� ���� �� �Ҹ�� �� ' �ڵ����� ' ȣ��
	// -> �Լ��ӿ��� �ұ��ϰ� ' ��ȯ ������ ���� '
	// �����ڴ� ���� ���� ���� , �Ҹ��ڴ� �Ұ���
	// 
	// �Ű������� �ϳ��� ���� ������ = ����Ʈ ������
	// -> ����Ʈ �����ڴ� ������� �ʾƵ� �����Ϸ��� �˾Ƽ� ���� (��, �ƹ��� �ڵ嵵 �߰����� ����) => ������, �Ҹ��ڰ� ���� Ŭ������ ����.

	
	CTestConstrutor a;				// ��ü ���� ����
	cout << "Begin a" << endl;

	// ���� ������ ����� ��� ������ ������ �ڵ� �Ҹ�

	CTestConstrutor b;				// ������ ���� ����
	cout << "Begin b" << endl;

	cout << "End" << endl;

	// ����Ʈ �������� ����
	cout << "Begin 1" << endl;
	CTestParam a1(1);
	cout << "Begin 2" << endl;
	CTestParam b1(2);
	cout << "End" << endl;

	// �Ҹ��ڰ� ������ ���� �ֱٿ� ������� ��ü���� �Ҹ��Ų�� ( b1 �Ҹ� ���� a1 �Ҹ� )

	// ���� ��ü�� ������ �Ҹ�
	// Ŭ������ �ν��Ͻ��� �����ؼ� ���� -> new ������ ���� ���� ���� ����
	// -> ���� ������ ��ü�� Delete �����ڷ� �����ؾ���

	cout << "Begin" << endl;

	CTestNewDel* pData = new CTestNewDel;
	cout << "Test" << endl;
	delete pData;
	cout << "End" << endl;

	// Delete �� �迭�� ������ ��ü�� �ݵ�� �迭�� �����ؾ���.

	CTestNewDel* pData2 = new CTestNewDel[3];
	delete[] pData2;
	cout << "End" << endl;
	//delete pData2;
	// �迭�� ������ ��ü�� �迭�� �������� ������ �ϳ��� �Ҹ��ϰ� �������� �޸𸮿� �״�� ���ƹ���
	// -> �ſ� �����ؾ��� ����
	//  => �� ������ �޸� ��(leak 3) ���׸� ���� ( Ŭ������ �ƴ� �⺻ �ڷ����� �迭�� �迭�� �������� �ʾƵ� ������ �߻������� ������, �����ؾ���)


	// �������� ��� �ʱ�ȭ
	// Ŭ������ ��� ������ ���� �������� ������ �� ���� -> �ݵ�� ����� ���ÿ� �ʱ�ȭ�� ������� (������ �ʱ�ȭ ����� �̿�)


	return 0;
}