#include"Դ.h"
Address_List *Head;/*����ͷ�ڵ�*/
void Create() {/*β�巨����������*/
//Address_List* Create() {  /*��������ֵ����ΪAddress_list���͵ĺ���*/
	Address_List *s,*r;
	int flag = 1;
	char fname[20];
	s = (Address_List*)malloc(sizeof(Address_List));  /*�����ڵ�*/
	//p2 = (Address_List*)malloc(sizeof(Address_List));
	if (s != NULL) {   /*�ж�����ڵ��Ƿ�ɹ�*/
		Head = s;/*��ͷ�ڵ�ָ��p1,��ʼ������*/
		r = s;/*����βָ�룬ʼ��ָ�����һ���ڵ�*/
		printf("\n\t\t\t����Input Datas����\n");
		printf("------------------------------------------------------------------\n");
		printf("Input 'yes' stand for continuing or 'no' stand for completing: \n");
		while (flag) {/*����yes�������������Ϣ������no����ֹͣ����*/
			printf("Please input 'yes' or 'no'��");
		loop1:	scanf_s("%s",fname,sizeof(fname));/*ʹ��goto����ж����빦���Ƿ�Ϸ�*/
			if (strcmp(fname, "yes") != 0 && strcmp(fname, "no") != 0) {
				printf("Please input the accurate choice:");
				goto loop1;
			}
			if (strcmp(fname, "no") == 0) { /*����no��ֹͣ������Ϣ*/
				printf("\nInput completed!\n");
				printf("========================================================================\n");
				flag = 0;
				r->Next = NULL;/*β�ڵ�ص�ַ�򸳿�ֵ*/
				free(s);/*�ͷ�p1�ڵ�*/
				//s = r;
			}
			else {
				printf("NAME:");
				scanf_s("%s",&s->NAME,sizeof(s->NAME));
				printf("GENDER:");
				scanf_s("%s",&s->GENDER,sizeof(s->GENDER));
				printf("TEL:");
				scanf_s("%s",&s->TEL,sizeof(s->TEL));
				printf("CITY:");
				scanf_s("%s",&s->CITY,sizeof(s->CITY));
				printf("EIP:");
				scanf_s("%s",&s->EIP,sizeof(s->EIP));
				printf("=====================================\n");
				r = s;
				s = (Address_List*)malloc(sizeof(Address_List));/*�����½ڵ����¸���ϵ����Ϣ*/
				if (s != NULL) {
					r->Next = s;/*��������Ľڵ���뵽��ǰ�����β*/
				}
			}

		}
		//return s->Next;
	}

}
void input(Address_List *p1) {/*���������Ϣ*/
	printf("NAME:");
	scanf_s("%s",&p1->NAME,sizeof(p1->NAME));
	printf("GENDER:");
	scanf_s("%s",&p1->GENDER,sizeof(p1->GENDER));
	printf("TEL:");
	scanf_s("%s",&p1->TEL,sizeof(p1->TEL));
	printf("CITY:");
	scanf_s("%s",&p1->CITY,sizeof(p1->CITY));
	printf("EIP:");
	scanf_s("%s",&p1->EIP,sizeof(p1->EIP));
}
void Add() {   /*β�巨�����Ϣ*/
	Address_List *p1, *p3;
	//char name[20];
	p1 = Head;   /*p1ָ��ͷ�ڵ�*/
	p3 = (Address_List*)malloc(sizeof(Address_List));  /*�����ڵ�p3*/
	p3->Next = NULL;  /*�ڵ�ָ���򸳿�ֵ*/
	printf("\n\t\t\t����Add data����\n");
	printf("----------------------------------------------------------------------\n");
	printf("Please input the information of adder:\n");
	input(p3);
	while (p1->Next != NULL) {/*�ҵ�����β�ڵ�*/
			p1 = p1->Next;
		}
	p1->Next = p3;/*ʹβ�ڵ�ָ��ýڵ�*/
	printf("Add completed!\n");
	printf("======================================================================\n");

}
void Find(Address_List *p2) {
	char name[20];
	int flag = 0;
	printf("\n\t\t\t����View Data����\n");
	printf("----------------------------------------------------------------------\n");
	printf("Please input the name of you want to find:");
	scanf_s("%s", name,sizeof(name));
	while (p2 != NULL)/*ѭ����������*/
	{
		if (strcmp(name, p2->NAME) == 0)/*ͨ���������ҵ�����Ϣ*/
		{
			printf("Viewing data of you want to find:\n");/*���������Ϣ*/
			printf("NAME:%s\n", p2->NAME);
			printf("GENDER:%s\t", p2->GENDER);
			printf("TEL:%s\t", p2->TEL);
			printf("CITY:%s\t", p2->CITY);
			printf("EIP:%s\t",p2->EIP);
			printf("======================================================================\n");
			flag = 1;
		}
		p2 = p2->Next;/*��������*/
	}
	if (flag == 0)/*��������û�ҵ��ñ�־��Ϊ0����ѭ��*/
	{
		printf("\nThe person you are finding not exist!\n");
	}
}
void Alter(Address_List *p2) {
	char name[20];
	int flag = 0, i;
	printf("\n\t\t\t����Modify Data����\n");
	printf("----------------------------------------------------------------------\n");
	printf("Please input the name of you want to modify:");
	scanf_s("%s", name,sizeof(name));  /*������Ҫ�޸���Ϣ������*/
	while (p2 != NULL) {/*ѭ����ֹ����*/
		if (strcmp(name, p2->NAME) == 0) {  /*�ж��Ƿ��и���ϵ��*/
			printf("The basic infornamtions of the person\n");/*�������������ϵ�˵Ļ�����Ϣ*/
			printf("NAME:%s\n", p2->NAME);
			printf("GENDER:%s\t", p2->GENDER);
			printf("TEL:%s\t", p2->TEL);
			printf("CITY:%s\t", p2->CITY);
			printf("EIP:%s\t", p2->EIP);
			printf("\nPlease choose the information you want to modify:\n");
			printf("\t1.NAME\t2.GENDER\t3.TEL\t4.CITY\n\t5.EIP\n");
			printf("\nYour choice is(1~5):");
			scanf_s("%d", &i);/*������Ҫ�޸ĵ���Ϣ���*/
			printf("Please input the laterest information:\n");
			switch (i)
			{
			case 1:printf("NAME:");
				scanf_s("%s", &p2->NAME,sizeof(p2->NAME));
				break;
			case 2:printf("GENDER:");
				scanf_s("%s", &p2->GENDER,sizeof(p2->GENDER));
				break;
			case 3:printf("TEL:");
				scanf_s("%s", &p2->TEL,sizeof(p2->TEL));
				break;
			case 4:printf("CITY:");
				scanf_s("%s", &p2->CITY,sizeof(p2->CITY));
				break;
			case 5:printf("EIP:");
				scanf_s("%s", &p2->EIP,sizeof(p2->EIP));
				break;
			}
			printf("\nModified Success!\n");
			printf("=========================================================================\n");
			flag = 1;/*�ҵ�����ϵ���ñ�־��Ϊ1*/
		}
		p2 = p2->Next;/*��������*/
	}
	if (flag == 0)/*û���ҵ�����ϵ���ñ�־��Ϊ�ս���ѭ��*/
	{
		printf("The person you are modify not exist!\n");
	}
}
void Delete()          //ɾ������
{
	Address_List *p1, *p2;
	p2 = (Address_List*)malloc(sizeof(Address_List));/*�����ڵ�*/
	char name[20];  //��Ҫɾ�����˵�����
	printf("\n\t\t\t����ɾ�����ݡ���\n");
	printf("----------------------------------------------------------------------\n");
	printf("Please input the name you want to delete:");
	scanf_s("%s", name,sizeof(name));/*����Ҫɾ����ϵ�˵�����*/
	p1 = Head;/*p1ָ��ͷ�ڵ�*/
	if (Head == NULL)/*ͷ�ڵ�Ϊ���κ���Ϣ*/
	{
		printf("No datas!\n");
		printf("======================================================================\n");
		//return;
	}
	if (strcmp(name, p1->NAME) == 0)/*�ҵ�����ϵ��*/
	{
		Head = p1->Next;/*��ͷ�ڵ�ָ����һ���ڵ㣨�ȼ���ɾ���˽ڵ㣩*/
		printf("Deleted Success!\n");
		printf("======================================================================\n");
		return;
	}
	while (p1 != NULL && (strcmp(name, p1->NAME) != 0))/*ѭ����ֹ�������ҵ�����ϵ�˻��Ǳ���������û���ҵ�*/
	{
		p2 = p1;/*��¼��ǰ�ڵ�*/
		p1 = p1->Next;/*��������*/
	}
	if (p1 == NULL)/*������������޴���*/
	{
		printf("The person you are delete not exist!\n");
		printf("======================================================================\n");
		return;
	}
	if (p1->Next != NULL)/*����Ҫ���ҵĲ������һ���ڵ�*/
	{
		p1 = p1->Next;/*��p1ָ����һ���ڵ�*/
		p2->Next = p1;/*ɾ���ýڵ�*/
		printf("Delete Success!\n");
		printf("======================================================================\n");
		return;
	}
	else
	{
		p2->Next = NULL;/*��Ҫɾ���Ľڵ������һ���ڵ㣬ֱ�Ӹ���ֵ*/
		printf("Delete Success!\n");
		printf("======================================================================\n");
		return;
	}
}
void List(Address_List *p1) {
//Address_List* List(Address_List *p1) {
	printf("\n\t\t\t����View Data����\n");
	printf("----------------------------------------------------------------------\n");
	if (p1 == NULL) {
		printf("No Data!\n");
	}
	while (p1 != NULL) {/*ѭ����ֹ��������������*/
		printf("NAME:%s\n\t", p1->NAME);/*�����Ϣ*/
		printf("GENDER:%s\n\t", p1->GENDER);
		printf("TEL:%s\n\t", p1->TEL);
		printf("CITY:%s\n\t", p1->CITY);
		printf("EIP:%s\t\n", p1->EIP);
		printf("======================================================================\n");
		p1 = p1->Next;/*��������*/
	}
	//return p1;
}
void Menu() {/*�˵�ѡ��*/
	printf("\n\n\n");
	printf("      �������������������������������\n");
	printf("      ***********************************************************\n");
	printf("      \t\t\tAddress book management system\n");
	printf("\n");
	printf("      \t\t1. Input Data");/*������ϵ����Ϣ*/
	printf("\t\t2. Add Data\n");/*�����ϵ����Ϣ*/
	printf("      \t\t3. Find Data");/*������ϵ����Ϣ*/
	printf("\t\t4. Modify Data\n");/*�޸���ϵ����Ϣ*/
	printf("      \t\t5. Delete Data");/*ɾ����ϵ����Ϣ*/
	printf("\t\t6. View Data\n");/*��ʾ������ϵ����Ϣ*/
	printf("\t\t7. Exit System\n");/*�Ƴ�ϵͳ*/
	printf("      ***********************************************************\n");
	printf("      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("      -----------------------------------------------------------\n\n");
}
int main() {
	int i;
	Menu();/*�˵���ʾ*/
	while (1) {
		printf("Please input the number of function:(1-7)");
	loop:scanf_s("%d", &i);/*���빦��ѡ��*/
		if (i < 0 || i>7) {
			printf("Errors! Please input the accurate number of function:");
			goto loop;/*����goto��䣬��ֹ�Ƿ����룻��������������������*/
		}
		switch (i)
		{
		case 1:
			Create();/*������ϵ����Ϣ*/
			break;
		case 2:
			Add();
			break;
		case 3:
			Find(Head);
			break;
		case 4:
			Alter(Head);
			break;
		case 5:
			Delete();
			break;
		case 6:
			List(Head);
			break;
		case 7:
			exit(1);
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}