#include <iostream>
#include <string.h>
#include <conio.h>

#include "ZombieHead.h"
#include "PlantHead.h"
#include "CombatHead.h"
#include "MyBrushHead.h"
#include "MyHead.h"
#include "MyFileHead.h"

using namespace std;

void startGameOfFile() {
	//���ļ�����
	MyFile file("GameMSG.dat");
	int level;
	
	try {
		level = file.getFileData(); 
	} catch (bool) {
		showMainMenu();	
	}
	
	showNeededLevel(level); 
}

void showNeededLevel(int level) {
	//���� level ��ֵ��ȡ��ͬ�Ĺؿ� 
	Apple apple("ƻ��", 10, 10, 3, 2);
	Pear pear("����", 10, 10, 3, 2);
	ApplePear applePear ("ƻ����", 5, 20, 6, 6, 6);
	
	if (level == 1) {
		showOneLevel();
		showPlantAttributeInGame(&applePear);
		OneLevelMovePlant(&applePear);
	} else if (level == 2) {
		showTwoLevel();
		showPlantAttributeInGame(&applePear);
		twoLevelMovePlant(&applePear);
	} else {
		
	}
}

void SaveGame(double level) {
	//������Ϸ�浵 
	MyFile file("GameMSG.dat");
	 
	file.addUserData(level); 
}

void twoLevelBeforeCombat(Plant *plant, int level) {
	//�ڶ��ؿ�ս��ǰ��ʾ 
	MyBrush brush;
	GiantZombie one("����ʬ", 10, 10, 10, 5);
	
	brush.earse_in_lateral(20, 21, 50);
	brush.draw_in_lateral(20, 20, "��ֻ��ʬ��������������� , ����ô��..."); 
	brush.draw_in_lateral(24, 22, "ENTER����       ESC����");
	
	if (isEnterCombat() == true) {
		showTransition();
		displayCombat(&one, plant);
		showWin();
	} else {
		showTwoLevel();
		showPlantAttributeInGame(plant);
		twoLevelMovePlant(plant);
	}
}

void beforeBack(Plant *plant, int level) {
	//������һ����ʾ 
	MyBrush brush;
	
	brush.earse_in_lateral(20, 21, 50);
	brush.draw_in_lateral(24, 20, "ȷ��������"); 
	brush.draw_in_lateral(24, 22, "ENTERȷ��       ESCȡ��");
	
	if (isEnterCombat() == true) {
		showOneLevel();
		showPlantAttributeInGame(plant);
		OneLevelMovePlant(plant);
	} else {
		showTwoLevel();
		showPlantAttributeInGame(plant);
		twoLevelMovePlant(plant);
	}
} 

void twoLevelMovePlant(Plant *plant) {
	//��һ�ظ��ݼ��̼���ֵ�ƶ�ֲ��
	char key;
	COORD pos = {36, 12};
	
	showPlant(36, 12, plant);
	for (; ; key = getch()) {	
		if (key == 72) {
			pos = upMove(pos.X, pos.Y, plant);
		} else if (key == 80) {
			pos = downMove(pos.X, pos.Y, plant);
		} else if (key == 75) {
			pos = leftMove(pos.X, pos.Y, plant);
		} else if (key == 77) {
			pos = rightMove(pos.X, pos.Y, plant);		
		} else {}
		if (pos.X == 53) {
			twoLevelBeforeCombat(plant, 1);
		} else if (pos.X == 20) {
			beforeBack(plant, 1);
		}
	} 
}

void showTwoLevel() {
	//����ڶ��عؿ���ͼ
	MyBrush brush;
	
	system("cls"); 
	brush.draw_in_vertical(0, 0, '@', 25);
	brush.draw_in_vertical(74, 0, '@', 25);//���Ʊ߿�
	brush.drawRectangle(1, 0, 73, 6, '!');
	brush.drawRectangle(1, 18, 73, 24, '!');
	brush. drawTriangle(2, 7, '*', 4);
	brush. drawTriangle(12, 7, '*', 4);
	brush. drawTriangle(2, 12, '*', 4);
	brush. drawTriangle(12, 12, '*', 4);
	brush.draw_in_lateral(8, 12, "������Χ");
	brush. drawTriangle(55, 7, '*', 4);
	brush. drawTriangle(65, 7, '*', 4);
	brush. drawTriangle(55, 12, '*', 4);
	brush. drawTriangle(65, 12, '*', 4);
	brush.draw_in_lateral(61, 12, "�����");
	brush.draw_in_lateral(5, 3, "��ǰλ�ã�����");
	brush.draw_in_lateral(20, 21, "������������һֻ���˽�ʬ..."); 
} 

