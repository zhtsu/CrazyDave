#include <iostream>
#include <string>
#include "ZombieHead.h"

using namespace std;

ostream& operator<< (ostream &output, Zombie &needOutput) {
	//�������������أ������ʬ���� 
	output << needOutput.name_;
	
	return output;
} 

Zombie::Zombie() {
	// Zombie �޲ι��� 
	name_ = "��ʬ";
	pHP_ = new int(0);
	attack_ = 0;
	defence_ = 0;
}

Zombie::Zombie(const string name) {
	// Zombie �вι��� 
	name_ = name;
}

Zombie::Zombie(int HP, int attack, int defence) {
	// Zombie �вι��� 
	pHP_ = new int(0);
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
}

Zombie::Zombie(string name, int HP, int attack, int defence) {
	// Zombie �вι��� 
	name_ = name;
	pHP_ = new int(0);
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
}

Zombie::~Zombie() {
	// Zombie �������� 
	delete pHP_;
}

CommonZombie::CommonZombie():Zombie() {
	//CommonZombie �޲ι��� 
}

CommonZombie::CommonZombie(string name, int HP, int attack, int defence):Zombie(name, HP, attack, defence) {
	//CommonZombie �вι��� 
}

CommonZombie::~CommonZombie() {
	//CommonZombie �������� 
	delete pHP_;
}

void CommonZombie::setCommonZombie(string name, int HP, int attack, int defence) {
	//���� CommonZombie ������
	name_ = name;
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
}

void CommonZombie::display() {
	//չʾ CommonZombie ������ 
	cout << "��ʬ����: " << name_ << endl;
	cout << "  ����ֵ: " << *pHP_ << endl;
	cout << "  ������: " << attack_ << endl;
	cout << "  ������: " << defence_ << endl;
}

FlagZombie::FlagZombie():Zombie() {
	// FlagZombie �޲ι��� 
	attackBonus_ = 0; 
}

FlagZombie::FlagZombie(int attackBonus):Zombie() {
	// FlagZombie �вι��� 
	attackBonus_ = attackBonus;
}

FlagZombie::FlagZombie(string name, int HP, int attack, int defence ,int attackBonus):Zombie(name, HP, attack, defence) {
	// FlagZombie �вι��� 
	attackBonus_ = attackBonus;
	
	attack_ = attack_ + attackBonus_;
}

FlagZombie::~FlagZombie() {
	// FlagZombie �������� 
	delete pHP_;
} 

void FlagZombie::setFlagZombie(string name, int HP, int attack, int defence ,int attackBonus) {
	//�������Ľ�ʬ������
	name_ = name;
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
	attackBonus_ = attackBonus;
	
	attack_ = attack_ + attackBonus_; 
}

void FlagZombie::display() {
	//չʾ FlagZombie ������ 
	cout << "��ʬ����: " << name_ << endl;
	cout << "  ����ֵ: " << *pHP_ << endl;
	cout << "  ������: " << attack_ << endl;
	cout << "  ������: " << defence_ << endl;
	cout << "�����ӳ�: " << attackBonus_ << endl;  
}

GiantZombie::GiantZombie():Zombie() {
	// GiantZombie �޲ι��� 
	defenceBonus_ = 0;
}

GiantZombie::GiantZombie(int defenceBonus):Zombie() {
	// GiantZombie �вι��� 
	defenceBonus_ = defenceBonus;
}

GiantZombie::GiantZombie(string name, int HP, int attack, int defence ,int defenceBonus):Zombie(name, HP, attack, defence) {
	// GiantZombie �вι��� 
	defenceBonus_ = defenceBonus;
	
	defence_ = defence_ + defenceBonus_;
}

GiantZombie::~GiantZombie() {
	// GiantZombie �������� 
	delete pHP_;
} 

void GiantZombie::setGiantZombie(string name, int HP, int attack, int defence ,int defenceBonus) {
	//���þ��˽�ʬ������
	name_ = name;
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
	defenceBonus_ = defenceBonus;
	
	defence_ = defence_ + defenceBonus_; 
}

void GiantZombie::display() {
	//չʾ GiantZombie ������ 
	cout << "��ʬ����: " << name_ << endl;
	cout << "  ����ֵ: " << *pHP_ << endl;
	cout << "  ������: " << attack_ << endl;
	cout << "  ������: " << defence_ << endl;
	cout << "�����ӳ�: " << defenceBonus_ << endl;  
}

void displayZombie(Zombie &zombie) {
	//չʾ��ʬ������ 
	zombie.display();
}

string CommonZombie::getName() {
	return name_;
}

int CommonZombie::getHP() {
	return *pHP_;
}

int CommonZombie::getAttack() {
	return attack_;
}

int CommonZombie::getDefence() {
	return  defence_;
}

string FlagZombie::getName() {
	return name_;
}

int FlagZombie::getHP() {
	return *pHP_;
}

int FlagZombie::getAttack() {
	return attack_;
}

int FlagZombie::getDefence() {
	return  defence_;
}

string GiantZombie::getName() {
	return name_;
}

int GiantZombie::getHP() {
	return *pHP_;
}

int GiantZombie::getAttack() {
	return attack_;
}

int GiantZombie::getDefence() {
	return  defence_;
}
