#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
#include "db_operation.h"


void make_choice(db_operation_t* p_dbo) {
    //system("clear");
	// 显示菜单选项
    printf("<<<======欢迎使用捷宏工资管理系统======>>>\n");
    printf("*----------------------------------------*\n");
	printf("*----------------------------------------*\n");
	printf("*----------------------------------------*\n");
    printf("*           0 显示所有员工信息           *\n");
    printf("*           1 添加员工信息               *\n");
    printf("*           2 删除员工信息               *\n");
    printf("*           3 查找员工信息               *\n");
    printf("*           4 修改员工信息               *\n");
	printf("*           5 退出系统                   *\n");
    printf("*----------------------------------------*\n");
	printf("*----------------------------------------*\n");
	printf("<<<====================================>>>\n");
    printf("请输入您选择的功能:");
    scanf("%u", &(p_dbo->choice));
    printf("您选择的功能是%u\n", p_dbo->choice);
}

void start(db_operation_t* p_dbo) {
	read_db(p_dbo);
    while(1) {
        make_choice(p_dbo);
        do_trans(p_dbo);
    }
}

// 根据选项选取对应的操作
void do_trans(db_operation_t* p_dbo) {
	employee_t emp = {0};
	switch(p_dbo->choice) {
	case 0: {
		show_db(p_dbo);
		break;
	}
	case 1: {
		add_record(p_dbo);
		break;
	}
	case 2: {
		delete_record(p_dbo);
		break;
	}
	case 3: {
		find_record_by_id(p_dbo);
		break;
	}
	case 4: {
		modify_item(p_dbo);
		break;
	}
	case 5: {
		quit(p_dbo);
		break;
	}
	default:
		printf("没有选择任何操作选项...\n");
	}
}

void quit(db_operation_t* p_dbo) {
	write_db(p_dbo); // 将链表中的数据写入到文件中
	destroy_list(&p_dbo->db_list); // 销毁链表
	exit(0); // 退出程序
}

// 遍历显示链表中的数据
void show_db(struct db_operation const* p_dbo) {
	// 遍历链表
	traverse_list(&p_dbo->db_list);
}

// 初始化数据库操作结构体
void init_db_operation(struct db_operation* p_dbo, char const* file) {
	// 默认初始化为0
	p_dbo->choice = 0;
	// 将数据文件名拷贝到 db_operation的db_file数组中
	strcpy(p_dbo->db_file, file);
	
	// 初始化链表
	init_list(&p_dbo->db_list);

}

// 添加新数据
void add_record(db_operation_t* p_dbo)
{
	// 定义 员工结构体   
	employee_t emp = {0};
	// 从键盘获取输入的员工信息
	get_info(&emp);
	// 把结点插入到链表里
	insert_node(&p_dbo->db_list, &emp);
}

// 输出数据
void delete_record(struct db_operation* p_dbo) {
	unsigned id; // 要删除id

	printf("请输入您想要删除的员工编号:");
	
	scanf("%u", &id);
	// 按照id查找数据并删除 
	remove_node(&p_dbo->db_list ,id);
}

// 通过id查找某条数据
void find_record_by_id(db_operation_t* p_dbo) {
	unsigned id;

	// 循环变量 结点指针
	node_t* p_node = NULL;
	
	printf("请输入您想要查找的员工编号:");
	scanf("%u", &id);
	// 根据id查找到结构体指针
	p_node = find_node(&p_dbo->db_list, id);
	// 找到即展示
	if(p_node) {
		// 展示查找到的员工信息
		show(&p_node->emp);
	}
	else {
		// 提示没有匹配数据
		printf("对不起，查无此人!!!\n");
	}
} 