void OneLevelBeforeCombat(Plant *plant, int level) {
	//��һ�ؿ�ս��ǰ��ʾ 
	MyBrush brush;
	CommonZombie one("��ͨ��ʬ", 10, 3, 3);
	
	brush.earse_in_lateral(20, 21, 50);
	brush.draw_in_lateral(20, 20, "��������һֻ��ͨ��ʬ����ɱ���������֣�"); 
	brush.draw_in_lateral(24, 22, "ENTER����       ESC����");
	
	if (isEnterCombat() == true) {
		showTransition();
		displayCombat(&one, plant);
		showTwoLevel();
		showPlantAttributeInGame(plant);
		twoLevelMovePlant(plant);
	} else {
		showOneLevel();
		showPlantAttributeInGame(plant);
		OneLevelMovePlant(plant);
	}
}

void showWin() {
	//��Ϸʤ������ 
	MyBrush brush;
	
	system("cls");
	brush.drawRectangle(0, 0, 74 , 24, '@');//���Ʊ߿�
	brush.draw_in_lateral(30, 6, "Happy End"); 
	brush.draw_in_lateral(26, 8, "�������������н�ʬ", 1, 0.1); Sleep(900);
	brush.draw_in_lateral(26, 9, "�㷢����������", 1, 0.1); Sleep(900);
	brush.draw_in_lateral(26, 10, "�������Ѿ����Ե���", 1, 0.1); Sleep(900);
	brush.draw_in_lateral(26, 11, "�������һ�������ʬ��", 1, 0.1); Sleep(900);
	brush.draw_in_lateral(26, 12, "��ȰͲ����ɻص��ڶ���...", 1, 0.1); Sleep(900);
	getch();
	gameMain(); 
}

bool isEnterCombat() {
	//�ж�����Ƿ����ս��
	bool flag = true; 
	char key; 
	
	for (; key != '\r' || key != 27; key = getch()) {
		if (key == 27) {
			flag = false; break;
		} else if(key == '\r') {
			break;
		}
	}

	return flag;
}

void showOneLevel() {
	//�����һ�عؿ���ͼ
	MyBrush brush;
	
	system("cls"); 
	brush.draw_in_vertical(0, 0, '@', 25);
	brush.draw_in_vertical(74, 0, '@', 25);//���Ʊ߿�
	brush.drawRectangle(1, 0, 73, 6, '!');
	brush.drawRectangle(1, 18, 73, 24, '!');
	brush. drawTriangle(55, 7, '*', 4);
	brush. drawTriangle(65, 7, '*', 4);
	brush. drawTriangle(55, 12, '*', 4);
	brush. drawTriangle(65, 12, '*', 4);
	brush.draw_in_lateral(62, 13, "����");
	brush.draw_in_lateral(5, 3, "��ǰλ�ã�����");
	brush.draw_in_lateral(20, 21, "�����ǽ�ʬ�ĵ���...�ұ�����̤���"); 
} 

void showPlantAttributeInGame(Plant *plant) {
	//����Ϸ��ͼ����ʾֲ�������
	MyBrush brush; 
	
	brush.draw_in_lateral(32, 2,  "ֲ�");
	brush.draw_in_lateral(50, 2, "����ֵ��");
	brush.draw_in_lateral(30, 4, "��������");
	brush.draw_in_lateral(50, 4, "��������");
	brush.earse_in_lateral(40, 2, 4);
	brush.setOriginPosition(40, 2); cout << plant->getName();
	brush.earse_in_lateral(60, 2, 4);
	brush.setOriginPosition(60, 2); cout << plant->getHP();
	brush.earse_in_lateral(40, 4, 4);
	brush.setOriginPosition(40, 4); cout << plant->getAttack();
	brush.earse_in_lateral(60, 4, 4);
	brush.setOriginPosition(60, 4); cout << plant->getDefence();
}

