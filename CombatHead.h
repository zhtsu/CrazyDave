#include <iostream>
#include <string>

using namespace std;

class CombatantMSG {
	//���ڽ���ս����Ա��������ԣ����㴦��(�����ṹ��ʹ��)
	public:
		string _name;
		int _HP;
		int _attack;
		int _defence;

		//��ֵ����� = ���أ����ڽ� Zombie �� Plant ����ת��Ϊ CombatantMSG ����
		CombatantMSG operator= (Zombie &zombie);
		CombatantMSG operator= (Plant &plant);
		//��ϵ����� == ���أ��ж� CombatantMSG �����ڵ������Ƿ�� Zombie �� Plant ��������� 
		bool operator== (Zombie &zombie);
		bool operator== (Plant &plant);
};

class Combat {
	//��ս�࣬���ڴ����ս��Ϣ
	public:
		Combat();
		Combat(Zombie *zombie, Plant *plant);//���캯��

	public:
		void setCombatant(Zombie *zombie, Plant *plant); //����ս����Ա
		void setDisplayGapSenonds(double gapSeconds);       //���ò�����Ϣ��ʱ��������
		bool isNoResult();           //�ж���Ϸ�Ƿ����
		void switchSound();          //�л��غ�
		void calculateHurt();		 //�����˺� 
		void calculateHP();          //����ʣ��Ѫ��
		void showHP();               //���ʣ��Ѫ��
		void showTextLog();          //���������ǰս����Ϣ 
		void displayBoutCombatLog(); //����һ�غ�ս��
		void displayAllCombatLog();  //��������ս��
		
	private:
		//����ս������ ,������ÿ֮֡��������
		void displayCombatAnimation(double FramesGapSenonds = 0.1); 
		void drawPlant(int namePositionX, int namePositionY, int bodyPositionX, int bodyPositionY);//ָ��λ�û���ֲ�����ɫ
		void drawZombie(int namePositionX, int namePositionY, int bodyPositionX, int bodyPositionY);//ָ��λ�û��ƽ�ʬ���ɫ
		void earsePlant(int namePositionX, int namePositionY, int bodyPositionX, int bodyPositionY);//����ֲ�����ɫ
		void earseZombie(int namePositionX, int namePositionY, int bodyPositionX, int bodyPositionY);//������ʬ���ɫ
		void showDead(CombatantMSG nowCharacter);//չʾ����ʱ�Ľ�ɫ��� 

	private:
		int flag_;              //��ǵ�ǰ�غ�
		double gapSeconds_;     //����ս����Ϣ�������
		Zombie *zombie_;        //��ʬ���ɫ
		Plant *plant_;		    //ֲ�����ɫ
		CombatantMSG offensive_;//���ս���������
		CombatantMSG defender_; //���շ��ط�����
		int hurt_;              //һ�ι������˺�
};
