#include <iostream>
#include <string>
#include "PlantHead.h"

using namespace std;

ostream& operator<< (ostream &output, Plant &needOutput) {
	//�������������أ����ֲ������ 
	output << needOutput.name_;
	
	return output;
} 

Plant::Plant() {
	// Plant �޲ι��� 
	name_ = "ֲ��";
	pHP_ = new int(0);
	attack_ = 0;
	defence_ = 0;
}

Plant::Plant(const string name) {
	// Plant �вι��� 
	name_ = name;
}

Plant::Plant(int HP, int attack, int defence) {
	// Plant �вι��� 
	pHP_ = new int(0);
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
}

Plant::Plant(string name, int HP, int attack, int defence) {
	// Plant �вι��� 
	name_ = name;
	pHP_ = new int(0);
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
}

Plant::~Plant() {
	// Plant �������� 
	delete pHP_;
}

Pear::Pear():Plant() {
	// Pear �޲ι��� 
	attackBonus_ = 0;
}

Pear::Pear(int attackBonus) {
	// Pear �вι���
	attackBonus_ = attackBonus;
} 

Pear::Pear(string name, int HP, int attack, int defence ,int attackBonus):Plant(name, HP, attack, defence) {
	// Pear �вι��� 
	attackBonus_ = attackBonus;
	//��ǰ������Ϊ��ʼ���������Ϲ������ӳ� 
	attack_ = attack_ + attackBonus_; 
}

Pear::~Pear() {
	// Pear �������� 
	delete pHP_;
}

void Pear::setPear(string name, int HP, int attack, int defence ,int attackBonus) {
	//���� Pear ������ 
	name_ = name;
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
	attackBonus_ = attackBonus;
	
	attack_ = attack_ + attackBonus_;
} 

void Pear::display() {
	//չʾ Pear ������ 
	cout << "ֲ������: " << name_ << endl;
	cout << "  ����ֵ: " << *pHP_ << endl;
	cout << "  ������: " << attack_ << endl;
	cout << "  ������: " << defence_ << endl;
	cout << "�����ӳ�: " << attackBonus_ << endl << endl; 
}

Apple::Apple():Plant() {
	// Apple �޲ι��� 
	defenceBonus_ = 0;
}

Apple::Apple(int defenceBonus) {
	// Apple �вι��� 
	defenceBonus_ = defenceBonus;
}

Apple::Apple(string name, int HP, int attack, int defence ,int defenceBonus):Plant(name, HP, attack, defence) {
	// Apple �вι���
	defenceBonus_ = defenceBonus;
	
	defence_ = defence_ + defenceBonus_; 
}

Apple::~Apple() {
	// Apple ��������
	delete pHP_; 
}

void Apple::setApple(string name, int HP, int attack, int defence, int defenceBonus) {
	//���� Apple ������ 
	name_ = name;
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
	defenceBonus_ = defenceBonus;
	
	defence_ = defence_ + defenceBonus_;
}

void Apple::display() {
	//չʾ Apple ������ 
	cout << "ֲ������: " << name_ << endl;
	cout << "  ����ֵ: " << *pHP_ << endl;
	cout << "  ������: " << attack_ << endl;
	cout << "  ������: " << defence_ << endl;
	cout << "�����ӳ�: " << defenceBonus_ << endl << endl;	
} 

ApplePear::ApplePear():Plant(), Apple(), Pear() {
	// ApplePear �޲ι��� 
} 

ApplePear::ApplePear(int attackBonus, int defenceBonus):Plant(), Pear(attackBonus), Apple(defenceBonus) {
	// ApplePear �вι��� 
}

ApplePear::ApplePear(string name, int HP, int attack, int defence, int attackBonus, int defenceBonus)
		  			:Plant(name, HP, attack, defence), Pear(attackBonus), Apple(defenceBonus) {
	// ApplePear �вι��� 
	attack_ = attack_ + attackBonus_;
	defence_ = defence_ + defenceBonus_;
}

ApplePear::~ApplePear() {
	// ApplePear �������� 
	delete pHP_;
}

void ApplePear::setApplePear(string name, int HP, int attack, int defence, int attackBonus, int defenceBonus) {
	//���� ApplePear ������ 
	name_ = name;
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
	attackBonus_ = attackBonus; 
	defenceBonus_ = defenceBonus;
	
	attack_ = attack_ + attackBonus_;
	defence_ = defence_ + defenceBonus_;
}

void ApplePear::display() {
	//չʾ ApplePear ������ 
	cout << "ֲ������: " << name_ << endl;
	cout << "  ����ֵ: " << *pHP_ << endl;
	cout << "  ������: " << attack_ << endl;
	cout << "  ������: " << defence_ << endl;
	cout << "�����ӳ�: " << attackBonus_ << endl; 
	cout << "�����ӳ�: " << defenceBonus_ << endl << endl;
}

void displayPlant(Plant &plant) {
	//չʾֲ������� 
	plant.display();
} 

string Pear::getName() {
	return name_;
}

int Pear::getHP() {
	return *pHP_;
}

int Pear::getAttack() {
	return attack_;
}

int Pear::getDefence() {
	return  defence_;
}

string Apple::getName() {
	return name_;
}

int Apple::getHP() {
	return *pHP_;
}

int Apple::getAttack() {
	return attack_;
}

int Apple::getDefence() {
	return  defence_;
}

string ApplePear::getName() {
	return name_;
}

int ApplePear::getHP() {
	return *pHP_;
}

int ApplePear::getAttack() {
	return attack_;
}

int ApplePear::getDefence() {
	return  defence_;
}