void showPlant(int originX, int originY, Plant *plant) {
	//�ڵ�ͼ�����ֲ������ , ��ָ��λ�� 
	MyBrush brush;
	
	if (plant->getName() == "ƻ��") {
			brush.draw_in_lateral(originX, originY, "��");
	} else if(plant->getName() == "����") {
			brush.draw_in_lateral(originX, originY, "��");
	} else if(plant->getName() == "ƻ����") { 
			brush.draw_in_lateral(originX, originY, "��");
	} else {}
}

void OneLevelMovePlant(Plant *plant) {
	//��һ�ظ��ݼ��̼���ֵ�ƶ�ֲ��
	char key;
	COORD pos = {5, 12};
	
	showPlant(5, 12, plant);
	for (; ; key = getch()) {	
		if (key == 72) {
			pos = upMove(pos.X, pos.Y, plant);
		} else if (key == 80) {
			pos = downMove(pos.X, pos.Y, plant);
		} else if (key == 75) {
			pos = leftMove(pos.X, pos.Y, plant);
		} else if (key == 77) {
			pos = rightMove(pos.X, pos.Y, plant);		
		} else {}
		if (pos.X == 53) {
			OneLevelBeforeCombat(plant, 1);
		}
	} 
}

COORD upMove(int originX, int originY, Plant *plant) {
    //�����ƶ�ָ��λ�õ��ַ�,���ش洢��ʱ�ַ�����Ľṹ�� 
    MyBrush brush;
	COORD pos; 
	if (originY > 7) {
		brush.earse_in_lateral(originX, originY, 1);
		showPlant(originX, originY - 1, plant);
		brush.setOriginPosition(originX, originY - 1);
		pos.X = brush.getNowX();
		pos.Y = brush.getNowY();
	} else {
		showPlant(originX, originY, plant);
		brush.setOriginPosition(originX, originY);
		pos.X = brush.getNowX();
		pos.Y = brush.getNowY();
	}
	
	return pos;
}

COORD downMove(int originX, int originY, Plant *plant) {
	//�����ƶ�
    MyBrush brush;
	COORD pos;
	
	if (originY < 17) {
		brush.earse_in_lateral(originX, originY, 1);
		showPlant(originX, originY + 1, plant);
		brush.setOriginPosition(originX, originY + 1);
		pos.X = brush.getNowX();
		pos.Y = brush.getNowY();
	} else {
		showPlant(originX, originY, plant);
		brush.setOriginPosition(originX, originY);
		pos.X = brush.getNowX();
		pos.Y = brush.getNowY();
	}
	
	return pos;
}

COORD leftMove(int originX, int originY, Plant *plant) {
    //�����ƶ� 
    MyBrush brush;
	COORD pos;
	
	if (originX > 2) {
		brush.earse_in_lateral(originX, originY, 1);
		showPlant(originX - 1, originY, plant);  
		brush.setOriginPosition(originX - 1, originY);
		pos.X = brush.getNowX();
		pos.Y = brush.getNowY();
	} else {
		showPlant(originX, originY, plant);
		brush.setOriginPosition(originX, originY);
		pos.X = brush.getNowX();
		pos.Y = brush.getNowY();
	}

	return pos; 
}

COORD rightMove(int originX, int originY, Plant *plant) {
	//�����ƶ�
    MyBrush brush;
	COORD pos;
	
	if (originX < 71) {
		brush.earse_in_lateral(originX, originY, 1);
		showPlant(originX + 1, originY, plant);	 
		brush.setOriginPosition(originX + 1, originY);
		pos.X = brush.getNowX();
		pos.Y = brush.getNowY();
	} else {
		showPlant(originX, originY, plant);
		brush.setOriginPosition(originX, originY);
		pos.X = brush.getNowX();
		pos.Y = brush.getNowY();
	}

	return pos;
}

