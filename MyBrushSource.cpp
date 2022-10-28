#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "MyBrushHead.h"

using namespace std;

MyBrush::MyBrush() {
	//���캯��
	hOut_ = GetStdHandle(STD_OUTPUT_HANDLE);//ʵ������� hOut
	COORD pos_ = {0,0};
}

MyBrush::MyBrush(int originX, int originY) {
	//���캯�����ù����ʼλ��
	pos_.X = originX;
	pos_.Y = originY;
	SetConsoleCursorPosition(hOut_,pos_);
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

int MyBrush::getNowX() {
	//���ص�ǰ X ���� 
	return pos_.X;
}

int MyBrush::getNowY() {
	//���ص�ǰ Y ���� 
	return pos_.Y;
}

