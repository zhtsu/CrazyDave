#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

class MyFile {
	public:
		MyFile();
		MyFile(char *pFile);//���캯��

	public:
		void setFileAddress(char *pFile);//������Ҫ�򿪵��ļ�·�� 
		void addUserData(const string msg);
		void addUserData(const double msg);
		int getFileData();         //���ļ���ȡһ�� int ������
		void displayFileData(void);//չʾ�ļ�����������
		void deleteFileData(void); //ɾ���ļ��ڵ�����

	private:
		void showError();//�ļ��򿪴�����

	private:
		char *pFileAddress_;//�û�������ļ���ַ
};
