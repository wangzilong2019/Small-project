#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// 初始化列表实现
void init_list(list_t* p_list) {
	// 头指针指向空
    p_list->head = NULL;
	// 结点个数为0
    p_list->count = 0;
}
// 向链表中插入结点实现
int insert_node(list_t* p_list, employee_t const* p_emp) {
	node_t* p_curr = NULL;	// 当前结点 链表中正在访问的结点
	node_t* p_prev = NULL; //前结点  当前结点的上一个结点
    
	// 动态分配结点，并将结点的各个成员初始化为0
    node_t* p_node = (node_t*)calloc(1, sizeof(node_t));
	if(NULL == p_node) {
        return -1;		// 分配结点内存失败，返回-1
    }

    p_node->emp = *p_emp;  //	将p_node所指向的结点的数据域进行赋值 
	// 如果要插入的位置是第1个结点位置处，此处有两种情况 
	// 1. p_list->head 为空 
	// 2. 将要插入的结点的id小于等于头结点的id   插入结点时  id小的放在前面 id大的在后

    if((!p_list->head) || (p_node->emp.id <= p_list->head->emp.id)) {
		// 将要插入的结点的指针域为list的head
        p_node->p_next = p_list->head;
		// 新插入的结点成为新的头结点
        p_list->head = p_node;
		// 结点个数加1
        ++p_list->count;
        return 0;
    }
	// p_second为当前结点，p_first为前一个结点
	// 将新结点插入到大于等于其id的结点之前
    p_prev = p_list->head;
    p_curr = p_prev->p_next;
	// 循环查找要插入的位置
	for(; p_curr; p_curr = p_curr->p_next) {
		// 如果新插入的结点的id小于等于当前结点的id
		// 则将要插入的结点插入到当结点之前 
        if(p_curr->emp.id >= p_node->emp.id) {
			// 新结点的指针域赋值为当前结点地址
            p_node->p_next = p_curr;
			// 前结点的指针域为新结点
            p_prev->p_next = p_node;
			// 新结点插入之后终止循环
            break;
        }
		// 更新结点指针，前结点指向当前结点
        p_prev = p_curr;
    }
	// 如果链表中的结点的id均小于当前结点id, 则将新结点插入到链表末尾，新结点成为新的尾结点
    if(!p_curr) {
        p_prev->p_next = p_node;
    }
	// 插入结点之后，链表结点个数自增1
    ++p_list->count;
    return 0;
}
// 遍历输出链表各结点
void traverse_list(list_t const* p_list) {
	node_t const* p_node = NULL;
	// 如果p_list指针为空，或结点个数个0，则无需遍历，立即退出该函数
    if(!p_list || !p_list->count) {
        return;
    }
	// 遍历链表输出各结点的数据域的值
    for(p_node = p_list->head; p_node; p_node = p_node->p_next) {
        show(&p_node->emp);
    }
}
// 销毁链表实现
void destroy_list(list_t* p_list) {
	// 如果p_list指针为空，或结点个数个0，则无需遍历，立即退出该函数
	 if(!p_list || !p_list->count) {
        return;
    }
	 // 删除结点时，每次删除头点结点确
    while(p_list->head) {
		// 定义p_node指向头结点
        node_t* p_node = p_list->head;
		// 头结点的下一个结点成为新的头结点 
        p_list->head = p_list->head->p_next;
		// 释放p_node所记录的结点的内存
        free(p_node);
		// 结点个数自减1
        --p_list->count;
    }
}
// 从链表中移除指定id的结点实现
int remove_node(list_t* p_list, unsigned id) {
	node_t* p_curr = NULL;		//当前结点指针
	node_t* p_prev = NULL;		//当前结点的前结点指针 
    // 如果p_list指针为空，或结点个数个0，则无需移除，立即退出该函数
    if(!p_list || !p_list->count) {
        return -1;
    }
	// 前结点指针为头结点指针 
    p_prev = p_list->head;
	// 当前结点为头结点的下一个节点 
    p_curr = p_prev->p_next;
	// 若头结点是要删除的结点 
    if(p_list->head->emp.id == id) {
		// 头结点的下一个结点成为新的头结点 
        p_list->head = p_list->head->p_next;
		// 前结点指针所指向的内存
        free(p_prev);
		// 结点个数自减1
        --p_list->count;
        return 0;
    }
	// 若头结点不是要删除的结点，则遍历查找
    for(; p_curr; p_curr = p_curr->p_next) {
		// 找到要删除的结点
        if(p_curr->emp.id == id) {
			// 前结点指针的指针域记录当前结点的下一个结点地址
            p_prev->p_next = p_curr->p_next;
			// 释放当前结点
            free(p_curr);
			// 结点个数自减1
            --p_list->count;
            return 0;
        }
		// 更新前结点指针，前结点记录当前结点指针的值
        p_prev = p_curr;
    }
    return -1;
}

// 查找结点(按员工id)
node_t* find_node(list_t* p_list, unsigned id) {
	// 定义循环指针变量指针
	node_t* p_curr = NULL;
	// 如果p_list指针为空，或结点个数个0，立即NULL, 退出该函数
    if(!p_list || !p_list->count) {
        return NULL;
    }
	// p_curr记录头结点地址
    p_curr = p_list->head;
	// 循环查找指定id的结点 
	while(p_curr) {
		// 若找到结点，则退出循环
		if(p_curr->emp.id == id) {
			break;
		}
		// 更新循环变量
		p_curr = p_curr->p_next;
	}
	// 返回查找到的结点指针  如果最后一个也不是要找的  则返回null
	return p_curr;
}