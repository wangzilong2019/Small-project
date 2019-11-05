#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
#include "db_operation.h"


void make_choice(db_operation_t* p_dbo) {
    //system("clear");
	// ��ʾ�˵�ѡ��
    printf("<<<======��ӭʹ�ýݺ깤�ʹ���ϵͳ======>>>\n");
    printf("*----------------------------------------*\n");
	printf("*----------------------------------------*\n");
	printf("*----------------------------------------*\n");
    printf("*           0 ��ʾ����Ա����Ϣ           *\n");
    printf("*           1 ���Ա����Ϣ               *\n");
    printf("*           2 ɾ��Ա����Ϣ               *\n");
    printf("*           3 ����Ա����Ϣ               *\n");
    printf("*           4 �޸�Ա����Ϣ               *\n");
	printf("*           5 �˳�ϵͳ                   *\n");
    printf("*----------------------------------------*\n");
	printf("*----------------------------------------*\n");
	printf("<<<====================================>>>\n");
    printf("��������ѡ��Ĺ���:");
    scanf("%u", &(p_dbo->choice));
    printf("��ѡ��Ĺ�����%u\n", p_dbo->choice);
}

void start(db_operation_t* p_dbo) {
	read_db(p_dbo);
    while(1) {
        make_choice(p_dbo);
        do_trans(p_dbo);
    }
}

// ����ѡ��ѡȡ��Ӧ�Ĳ���
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
		printf("û��ѡ���κβ���ѡ��...\n");
	}
}

void quit(db_operation_t* p_dbo) {
	write_db(p_dbo); // �������е�����д�뵽�ļ���
	destroy_list(&p_dbo->db_list); // ��������
	exit(0); // �˳�����
}

// ������ʾ�����е�����
void show_db(struct db_operation const* p_dbo) {
	// ��������
	traverse_list(&p_dbo->db_list);
}

// ��ʼ�����ݿ�����ṹ��
void init_db_operation(struct db_operation* p_dbo, char const* file) {
	// Ĭ�ϳ�ʼ��Ϊ0
	p_dbo->choice = 0;
	// �������ļ��������� db_operation��db_file������
	strcpy(p_dbo->db_file, file);
	
	// ��ʼ������
	init_list(&p_dbo->db_list);

}

// ���������
void add_record(db_operation_t* p_dbo)
{
	// ���� Ա���ṹ��   
	employee_t emp = {0};
	// �Ӽ��̻�ȡ�����Ա����Ϣ
	get_info(&emp);
	// �ѽ����뵽������
	insert_node(&p_dbo->db_list, &emp);
}

// �������
void delete_record(struct db_operation* p_dbo) {
	unsigned id; // Ҫɾ��id

	printf("����������Ҫɾ����Ա�����:");
	
	scanf("%u", &id);
	// ����id�������ݲ�ɾ�� 
	remove_node(&p_dbo->db_list ,id);
}

// ͨ��id����ĳ������
void find_record_by_id(db_operation_t* p_dbo) {
	unsigned id;

	// ѭ������ ���ָ��
	node_t* p_node = NULL;
	
	printf("����������Ҫ���ҵ�Ա�����:");
	scanf("%u", &id);
	// ����id���ҵ��ṹ��ָ��
	p_node = find_node(&p_dbo->db_list, id);
	// �ҵ���չʾ
	if(p_node) {
		// չʾ���ҵ���Ա����Ϣ
		show(&p_node->emp);
	}
	else {
		// ��ʾû��ƥ������
		printf("�Բ��𣬲��޴���!!!\n");
	}
} 

