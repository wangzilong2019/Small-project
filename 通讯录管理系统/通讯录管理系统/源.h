#include<stdio.h>
#include<string.h>
#include<Windows.h>
typedef struct Address_List {/*�ڵ����Ͷ���*/
	char NAME[20];
	char GENDER[20];
	char TEL[20];
	char CITY[20];
	char EIP[20];
	struct Address_List *Next;
}Address_List;/*Address_list*Ϊ�ṹ��ָ������*/
//Address_List* Create();/*������ϵ����Ϣ����*/
void Create();
void input(Address_List *p1);
/*�����ϵ�˺���*/
void Add();
/*������ϵ�˺�����ͨ���������ң�*/
void Find(Address_List *p2);
/*�޸�ͨѶ¼������Ϣ����*/
void Alter(Address_List *p2);
/*ɾ��ͨѶ¼������Ϣ����*/
void Delete();
/*ͨѶ¼��Ϣ��ʾ����*/
//Address_List* List(Address_List *p1);
void List(Address_List *p1);
/*�˵�������ʾ����*/
void Menu();
/*������*/
int main();
