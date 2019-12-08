#include"源.h"
Address_List *Head;/*建立头节点*/
void Create() {/*尾插法建立单链表*/
//Address_List* Create() {  /*创建返回值类型为Address_list类型的函数*/
	Address_List *s,*r;
	int flag = 1;
	char fname[20];
	s = (Address_List*)malloc(sizeof(Address_List));  /*建立节点*/
	//p2 = (Address_List*)malloc(sizeof(Address_List));
	if (s != NULL) {   /*判断申请节点是否成功*/
		Head = s;/*将头节点指向p1,初始化链表*/
		r = s;/*创建尾指针，始终指向最后一个节点*/
		printf("\n\t\t\t☆☆☆Input Datas☆☆☆\n");
		printf("------------------------------------------------------------------\n");
		printf("Input 'yes' stand for continuing or 'no' stand for completing: \n");
		while (flag) {/*输入yes代表继续插入信息；输入no代表停止插入*/
			printf("Please input 'yes' or 'no'：");
		loop1:	scanf_s("%s",fname,sizeof(fname));/*使用goto语句判断输入功能是否合法*/
			if (strcmp(fname, "yes") != 0 && strcmp(fname, "no") != 0) {
				printf("Please input the accurate choice:");
				goto loop1;
			}
			if (strcmp(fname, "no") == 0) { /*输入no则停止创建信息*/
				printf("\nInput completed!\n");
				printf("========================================================================\n");
				flag = 0;
				r->Next = NULL;/*尾节点地地址域赋空值*/
				free(s);/*释放p1节点*/
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
				s = (Address_List*)malloc(sizeof(Address_List));/*申请新节点存放下个联系人信息*/
				if (s != NULL) {
					r->Next = s;/*将新申请的节点插入到当前链表的尾*/
				}
			}

		}
		//return s->Next;
	}

}
void input(Address_List *p1) {/*输入添加信息*/
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
void Add() {   /*尾插法添加信息*/
	Address_List *p1, *p3;
	//char name[20];
	p1 = Head;   /*p1指向头节点*/
	p3 = (Address_List*)malloc(sizeof(Address_List));  /*创建节点p3*/
	p3->Next = NULL;  /*节点指针域赋空值*/
	printf("\n\t\t\t☆☆☆Add data☆☆☆\n");
	printf("----------------------------------------------------------------------\n");
	printf("Please input the information of adder:\n");
	input(p3);
	while (p1->Next != NULL) {/*找到链表尾节点*/
			p1 = p1->Next;
		}
	p1->Next = p3;/*使尾节点指向该节点*/
	printf("Add completed!\n");
	printf("======================================================================\n");

}
void Find(Address_List *p2) {
	char name[20];
	int flag = 0;
	printf("\n\t\t\t☆☆☆View Data☆☆☆\n");
	printf("----------------------------------------------------------------------\n");
	printf("Please input the name of you want to find:");
	scanf_s("%s", name,sizeof(name));
	while (p2 != NULL)/*循环截至条件*/
	{
		if (strcmp(name, p2->NAME) == 0)/*通过姓名查找到该信息*/
		{
			printf("Viewing data of you want to find:\n");/*输出个人信息*/
			printf("NAME:%s\n", p2->NAME);
			printf("GENDER:%s\t", p2->GENDER);
			printf("TEL:%s\t", p2->TEL);
			printf("CITY:%s\t", p2->CITY);
			printf("EIP:%s\t",p2->EIP);
			printf("======================================================================\n");
			flag = 1;
		}
		p2 = p2->Next;/*遍历链表*/
	}
	if (flag == 0)/*遍历链表没找到置标志域为0结束循环*/
	{
		printf("\nThe person you are finding not exist!\n");
	}
}
void Alter(Address_List *p2) {
	char name[20];
	int flag = 0, i;
	printf("\n\t\t\t☆☆☆Modify Data☆☆☆\n");
	printf("----------------------------------------------------------------------\n");
	printf("Please input the name of you want to modify:");
	scanf_s("%s", name,sizeof(name));  /*输入想要修改信息的姓名*/
	while (p2 != NULL) {/*循环终止条件*/
		if (strcmp(name, p2->NAME) == 0) {  /*判断是否有该联系人*/
			printf("The basic infornamtions of the person\n");/*若有则输出该联系人的基本信息*/
			printf("NAME:%s\n", p2->NAME);
			printf("GENDER:%s\t", p2->GENDER);
			printf("TEL:%s\t", p2->TEL);
			printf("CITY:%s\t", p2->CITY);
			printf("EIP:%s\t", p2->EIP);
			printf("\nPlease choose the information you want to modify:\n");
			printf("\t1.NAME\t2.GENDER\t3.TEL\t4.CITY\n\t5.EIP\n");
			printf("\nYour choice is(1~5):");
			scanf_s("%d", &i);/*输入想要修改的信息编号*/
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
			flag = 1;/*找到该联系人置标志域为1*/
		}
		p2 = p2->Next;/*遍历链表*/
	}
	if (flag == 0)/*没有找到该联系人置标志域为空结束循环*/
	{
		printf("The person you are modify not exist!\n");
	}
}
void Delete()          //删除数据
{
	Address_List *p1, *p2;
	p2 = (Address_List*)malloc(sizeof(Address_List));/*建立节点*/
	char name[20];  //想要删除的人的姓名
	printf("\n\t\t\t☆☆☆删除数据☆☆☆\n");
	printf("----------------------------------------------------------------------\n");
	printf("Please input the name you want to delete:");
	scanf_s("%s", name,sizeof(name));/*输入要删除联系人的姓名*/
	p1 = Head;/*p1指向头节点*/
	if (Head == NULL)/*头节点为空任何信息*/
	{
		printf("No datas!\n");
		printf("======================================================================\n");
		//return;
	}
	if (strcmp(name, p1->NAME) == 0)/*找到该联系人*/
	{
		Head = p1->Next;/*将头节点指向下一个节点（等价于删除此节点）*/
		printf("Deleted Success!\n");
		printf("======================================================================\n");
		return;
	}
	while (p1 != NULL && (strcmp(name, p1->NAME) != 0))/*循环终止条件；找到该联系人或是遍历完链表没有找到*/
	{
		p2 = p1;/*记录当前节点*/
		p1 = p1->Next;/*遍历链表*/
	}
	if (p1 == NULL)/*遍历完链表查无此人*/
	{
		printf("The person you are delete not exist!\n");
		printf("======================================================================\n");
		return;
	}
	if (p1->Next != NULL)/*即所要查找的不是最后一个节点*/
	{
		p1 = p1->Next;/*将p1指向下一个节点*/
		p2->Next = p1;/*删除该节点*/
		printf("Delete Success!\n");
		printf("======================================================================\n");
		return;
	}
	else
	{
		p2->Next = NULL;/*所要删除的节点是最后一个节点，直接赋空值*/
		printf("Delete Success!\n");
		printf("======================================================================\n");
		return;
	}
}
void List(Address_List *p1) {
//Address_List* List(Address_List *p1) {
	printf("\n\t\t\t☆☆☆View Data☆☆☆\n");
	printf("----------------------------------------------------------------------\n");
	if (p1 == NULL) {
		printf("No Data!\n");
	}
	while (p1 != NULL) {/*循环终止条件遍历完链表*/
		printf("NAME:%s\n\t", p1->NAME);/*输出信息*/
		printf("GENDER:%s\n\t", p1->GENDER);
		printf("TEL:%s\n\t", p1->TEL);
		printf("CITY:%s\n\t", p1->CITY);
		printf("EIP:%s\t\n", p1->EIP);
		printf("======================================================================\n");
		p1 = p1->Next;/*遍历链表*/
	}
	//return p1;
}
void Menu() {/*菜单选项*/
	printf("\n\n\n");
	printf("      ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("      ***********************************************************\n");
	printf("      \t\t\tAddress book management system\n");
	printf("\n");
	printf("      \t\t1. Input Data");/*创建联系人信息*/
	printf("\t\t2. Add Data\n");/*添加联系人信息*/
	printf("      \t\t3. Find Data");/*查找联系人信息*/
	printf("\t\t4. Modify Data\n");/*修改联系人信息*/
	printf("      \t\t5. Delete Data");/*删除联系人信息*/
	printf("\t\t6. View Data\n");/*显示所有联系人信息*/
	printf("\t\t7. Exit System\n");/*推出系统*/
	printf("      ***********************************************************\n");
	printf("      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("      -----------------------------------------------------------\n\n");
}
int main() {
	int i;
	Menu();/*菜单显示*/
	while (1) {
		printf("Please input the number of function:(1-7)");
	loop:scanf_s("%d", &i);/*输入功能选择*/
		if (i < 0 || i>7) {
			printf("Errors! Please input the accurate number of function:");
			goto loop;/*定义goto语句，防止非法输入；若输出功能无则继续输入*/
		}
		switch (i)
		{
		case 1:
			Create();/*创建联系人信息*/
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