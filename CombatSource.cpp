#include <iostream>
#include <string.h>
#include "ZombieHead.h"
#include "PlantHead.h"
#include "CombatHead.h"
#include "MyBrushHead.h"

using namespace std;

CombatantMSG CombatantMSG::operator=(Zombie &zombie) {
	//��ֵ����� = ���أ����ڽ� Zombie �� Plant ����ת��Ϊ CombatantMSG ����
	_name = zombie.name_;
	_HP = *zombie.pHP_;
	_attack = zombie.attack_;
	_defence = zombie.defence_;

	return *this;
}

CombatantMSG CombatantMSG::operator=(Plant &plant) {
	//���ڽ� Zombie �� Plant ����ת��Ϊ CombatantMSG ����
	_name = plant.name_;
	_HP = *plant.pHP_;
	_attack = plant.attack_;
	_defence = plant.defence_;

	return *this;
}

bool CombatantMSG::operator== (Zombie &zombie) {
	//ͨ���ж� name �ж� CombatantMSG �ڵ������Ƿ�� Zombie �� Plant �����
	bool flag = true;
	
	if (strcmp(_name.c_str(), zombie.name_.c_str()) != 0) {
		flag = false;
	}
	
	return flag;
}

bool CombatantMSG::operator== (Plant &plant) {
	//ͨ���ж� name �ж� CombatantMSG �ڵ������Ƿ�� Zombie �� Plant �����
	bool flag = true;
	
	if (strcmp(_name.c_str(), plant.name_.c_str()) != 0) {
		flag = false;
	}
	
	return flag;
}

Combat::Combat() {
	//�޲ι���
	flag_ = 1;
	gapSeconds_ = 0;
	zombie_ = NULL;
	plant_ = NULL;
}

Combat::Combat(Zombie *zombie, Plant *plant) {
	//�вι���
	flag_ = 1;
	gapSeconds_ = 0;
	zombie_ = zombie;
	plant_ = plant;
}

void Combat::setCombatant(Zombie *zombie, Plant *plant) {
	//������ս��Ա
	zombie_ = zombie;
	plant_ = plant;
}

void Combat::setDisplayGapSenonds(double gapSeconds) {
	//���ò���ÿ�غ�ս����Ϣ��ʱ����
	gapSeconds_ = gapSeconds;
}

bool Combat::isNoResult() {
	//ͨ������Ѫ���ж���Ϸ�Ƿ����
	bool flag = true;

	if (*(plant_->pHP_) <= 0 || *(zombie_->pHP_) <= 0) {
		flag = false;
	}

	return flag;
}

void Combat::switchSound() {
	//���� flag_ �ĵ�˫���л��غϣ����趨��ǰ�غϽ������ͷ��ط�
	if (flag_ % 2 != 0) {
		offensive_ = *plant_;
		defender_ = *zombie_;
	} else {
		offensive_ = *zombie_;
		defender_ = *plant_;
	}
}

void Combat::calculateHurt() {
	//�Ӵ˴���ʼս�����жϹ������������Ƿ���ڷ������������������������˺��������˺�Ϊ 1
	if (offensive_._attack > defender_._defence) {
		hurt_ = offensive_._attack - defender_._defence;
	} else {
		hurt_ = 1;
	}
} 

void Combat::calculateHP() {
	//�жϳ���ǰ�ķ��ط���������Ѫ�����в��� 
	calculateHurt();
	defender_._HP -= hurt_;
	
	if (defender_ == *plant_) {
		*(plant_->pHP_) -= hurt_;
	} else {
		*(zombie_->pHP_) -= hurt_;
	}
}

void Combat::showHP() {
	//�����ǰʣ��Ѫ�� 
	MyBrush drawHP;
	
	drawHP.earse_in_lateral(15, 10, 50);
	drawHP.setOriginPosition(15, 10);
	cout << plant_->name_ << " HP: "  << *(plant_->pHP_);
	drawHP.setOriginPosition(43, 10);
	cout << zombie_->name_ << " HP: " << *(zombie_->pHP_);
	drawHP.setOriginPosition(15, 6);
} 

