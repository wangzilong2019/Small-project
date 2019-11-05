#ifndef     __DB_OPERATION_H__
#define     __DB_OPERATION_H__
#include "list.h"

// �������ݿ�����ṹ��
typedef struct db_operation {
	// ����˵�ѡ����
    unsigned choice;
	char db_file[16];
	// �洢Ա����Ϣ�õ����� 
    list_t db_list;
} db_operation_t;

// ��ʾ�˵�ѡ���� 
void make_choice(db_operation_t*);
// ����ϵͳ 
void start(db_operation_t*);
void do_trans(db_operation_t*);
// ������ݿ��еļ�¼ 
void show_db(db_operation_t const*);
// ��Ӽ�¼
void add_record(db_operation_t*);
// ɾ��ĳ����¼ 
void delete_record(db_operation_t *);
// ͨ��id���ҵ�ĳ����¼�������еĽ�� 
void find_record_by_id(db_operation_t *);

// �޸ļ�¼�е�ĳЩ�� 
void modify_item(db_operation_t*);
// �˳�ϵͳ 
void quit(db_operation_t *);
// �����ݿ��¼�ļ��ж�ȡ��Ϣ�������� 
void read_db(db_operation_t *);
// �������е�����д�뵽���ݿ��ļ� 
void write_db(db_operation_t *);

// ��ʼ�����ݿ���� 
void init_db_operation(db_operation_t*, char const*);

#endif      // __DB_OPERATION_H__
