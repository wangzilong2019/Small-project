#ifndef     __LIST_H__
#define     __LIST_H__
#include "employee.h"
 
// ����������Ԫ��
// ����������
typedef struct node {
    employee_t emp;
    struct node* p_next;
} node_t;

// ������������
// head:ָ�������׽���ָ��
// count:ͳ�ƽ������
typedef struct list {
    node_t* head;
    unsigned count;
} list_t;

// ��ʼ������
void init_list(list_t *p_list);
// ������
int insert_node(list_t* p_list, employee_t const* p_emp);
// ��������
void traverse_list(list_t const* p_list);
// ��������
void destroy_list(list_t* p_list);
// �Ƴ����(�����ֶ�idɾ��)
int remove_node(list_t* p_list, unsigned id);
// ����id���в���
node_t* find_node(list_t* p_list, unsigned id);
#endif      // __LIST_H__
