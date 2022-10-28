#include <iostream>
#include <string>

using namespace std;

class Zombie {
	//��ʬ�� (������)
	friend class Combat; 
	friend class CombatantMSG;
	friend ostream& operator<< (ostream &output, Zombie &needOutput);//������������������ 
	
	public:
		Zombie();
		Zombie(const string name);
		Zombie(int HP, int attack, int defence);
		Zombie(string name, int HP, int attack, int defence);//���캯�� 
		virtual ~Zombie();//���������� 
		
	public:
		virtual void display() = 0;
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

class CommonZombie:public Zombie {
	//��ͨ��ʬ�� 
	public:
		CommonZombie();
		CommonZombie(string name, int HP, int attack, int defence);
		~CommonZombie();//�������� 
		
	public:
		string getName();//���� get 
		int getHP();
		int getAttack();
		int getDefence();
		
	public:
		void setCommonZombie(string name, int HP, int attack, int defence);//������ͨ��ʬ������ 
		void display();
}; 

class FlagZombie:public Zombie {
	//���Ľ�ʬ�� 
	public:
		FlagZombie();
		FlagZombie(int attackBonus);
		FlagZombie(string name, int HP, int attack, int defence ,int attackBonus);//���캯�� 
		~FlagZombie();
		
	public:
		void setFlagZombie(string name, int HP, int attack, int defence ,int attackBonus);
		void display();
		string getName();//���� get 
		int getHP();
		int getAttack();
		int getDefence();
		
	protected:
		int attackBonus_;//�������ӳ� 
};

class GiantZombie:public Zombie {
	//���˽�ʬ��
	public:
		GiantZombie();
		GiantZombie(int defenceBonus);
		GiantZombie(string name, int HP, int attack, int defence ,int defenceBonus);//���캯�� 
		~GiantZombie();//�������� 
		
	public:
		void setGiantZombie(string name, int HP, int attack, int defence ,int defencBonus);
		void display();
		string getName();//���� get 
		int getHP();
		int getAttack();
		int getDefence();
		
	protected:
		int defenceBonus_;//�������ӳ� 
}; 

void displayZombie(Zombie &zombie);