void Combat::drawPlant(int namePositionX, int namePositionY, int bodyPositionX, int bodyPositionY) {
	//����ֲ����ս������ 
	MyBrush drawPlant;
	
	drawPlant.draw_in_lateral(namePositionX, namePositionY, plant_->name_);
	drawPlant.drawTriangle(bodyPositionX, bodyPositionY, 'P', 5); 
} 

void Combat::drawZombie(int namePositionX, int namePositionY, int bodyPositionX, int bodyPositionY) {
	//���ƽ�ʬ��ս������ 
	MyBrush drawZombie;
	
	drawZombie.draw_in_lateral(namePositionX, namePositionY, zombie_->name_);
	drawZombie.drawTriangle(bodyPositionX, bodyPositionY, 'Z', 5); 
}

void Combat::earsePlant(int namePositionX, int namePositionY, int bodyPositionX, int bodyPositionY) {
	//����ֲ����ս������ 
	MyBrush drawPlant;
	
	drawPlant.earse_in_lateral(namePositionX, namePositionY, plant_->name_.length());
	drawPlant.earseTriangle(bodyPositionX, bodyPositionY, 5); 	
}

void Combat::earseZombie(int namePositionX, int namePositionY, int bodyPositionX, int bodyPositionY) {
	//������ʬ��ս������ 
	MyBrush drawZombie;
	
	drawZombie.earse_in_lateral(namePositionX, namePositionY, zombie_->name_.length());
	drawZombie.earseTriangle(bodyPositionX, bodyPositionY, 5); 
}

void Combat::displayCombatAnimation(double FramesGapSenonds) {
	//����ս������, ������ÿһ֡��������� 
	drawPlant(18, 14, 15, 15); drawZombie(47, 14, 45, 15);
	Sleep(FramesGapSenonds * 1000);
	earsePlant(18, 14, 15, 15); earseZombie(47, 14, 45, 15);

	drawPlant(27, 14, 24, 15); drawZombie(37, 14, 35, 15);
	Sleep(FramesGapSenonds * 1000);
	earsePlant(27, 14, 24, 15); earseZombie(37, 14, 35, 15);
	
	drawPlant(18, 14, 15, 15); drawZombie(47, 14, 45, 15);
	Sleep(FramesGapSenonds * 1000);
} 

void Combat::showDead(CombatantMSG nowCharacter) {
	//չʾ����ʱ�Ľ�ɫ�����������������ɫ 
	if (nowCharacter == *plant_) {
		earsePlant(18, 14, 15, 15);
	} else {
		earseZombie(47, 14, 45, 15);
	}
}

void Combat::showTextLog() {
	//�����ǰս����Ϣ 
	if (offensive_._HP <= 0) {
		cout << offensive_._name << " ս���ˡ����� ";
		showDead(offensive_);
	} else if (defender_._HP <= 0) {
		cout << defender_._name << " ս���ˡ����� ";
		showDead(defender_);
	} else {
		cout << offensive_._name << " ������ " << defender_._name << "��" << "����� " << hurt_ << " ���˺�" << endl; 
	};
	Sleep(gapSeconds_ * 1000); 
}

void Combat::displayBoutCombatLog() {
	//����һ���غϵ�ս��
	if (isNoResult() == true) {
		switchSound();
		calculateHP();
		showHP();
		showTextLog();
	} 
	
	flag_++;//�л��غ� 
}

void Combat::displayAllCombatLog() {
	//��������ս��
	MyBrush brush;
	
	system("cls");//������һ������ 
	brush.drawRectangle(0, 0, 74 , 24, '@');//���Ʊ߿�
	brush.setOriginPosition(27, 3);
	cout << '@' << plant_->name_ << " VS "	<< zombie_->name_ << '@';

	brush.draw_in_lateral(30, 10, "ս��������ʼ", 1, 0.3);
	brush.earse_in_lateral(30, 10, 12);
	showHP();
	
	while (isNoResult() == true) {
		displayCombatAnimation(1);
		brush.earse_in_lateral(15, 6, 40);
		brush.setOriginPosition(15, 6);
		displayBoutCombatLog();
	}
}