void showTransition() {
	//�����������
	MyBrush brush;
	
	system("mode con cols=75 lines=25");//���� CMD ���ڴ�С
	for (int i = 0; i < 2; i++) {
		system("cls");
		brush.draw_in_lateral(30, 8, "��Ϸ������...");
		brush.draw_in_lateral(30, 10, "�~", 8, 0.1);
	}
} 

void showGameBackground() {
	//���������Ϸ����
	MyBrush brush;
	
	system("cls");
	brush.drawRectangle(0, 0, 74 , 24, '@');//���Ʊ߿�
	brush.draw_in_lateral(20, 8, "��������һ�������տ���ˮ", 1, 0.09); Sleep(900);
	brush.draw_in_lateral(20, 9, "�������ƽʱ�ƺ���һЩ��һ��", 1, 0.09); Sleep(900);
	brush.draw_in_lateral(20, 10, "�����򲻼��ˣ�", 1, 0.09); Sleep(900);
	brush.draw_in_lateral(20, 11, "һ���Ǳ���ʬץ����", 1, 0.09); Sleep(900);
	brush.draw_in_lateral(20, 12, "�������ѡһ��ֲ��ǰȥӪ�ȷ�����...", 1, 0.09); Sleep(900);
	getch();
}

void showSelected(int originX, int originY) {
	//���ѡ���
	MyBrush brush;
	
	brush.draw_in_lateral(originX, originY, ">>");
	brush.draw_in_lateral((originX + 12), originY, "<<");
}

int moveSelected(int originX, int originY, int finishX, int finishY ) {
	//�ƶ�ָ��λ�õ�ѡ��򵽴�Ŀ��λ�� , ���ع������ Y ���� 
	MyBrush brush; 
	
	brush.earse_in_lateral(originX, originY, 2);
	brush.earse_in_lateral((originX + 12), originY, 2);
	brush.draw_in_lateral(finishX, finishY, ">>");
	brush.draw_in_lateral((finishX + 12), finishY, "<<");
	
	return finishY;
}

void displayCombat(Zombie *zombie, Plant *plant) {
	//���ݶ���ָ�벥��ս������ 
	system("cls");
	Combat fight(zombie, plant);
	fight.setDisplayGapSenonds(1.5);
	fight.displayAllCombatLog();
	getch();
	if (plant->getHP() < 0) {
		system("cls");
		MyBrush brush;
		brush.draw_in_lateral(30, 10, "��������!");
		getch();
		showMainMenu(); 
	}
} 

void showPlantAttribute(Plant *plant) {
	//չʾֲ���ɫ���� 
	MyBrush brush;
	
	showPlant(36, 12, plant);
	brush.earse_in_lateral(40, 9, 8);
	brush.setOriginPosition(40, 9); cout << plant->getName();
	brush.draw_in_lateral(30, 20, "ֲ��");
	brush.earse_in_lateral(50, 20, 4);
	brush.setOriginPosition(50, 20); cout << plant->getHP();
	brush.earse_in_lateral(30, 22, 4);
	brush.setOriginPosition(30, 22); cout << plant->getAttack();
	brush.earse_in_lateral(50, 22, 4);
	brush.setOriginPosition(50, 22); cout << plant->getDefence();
}

int selectPlantMoveCommand(Plant *apple, Plant *pear, Plant *applePear) {
	//ֲ��ѡ��˵� �ڸ��ݼ��̼���ֵ�л�ֲ��,���ش�ʱֲ��Ĵ���
	int attempts = 1;//�����жϵ�ǰֲ�� 
	char key; 
	
	for (; key != '\r'; key = getch()) {
		if (key == 75 || key == 77) {
			attempts++;
			if (attempts > 3) {
				attempts -= 3;
			}
		} 
	switch (attempts) {
		case 1:
			showPlantAttribute(apple);
			break;
		case 2:
			showPlantAttribute(pear);
			break;
		case 3:
			showPlantAttribute(applePear);
			break;
		default:{
			break;
		}	
	}
	} 
	
	return attempts;
}

