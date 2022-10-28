#include <iostream>
#include <string>

using namespace std;

class Plant {
	//ֲ���� (������)
	friend class Combat;
	friend class CombatantMSG;
	friend ostream& operator<< (ostream &output, Plant &needOutput);
	
	public:  
		Plant();
		Plant(const string name);
		Plant(int HP, int attack, int defence);
		Plant(string name, int HP, int attack, int defence);//���캯��
		virtual ~Plant();//����������
		
	public: 
		virtual void display() = 0;//չʾֲ�����ԣ����麯���� 
		virtual string getName() = 0;//���� get 
		virtual int getHP() = 0;
		virtual int getAttack() = 0;
		virtual int getDefence() = 0;
	
	protected:
		string name_; //���� 
		int *pHP_;    //����ֵ 
		int attack_;  //������ 
		int defence_; //������ 
}; 

class Pear:virtual public Plant {
	//������ 
	public:
		Pear();
		Pear(int attackAddition);
		Pear(string name, int HP, int attack, int defence ,int attackBonus);//���캯�� 
		~Pear();
		
	public:
		void setPear(string name, int HP, int attack, int defence ,int attackBonus);
		void display();
		string getName();//���� get 
		int getHP();
		int getAttack();
		int getDefence();
		
	protected:
		int attackBonus_;//�������ӳ� 
};

class Apple:virtual public Plant {
	//ƻ����
	public:
		Apple();
		Apple(int defenceAddition);
		Apple(string name, int HP, int attack, int defence ,int defenceBonus);//���캯�� 
		~Apple();//�������� 
		
	public:
		void setApple(string name, int HP, int attack, int defence ,int defenceBonus);
		void display();
		string getName();//���� get 
		int getHP();
		int getAttack();
		int getDefence();
		
	protected:
		int defenceBonus_;//�������ӳ� 
}; 

class ApplePear:public Apple, public Pear {
	//ƻ������ 
	public:
		ApplePear();
		ApplePear(int attackAddition, int defenceBonus);
		ApplePear(string name, int HP, int attack, int defence, int attackBonus, int defenceBonus);
		~ApplePear();//�������� 
		
	public:
		void setApplePear(string name, int HP, int attack, int defence, int attackBonus, int defenceBonus);//����ƻ��������� 
		void display();
		string getName();//���� get 
		int getHP();
		int getAttack();
		int getDefence();
}; 

void displayPlant(Plant &plant);