// �޸�Ա����Ϣ
void modify_item(db_operation_t* p_dbo)
{
	unsigned id;
	unsigned sel_item; // �޸�ѡ�� 
	node_t* p_node = NULL; //�ҵ���Ӧ��� ��¼��Ӧ���ĵ�ַ
	printf("��������Ҫ�޸ĵ�Ա�����:");
	scanf("%u", &id);
	// ����id���� 
	p_node = find_node(&p_dbo->db_list, id);
	// δ�ҵ�
	if(NULL == p_node) {
		printf("�Բ��𣬲��޴���!!!\n");
		return ;
	}
	// �ҵ�   ����˵� ѡ���Ӧ�޸���Ŀ
	while(1)
	{
		printf("1 �޸�Ա�����\n");
		printf("2 �޸�Ա������\n");
		printf("3 �޸�Ա������\n");
		printf("4 �޸�Ա������\n");
		printf("5 �޸�Ա����ְʱ��\n");
		printf("6 �޸�Ա���׹���\n");
		printf("7 �޸�Ա������\n");
		printf("8 �޸�Ա�����۹���\n");
		printf("9 �޸�Ա��ʵ�ʹ���\n");
		printf("10 �޸�Ա�����п���\n");
		printf("11 OK\n");
		printf("����������Ҫִ�еĲ���:");
		scanf("%u", &sel_item);
		switch(sel_item) {
			case 1: {
				printf("�������µ�Ա�����:");
				scanf("%u", &p_node->emp.id);// ͨ��ָ���ҵ���Ӧ���� �޸�
				show(&p_node->emp); // չʾ
				break;
			}
			case 2: {
				printf("�������µ�Ա������:");
				scanf("%s", p_node->emp.name);
				show(&p_node->emp);
				break;
			}
			case 3: {
				printf("�������µ�Ա������:");
				scanf("%u", &p_node->emp.age);
				show(&p_node->emp);
				break;
			}
			case 4: {
				printf("�������µ�Ա������:");
				scanf("%s", p_node->emp.department);
				show(&p_node->emp);
				break;
			}
			case 5:{
				printf("�������µ�Ա����ְʱ��:");
				scanf("%s", p_node->emp.date);
				show(&p_node->emp);
				break;
		   }
		    case 6:{
			   printf("�������µ�Ա���׹���:");
			   scanf("%u", &p_node->emp.bottom_wages);
			   show(&p_node->emp);
			   break;
			  }
			case 7:{
				printf("�������µ�Ա������:");
				scanf("%u", &p_node->emp.bonus);
				show(&p_node->emp);
				break;
				   }
			case 8:{
				printf("�������µ�Ա�����۹���:");
				scanf("%u", &p_node->emp.withholding_wages);
				show(&p_node->emp);
				break;
				   }
			case 9:{
				printf("�������µ�Ա��ʵ�ʹ���:");
				scanf("%u", &p_node->emp.actual_wages);
				show(&p_node->emp);
				break;
				   }

			case 10:{
				printf("�������µ�Ա�����п���:");
				scanf("%s", p_node->emp.bankcard);
				show(&p_node->emp);
				break;
				   }
			case 11: {
				printf("�޸����!!!\n");
				return ;
			}
		}
	}	
}

// ��ȡ�����ļ�
void read_db(db_operation_t* p_dbo)
{
	employee_t  emp; //  ����Ա���ṹ��  Ϊ�˴��ļ��ж�ȡ

	FILE* fp = fopen(p_dbo->db_file, "a+t"); // ���ļ� ��ȡ�ļ�����  a+t ��׷�ӵķ�ʽ��������ļ�
	if(NULL == fp) { // ����ļ���ʧ��
		printf("���ݿ��ļ���ʧ��!!!\n"); 
		return ; // �˳�����
	}
	// �ļ��򿪳ɹ�   
	// !feof(fp)  û�ж����ļ�ĩβ   ������
	while(!feof(fp)) {
		memset(&emp, 0, sizeof(emp)); // memset ��սṹ��

		// fscanf���ļ��ж�ȡԱ����Ϣ���浽�ṹ�������
		if(fscanf(fp, "%u\t%s\t%u\t%s\t%s\t%u\t%u\t%u\t%u\t%s", &emp.id, emp.name, &emp.age, emp.department, emp.date, &emp.bottom_wages, &emp.bonus, &emp
			.withholding_wages, &emp.actual_wages, emp.bankcard) == 10) 
		{
			insert_node(&p_dbo->db_list, &emp); // �ѽṹ����뵽������
		}
	}

	fclose(fp); // �ر��ļ�
}

// д�ļ�
void write_db(db_operation_t* p_dbo){
	// ���������õ� ���ָ��
	node_t* p_node = NULL;
	// ���ļ� ��ȡ�ļ�����  w+t ��д��ķ�ʽ��������ļ�  +�Ŵ�����Զ�ȡ
	FILE* fp = fopen(p_dbo->db_file, "w+t");
	if(NULL == fp) { // ����ļ���ʧ��
		printf("���ݿ��ļ���ʧ��!!!\n");
		return ;// �˳�����
	}
	// �����ļ�ָ��  д�ļ�ʱ���ļ�����ʼλ�ÿ�ʼд��
	fseek(fp, 0, SEEK_SET);  //0 ����ƫ���� ����������Ҳ�����Ǹ���    SEEK_SET ���ļ�ָ������ļ�����ʼλ��
	// ��ȡ����ͷ���
	p_node = p_dbo->db_list.head; //ѭ������ ���ʸ������ p_node
	
	// ����㲻Ϊ��
	while(p_node) {
		// ��Ա����Ϣ���ո�ʽд�뵽�ļ���ȥ
		fprintf(fp, "%u\t%s\t%u\t%s\t%s\t%u\t%u\t%u\t%u\t%s\n", p_node->emp.id, p_node->emp.name,
			p_node->emp.age, p_node->emp.department, p_node->emp.date, p_node->emp.bottom_wages, p_node->emp.bonus, p_node->emp.withholding_wages, p_node->emp.actual_wages, p_node->emp.bankcard);
		// ���½��  ����ѭ��������ֵ
		p_node = p_node->p_next;
	}
	// �ر��ļ�
	fclose(fp);
}
