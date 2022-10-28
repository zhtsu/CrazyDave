#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

class MyBrush {
	public:
		MyBrush();

	public:
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

	private:
		void setOriginPosition(int originX, int originY);//���ù����ʼλ��

	private:
		HANDLE hOut_;//�½���� hOut
		COORD pos_;//�洢����ṹ��
};

MyBrush::MyBrush() {
	//���캯��
	hOut_=GetStdHandle(STD_OUTPUT_HANDLE);//ʵ������� hOut
	COORD pos_= {0,0};
}

void MyBrush::setOriginPosition(int originX, int originY) {
	//���ù����ʼλ��
	pos_.X = originX;
	pos_.Y = originY;
	SetConsoleCursorPosition(hOut_,pos_);
}

void MyBrush::draw_in_lateral(int originX, int originY, char needDraw, int number, double gapSeconds) {
	//����ʼλ���ں�����������ַ�
	setOriginPosition(originX, originY);

	for (int i = 0; i < number; i++) {
		cout << needDraw;
		Sleep(gapSeconds * 1000);
	}
}

void MyBrush::draw_in_vertical(int originX, int originY, char needDraw, int number, double gapSeconds) {
	//��ֱ����
	setOriginPosition(originX, originY);

	for (int i = 0; i < number; i++) {
		cout << needDraw;
		originY++;
		setOriginPosition(originX, originY);
		Sleep(gapSeconds * 1000);
	}
}

void MyBrush::draw_in_lateral(int originX, int originY, string needDraw, int number, double gapSeconds) {
	//����ʼλ���ں�����������ַ���
	setOriginPosition(originX, originY);

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < needDraw.length(); j++) {
			cout << *(needDraw.begin() + j);
			Sleep(gapSeconds * 1000);
		}
	}
}

void MyBrush::draw_in_vertical(int originX, int originY, string needDraw, int number, double gapSeconds) {
	//��ֱ����
	setOriginPosition(originX, originY);

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < needDraw.length(); j++) {
			cout << *(needDraw.begin() + j);
			originY++;
			setOriginPosition(originX, originY);
			Sleep(gapSeconds * 1000);
		}
	}
}

void MyBrush::earse_in_lateral(int originX, int originY, int number) {
	//�������
	setOriginPosition(originX, originY);

	for (int i = 0; i < number; i++) {
		cout << " ";
		originX++;
		setOriginPosition(originX, originY);
	}
}

void MyBrush::earse_in_vertical(int originX, int originY, int number) {
	//�������
	for (int i = 0; i < number; i++) {
		cout << " ";
		originY++;
		setOriginPosition(originX, originY);
	}
}

void MyBrush::drawRectangle(int left, int top, int right, int bottom, char needDraw) {
	//ͨ�����þ��ε����ϽǺ����½ǻ��ƾ��α߿�
	draw_in_lateral(left, top, needDraw, (right - left));
	draw_in_lateral(left, bottom, needDraw, ((right - left) + 1));
	draw_in_vertical(left, top, needDraw, (bottom - top));
	draw_in_vertical(right, top, needDraw, (bottom - top));
}

void MyBrush::earseRectangle(int left, int top, int right, int bottom) {
	//�������α߿�
	earse_in_lateral(left, top, ((right - left) + 1));
	earse_in_lateral(left, bottom, ((right - left)));
	earse_in_vertical(left, top, ((bottom - top)));
	earse_in_vertical(right, top, ((bottom - top)));
}

void MyBrush::drawTriangle(int anchorX, int anchorY, char needDraw, int layers) {
	//ͨ������λ�ú������εĲ������������� 
	setOriginPosition(anchorX, anchorY);
	
	for (int i = 0; i < layers+1; i++) {
		for (int j = layers - i; j > 0; j--) {
			cout << " "; 
		}
		for (int k = 0; k < i; k++) {
			cout << " " << needDraw;
		}
		anchorY++;
		setOriginPosition(anchorX, anchorY);
	}
}

void MyBrush::earseTriangle(int anchorX, int anchorY, int layers) {
	//����������
	setOriginPosition(anchorX, anchorY);
	
	for (int i = 0; i < layers+1; i++) {
		for (int j = layers - i; j > 0; j--) {
			cout << " "; 
		}
		for (int k = 0; k < i; k++) {
			cout << " " << " ";
		}
		anchorY++;
		setOriginPosition(anchorX, anchorY);
	}
}

int main() {
	system("mode con cols=75 lines=25");

	MyBrush one;
	
	one.draw_in_lateral(30, 10, "��ʼ����", 1, 1);
	one.earse_in_lateral(30, 10, 4);
	one.drawRectangle(0, 0, 74 , 24, '@');
	one.earseRectangle(0, 0, 74 , 24);
	one.drawTriangle(10, 10, '*', 9);
	one.earseTriangle(10, 10, 9);
	one.draw_in_lateral(30, 10, "�������");
	
	while (!getch()) {

	}

	return 0;
}
