#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// ��ʼ���б�ʵ��
void init_list(list_t* p_list) {
	// ͷָ��ָ���
    p_list->head = NULL;
	// ������Ϊ0
    p_list->count = 0;
}
// �������в�����ʵ��
int insert_node(list_t* p_list, employee_t const* p_emp) {
	node_t* p_curr = NULL;	// ��ǰ��� ���������ڷ��ʵĽ��
	node_t* p_prev = NULL; //ǰ���  ��ǰ������һ�����
    
	// ��̬�����㣬�������ĸ�����Ա��ʼ��Ϊ0
    node_t* p_node = (node_t*)calloc(1, sizeof(node_t));
	if(NULL == p_node) {
        return -1;		// �������ڴ�ʧ�ܣ�����-1
    }

    p_node->emp = *p_emp;  //	��p_node��ָ��Ľ�����������и�ֵ 
	// ���Ҫ�����λ���ǵ�1�����λ�ô����˴���������� 
	// 1. p_list->head Ϊ�� 
	// 2. ��Ҫ����Ľ���idС�ڵ���ͷ����id   ������ʱ  idС�ķ���ǰ�� id����ں�

    if((!p_list->head) || (p_node->emp.id <= p_list->head->emp.id)) {
		// ��Ҫ����Ľ���ָ����Ϊlist��head
        p_node->p_next = p_list->head;
		// �²���Ľ���Ϊ�µ�ͷ���
        p_list->head = p_node;
		// ��������1
        ++p_list->count;
        return 0;
    }
	// p_secondΪ��ǰ��㣬p_firstΪǰһ�����
	// ���½����뵽���ڵ�����id�Ľ��֮ǰ
    p_prev = p_list->head;
    p_curr = p_prev->p_next;
	// ѭ������Ҫ�����λ��
	for(; p_curr; p_curr = p_curr->p_next) {
		// ����²���Ľ���idС�ڵ��ڵ�ǰ����id
		// ��Ҫ����Ľ����뵽�����֮ǰ 
        if(p_curr->emp.id >= p_node->emp.id) {
			// �½���ָ����ֵΪ��ǰ����ַ
            p_node->p_next = p_curr;
			// ǰ����ָ����Ϊ�½��
            p_prev->p_next = p_node;
			// �½�����֮����ֹѭ��
            break;
        }
		// ���½��ָ�룬ǰ���ָ��ǰ���
        p_prev = p_curr;
    }
	// ��������еĽ���id��С�ڵ�ǰ���id, ���½����뵽����ĩβ���½���Ϊ�µ�β���
    if(!p_curr) {
        p_prev->p_next = p_node;
    }
	// ������֮���������������1
    ++p_list->count;
    return 0;
}
// ���������������
void traverse_list(list_t const* p_list) {
	node_t const* p_node = NULL;
	// ���p_listָ��Ϊ�գ����������0������������������˳��ú���
    if(!p_list || !p_list->count) {
        return;
    }
	// ������������������������ֵ
    for(p_node = p_list->head; p_node; p_node = p_node->p_next) {
        show(&p_node->emp);
    }
}
// ��������ʵ��
void destroy_list(list_t* p_list) {
	// ���p_listָ��Ϊ�գ����������0������������������˳��ú���
	 if(!p_list || !p_list->count) {
        return;
    }
	 // ɾ�����ʱ��ÿ��ɾ��ͷ����ȷ
    while(p_list->head) {
		// ����p_nodeָ��ͷ���
        node_t* p_node = p_list->head;
		// ͷ������һ������Ϊ�µ�ͷ��� 
        p_list->head = p_list->head->p_next;
		// �ͷ�p_node����¼�Ľ����ڴ�
        free(p_node);
		// �������Լ�1
        --p_list->count;
    }
}
// ���������Ƴ�ָ��id�Ľ��ʵ��
int remove_node(list_t* p_list, unsigned id) {
	node_t* p_curr = NULL;		//��ǰ���ָ��
	node_t* p_prev = NULL;		//��ǰ����ǰ���ָ�� 
    // ���p_listָ��Ϊ�գ����������0���������Ƴ��������˳��ú���
    if(!p_list || !p_list->count) {
        return -1;
    }
	// ǰ���ָ��Ϊͷ���ָ�� 
    p_prev = p_list->head;
	// ��ǰ���Ϊͷ������һ���ڵ� 
    p_curr = p_prev->p_next;
	// ��ͷ�����Ҫɾ���Ľ�� 
    if(p_list->head->emp.id == id) {
		// ͷ������һ������Ϊ�µ�ͷ��� 
        p_list->head = p_list->head->p_next;
		// ǰ���ָ����ָ����ڴ�
        free(p_prev);
		// �������Լ�1
        --p_list->count;
        return 0;
    }
	// ��ͷ��㲻��Ҫɾ���Ľ�㣬���������
    for(; p_curr; p_curr = p_curr->p_next) {
		// �ҵ�Ҫɾ���Ľ��
        if(p_curr->emp.id == id) {
			// ǰ���ָ���ָ�����¼��ǰ������һ������ַ
            p_prev->p_next = p_curr->p_next;
			// �ͷŵ�ǰ���
            free(p_curr);
			// �������Լ�1
            --p_list->count;
            return 0;
        }
		// ����ǰ���ָ�룬ǰ����¼��ǰ���ָ���ֵ
        p_prev = p_curr;
    }
    return -1;
}

// ���ҽ��(��Ա��id)
node_t* find_node(list_t* p_list, unsigned id) {
	// ����ѭ��ָ�����ָ��
	node_t* p_curr = NULL;
	// ���p_listָ��Ϊ�գ����������0������NULL, �˳��ú���
    if(!p_list || !p_list->count) {
        return NULL;
    }
	// p_curr��¼ͷ����ַ
    p_curr = p_list->head;
	// ѭ������ָ��id�Ľ�� 
	while(p_curr) {
		// ���ҵ���㣬���˳�ѭ��
		if(p_curr->emp.id == id) {
			break;
		}
		// ����ѭ������
		p_curr = p_curr->p_next;
	}
	// ���ز��ҵ��Ľ��ָ��  ������һ��Ҳ����Ҫ�ҵ�  �򷵻�null
	return p_curr;
}