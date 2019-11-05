#ifndef     __LIST_H__
#define     __LIST_H__
#include "employee.h"
 
// 结点是链表的元素
// 定义结点类型
typedef struct node {
    employee_t emp;
    struct node* p_next;
} node_t;

// 定义链表类型
// head:指向链表首结点的指针
// count:统计结点数量
typedef struct list {
    node_t* head;
    unsigned count;
} list_t;

// 初始化链表
void init_list(list_t *p_list);
// 插入结点
int insert_node(list_t* p_list, employee_t const* p_emp);
// 遍历链表
void traverse_list(list_t const* p_list);
// 销毁链表
void destroy_list(list_t* p_list);
// 移除结点(按照字段id删除)
int remove_node(list_t* p_list, unsigned id);
// 按照id进行查找
node_t* find_node(list_t* p_list, unsigned id);
#endif      // __LIST_H__
