#include<stdio.h>
#include<string.h>
#include<Windows.h>
typedef struct Address_List {/*节点类型定义*/
	char NAME[20];
	char GENDER[20];
	char TEL[20];
	char CITY[20];
	char EIP[20];
	struct Address_List *Next;
}Address_List;/*Address_list*为结构体指针类型*/
//Address_List* Create();/*创建联系人信息函数*/
void Create();
void input(Address_List *p1);
/*添加联系人函数*/
void Add();
/*查找联系人函数（通过姓名查找）*/
void Find(Address_List *p2);
/*修改通讯录个人信息函数*/
void Alter(Address_List *p2);
/*删除通讯录个人信息函数*/
void Delete();
/*通讯录信息显示函数*/
//Address_List* List(Address_List *p1);
void List(Address_List *p1);
/*菜单功能显示函数*/
void Menu();
/*主函数*/
int main();
