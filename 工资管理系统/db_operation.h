#ifndef     __DB_OPERATION_H__
#define     __DB_OPERATION_H__
#include "list.h"

// 定义数据库操作结构体
typedef struct db_operation {
	// 保存菜单选项编号
    unsigned choice;
	char db_file[16];
	// 存储员工信息用的链表 
    list_t db_list;
} db_operation_t;

// 显示菜单选择项 
void make_choice(db_operation_t*);
// 启动系统 
void start(db_operation_t*);
void do_trans(db_operation_t*);
// 输出数据库中的记录 
void show_db(db_operation_t const*);
// 添加记录
void add_record(db_operation_t*);
// 删除某条记录 
void delete_record(db_operation_t *);
// 通过id查找到某条记录在链表中的结点 
void find_record_by_id(db_operation_t *);

// 修改记录中的某些项 
void modify_item(db_operation_t*);
// 退出系统 
void quit(db_operation_t *);
// 从数据库记录文件中读取信息到链表中 
void read_db(db_operation_t *);
// 将链表中的数据写入到数据库文件 
void write_db(db_operation_t *);

// 初始化数据库操作 
void init_db_operation(db_operation_t*, char const*);

#endif      // __DB_OPERATION_H__
