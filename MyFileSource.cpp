#include <fstream>
#include <iostream>
#include <string.h>
#include <Windows.h>

#include "MyFileHead.h" 

using namespace std;

MyFile::MyFile() {}//�޲ι��캯��

MyFile::MyFile(char *FileAddress) {
	//�вι��캯�������û�ָ�����ļ���ַ��ֵ���ļ�ָ��
	pFileAddress_ = FileAddress;
}

void MyFile::setFileAddress(char *pFile) {
	//�޲ι��������������Ҫ�򿪵��ļ���·��
	pFileAddress_ = pFile;
}

void MyFile::showError() {
	//���ļ�������
	MessageBox(NULL, "�ļ���ʧ�ܣ�", "��ʾ", MB_ICONEXCLAMATION);
	throw false;
}

void MyFile::addUserData(const string msg) {
	//���ļ�д���ַ��� string ��������
	ofstream File(this->pFileAddress_, ios::app);

	if (! File.is_open()) {
		showError();

	} else {
		File << msg << endl;
	}

	File.close();
}

void MyFile::addUserData(const double msg) {
	//���ļ�д��˫���� double ��������
	ofstream File(this->pFileAddress_, ios::app);

	if (! File.is_open()) {
		showError();

	} else {
		File << msg << endl;
	}

	File.close();
}

int MyFile::getFileData() {
	//���ļ���ȡһ�� int ������
	int myData;

	ifstream File(this->pFileAddress_, ios::in);

	if (! File.is_open()) {
		showError();

	} else {
		File >> myData;
	} 

	File.close();
	
	return myData;
} 

void MyFile::displayFileData(void) {
	//չʾ�ļ�����������
	string myString;

	ifstream File(this->pFileAddress_, ios::in);

	if (! File.is_open()) {
		showError();

	} else {
		while (File >> myString) {
			cout << myString << endl;
		}
	} 

	File.close();
}

void MyFile::deleteFileData(void) {
	//����ļ��ڵ�����
	fstream File(this->pFileAddress_, ios::out);
	File.close();
}