// 修改员工信息
void modify_item(db_operation_t* p_dbo)
{
	unsigned id;
	unsigned sel_item; // 修改选项 
	node_t* p_node = NULL; //找到对应结点 记录对应结点的地址
	printf("请输入您要修改的员工编号:");
	scanf("%u", &id);
	// 根据id查找 
	p_node = find_node(&p_dbo->db_list, id);
	// 未找到
	if(NULL == p_node) {
		printf("对不起，查无此人!!!\n");
		return ;
	}
	// 找到   输出菜单 选择对应修改项目
	while(1)
	{
		printf("1 修改员工编号\n");
		printf("2 修改员工姓名\n");
		printf("3 修改员工年龄\n");
		printf("4 修改员工部门\n");
		printf("5 修改员工入职时间\n");
		printf("6 修改员工底工资\n");
		printf("7 修改员工奖金\n");
		printf("8 修改员工被扣工资\n");
		printf("9 修改员工实际工资\n");
		printf("10 修改员工银行卡号\n");
		printf("11 OK\n");
		printf("请输入您想要执行的操作:");
		scanf("%u", &sel_item);
		switch(sel_item) {
			case 1: {
				printf("请输入新的员工编号:");
				scanf("%u", &p_node->emp.id);// 通过指针找到对应数据 修改
				show(&p_node->emp); // 展示
				break;
			}
			case 2: {
				printf("请输入新的员工姓名:");
				scanf("%s", p_node->emp.name);
				show(&p_node->emp);
				break;
			}
			case 3: {
				printf("请输入新的员工年龄:");
				scanf("%u", &p_node->emp.age);
				show(&p_node->emp);
				break;
			}
			case 4: {
				printf("请输入新的员工部门:");
				scanf("%s", p_node->emp.department);
				show(&p_node->emp);
				break;
			}
			case 5:{
				printf("请输入新的员工入职时间:");
				scanf("%s", p_node->emp.date);
				show(&p_node->emp);
				break;
		   }
		    case 6:{
			   printf("请输入新的员工底工资:");
			   scanf("%u", &p_node->emp.bottom_wages);
			   show(&p_node->emp);
			   break;
			  }
			case 7:{
				printf("请输入新的员工奖金:");
				scanf("%u", &p_node->emp.bonus);
				show(&p_node->emp);
				break;
				   }
			case 8:{
				printf("请输入新的员工被扣工资:");
				scanf("%u", &p_node->emp.withholding_wages);
				show(&p_node->emp);
				break;
				   }
			case 9:{
				printf("请输入新的员工实际工资:");
				scanf("%u", &p_node->emp.actual_wages);
				show(&p_node->emp);
				break;
				   }

			case 10:{
				printf("请输入新的员工银行卡号:");
				scanf("%s", p_node->emp.bankcard);
				show(&p_node->emp);
				break;
				   }
			case 11: {
				printf("修改完成!!!\n");
				return ;
			}
		}
	}	
}

// 读取数据文件
void read_db(db_operation_t* p_dbo)
{
	employee_t  emp; //  定义员工结构体  为了从文件中读取

	FILE* fp = fopen(p_dbo->db_file, "a+t"); // 打开文件 读取文件内容  a+t 以追加的方式创建或打开文件
	if(NULL == fp) { // 如果文件打开失败
		printf("数据库文件打开失败!!!\n"); 
		return ; // 退出函数
	}
	// 文件打开成功   
	// !feof(fp)  没有读到文件末尾   继续读
	while(!feof(fp)) {
		memset(&emp, 0, sizeof(emp)); // memset 清空结构体

		// fscanf从文件中读取员工信息，存到结构体变量中
		if(fscanf(fp, "%u\t%s\t%u\t%s\t%s\t%u\t%u\t%u\t%u\t%s", &emp.id, emp.name, &emp.age, emp.department, emp.date, &emp.bottom_wages, &emp.bonus, &emp
			.withholding_wages, &emp.actual_wages, emp.bankcard) == 10) 
		{
			insert_node(&p_dbo->db_list, &emp); // 把结构体插入到链表中
		}
	}

	fclose(fp); // 关闭文件
}

// 写文件
void write_db(db_operation_t* p_dbo){
	// 遍历链表用到 结点指针
	node_t* p_node = NULL;
	// 打开文件 读取文件内容  w+t 以写入的方式创建或打开文件  +号代表可以读取
	FILE* fp = fopen(p_dbo->db_file, "w+t");
	if(NULL == fp) { // 如果文件打开失败
		printf("数据库文件打开失败!!!\n");
		return ;// 退出函数
	}
	// 调整文件指针  写文件时从文件的起始位置开始写入
	fseek(fp, 0, SEEK_SET);  //0 代表偏移量 可以是正数也可以是负数    SEEK_SET 把文件指针调整文件的起始位置
	// 获取链表头结点
	p_node = p_dbo->db_list.head; //循环变量 访问各个结点 p_node
	
	// 当结点不为空
	while(p_node) {
		// 将员工信息按照格式写入到文件中去
		fprintf(fp, "%u\t%s\t%u\t%s\t%s\t%u\t%u\t%u\t%u\t%s\n", p_node->emp.id, p_node->emp.name,
			p_node->emp.age, p_node->emp.department, p_node->emp.date, p_node->emp.bottom_wages, p_node->emp.bonus, p_node->emp.withholding_wages, p_node->emp.actual_wages, p_node->emp.bankcard);
		// 更新结点  更新循环变量的值
		p_node = p_node->p_next;
	}
	// 关闭文件
	fclose(fp);
}