void selectPlantCommand(Plant *apple, Plant *pear, Plant *applePear) {
	//ѡ��ֲ����������Ӧ 
	switch (selectPlantMoveCommand(apple, pear, applePear)) {
		case 1:
			showOneLevel();
			showPlantAttributeInGame(apple);
			OneLevelMovePlant(apple);
			break;
		case 2:
			showOneLevel();
			showPlantAttributeInGame(pear);
			OneLevelMovePlant(pear);
			break;
		case 3:
			showOneLevel();
			showPlantAttributeInGame(applePear);
			OneLevelMovePlant(applePear);
			break;
		default:{
			break;
		}	
	}
}

void showSelectPlant(Plant *apple, Plant *pear, Plant *applePear) {
	//��ʾֲ��ѡ�����
	MyBrush brush;
	
	system("cls");//������һ������ 
	brush.draw_in_vertical(0, 0, '@', 25);
	brush.draw_in_vertical(74, 0, '@', 25);//���Ʊ߿�
	brush.drawRectangle(1, 0, 73, 6, '!');
	brush.drawRectangle(1, 18, 73, 24, '!');
	brush.draw_in_lateral(30, 3, "��ѡ�������ֲ��");
	brush.draw_in_lateral(30, 9, "ֲ��������");
	brush.draw_in_lateral(22, 20, "���壺");
	brush.draw_in_lateral(40, 20, "����ֵ��");
	brush.draw_in_lateral(20, 22, "��������");
	brush.draw_in_lateral(40, 22, "��������");
	brush.draw_in_lateral(5, 12, "<<<"); 
	brush.draw_in_lateral(67, 12, ">>>");
	
	selectPlantCommand(apple, pear, applePear); 
}

void showMainMenu() {
	//չʾ���˵� 
	MyBrush brush;
	
	system("cls");//������һ������ 
	brush.drawRectangle(0, 0, 74 , 24, '@');//���Ʊ߿�
	brush.draw_in_lateral(30, 5, "GoneCrazyDave");
	brush.draw_in_lateral(32, 8, "��ʼ��Ϸ");
	brush.draw_in_lateral(32, 10, "��ȡ�浵");
	brush.draw_in_lateral(32, 12, "�˳���Ϸ");
	brush.draw_in_lateral(27, 16, "����ѡ�� ENTER����");
	
	mainMenuCommand(); 
}

int mainMenuMoveCommand() {
	// ���˵� �ڸ��ݼ��̼���ֵ�ƶ����,���ش�ʱ�����ָ����Ĵ���
	int attempts = 1;//�����ж���ҵĲ��� 
	char key; 
	
	showSelected(29,8);//���ƹ�� 
	for (; key != '\r'; key = getch()) {
		if (key == 72) {//Ϊ ����ʱ
			if (attempts == 1) {
			} else if (attempts == 2){
				moveSelected(29, 10, 29, 8);
				attempts = 1;
			} else {
				moveSelected(29, 12, 29, 10);
				attempts = 2;
			}
		} 
		else if (key == 80) {//Ϊ ����ʱ 
			if (attempts == 1) {
				moveSelected(29, 8, 29, 10);
				attempts = 2;
			} else if (attempts == 2) {
				moveSelected(29, 10, 29, 12);
				attempts = 3;
			} else {
			}
		} else {
			continue;
		}
	} 
	
	return attempts; 
}

void mainMenuCommand() {
	//��Ӧ���˵��ļ������� 
	Apple apple("ƻ��", 10, 10, 3, 2);
	Pear pear("����", 10, 10, 3, 2);
	ApplePear applePear ("ƻ����", 5, 20, 6, 6, 6);
	
	switch (mainMenuMoveCommand()) {
		case 1:
			showGameBackground(); 
			showSelectPlant(&apple, &pear, &applePear);
			break;
		case 2:
			startGameOfFile();
			break;
		case 3:
			system("cls");
			SaveGame(2); 
			exit(1); break;
		default: {
		}
	}
} 

void gameMain() {
	//��Ϸ��ڣ���Ϸ����Ҫ�߼�ʵ��
	showTransition();
	showMainMenu(); 
}
