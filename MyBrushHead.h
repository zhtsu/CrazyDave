#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

class MyBrush {
	public:
		MyBrush();
		MyBrush(int originX, int originY);

	public:
		//���ù����ʼλ��
		void setOriginPosition(int originX, int originY);
		//����ʼλ�ú������ϰ�Ҫ������ַ����ַ�������������������͵����ַ�����ļ��ʱ�䣨������
		void draw_in_lateral(int originX, int originY, char needDraw, int number = 1, double gapSeconds = 0);
		void draw_in_lateral(int originX, int originY, string needDraw, int number = 1, double gapSeconds = 0);
		//��ֱ����
		void draw_in_vertical(int originX, int originY, char needDraw, int number = 1, double gapSeconds = 0);
		void draw_in_vertical(int originX, int originY, string needDraw, int number = 1, double gapSeconds = 0);
		//����ʼλ�ú��������ָ���������ַ���
		void earse_in_lateral(int originX, int originY, int number = 1);
		//��ֱ����
		void earse_in_vertical(int originX, int originY, int number = 1);
		//���޶���Χ��ʹ��һ���ַ����ƾ��α߿�
		void drawRectangle(int left, int top, int right, int bottom, char needDraw);
		//�������α߿�
		void earseRectangle(int left, int top, int right, int bottom);
		//��ָ��λ��ʹ��һ���ַ�����һ��������
		//�������ε�ê��Ϊ�Ը������εĵױ�Ϊ������Ϊ��ľ��ε����Ͻǡ� 
		void drawTriangle(int anchorX, int anchorY, char needDraw, int layers);
		//����������
		void earseTriangle(int anchorX, int anchorY, int layers);
		//���ش�ʱ�����ֵ
		int getNowX();
		int getNowY(); 

	private:
		HANDLE hOut_;//�½���� hOut
		COORD pos_;//�洢����ṹ��
};
