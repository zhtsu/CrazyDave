#include <iostream>
#include <string>

using namespace std;

//ȫ�ֺ����������� 

void gameMain();            //��Ϸ���
void startGameOfFile();     //���ļ����� 
void SaveGame(double level);//��Ϸ�浵 
void showNeededLevel(int level); //�����Ӧ�Ĺؿ� 
void showWin();         //�����Ϸʤ������  
void showTwoLevel();    //����ڶ��عؿ���ͼ
void twoLevelMovePlant(Plant *plant);//�ڶ����ƶ�ֲ�� 
void beforeBack(Plant *plant, int level); //������һ����ʾ
void twoLevelBeforeCombat(Plant *plant, int level);//�ڶ��ؿ�ս��ǰ��ʾ 
void OneLevelBeforeCombat(Plant *plant, int level);//�ؿ�ս��ǰ��ʾ 
bool isEnterCombat();                              //�ж�����Ƿ��ͼս�� 
void showGameBackground();                         //�����Ϸ��������
void showTransition();                             //����������� 
void showSelectPlant(Plant *apple, Plant *pear, Plant *applePear);       //��ʾѡ��ֲ�����
int selectPlantMoveCommandr(Plant *apple, Plant *pear, Plant *applePear);//���ݼ��̼���ֵ�л�ֲ�� 
void selectPlantCommand(Plant *apple, Plant *pear, Plant *applePear);    //ѡ��ֲ����������Ӧ 
void showPlant(int originX, int originY, Plant *plant);//���ֲ���ɫ���� 
void showOneLevel();                                   //�����һ�ص�ͼ 
void OneLevelMovePlant(Plant *plant);				   //��һ�ؿ����ƶ�ֲ���ɫ���� 
void showPlantAttribute(Plant *plant);      //չʾֲ���ɫ���� 
void showPlantAttributeInGame(Plant *plant);//����Ϸ����ʾ��ɫ���� 
void showMainMenu();                  //��ʾ���˵�
int mainMenuMoveCommand();            //���ݼ��̼���ֵ�ƶ�ѡ��� 
void mainMenuCommand();               //���˵��������� 
void showSelected(int originX, int originY);                         //��ָ��λ����ʾ����ѡ���ѡ��� 
int moveSelected(int originX, int originY, int finishX, int finishY);//�ƶ�ָ��λ�õ�ѡ���ĩλ�� 
void displayCombat(Zombie *zombie, Plant *plant);                    //���ŵ�һ���ս������ 
COORD upMove(int originX, int originY, Plant *plant);           //�����ƶ�ָ��λ�õ��ַ�
COORD downMove(int originX, int originY, Plant *plant);         //�����ƶ�
COORD leftMove(int originX, int originY, Plant *plant);         //�����ƶ� 
COORD rightMove(int originX, int originY, Plant *plant);        //�����ƶ� 



