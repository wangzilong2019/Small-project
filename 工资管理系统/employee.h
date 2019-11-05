#ifndef     __EMPLOYEE_H__
#define     __EMPLOYEE_H__

// ����Ա����Ϣ�ṹ��
typedef struct employee {
    unsigned id;
    char name[16];
    unsigned age;
    char department[16];
	char date[16];
	unsigned bottom_wages;
	unsigned bonus;
	unsigned withholding_wages;
	unsigned actual_wages;
	char bankcard[20];
} employee_t;

void set_id(employee_t* p_emp, unsigned id);
void set_name(employee_t* p_emp, char const* name);
void set_age(employee_t* p_emp, unsigned age);
void set_department(employee_t* p_emp, char const* department);
void set_date(employee_t* p_emp, char const* date);
void set_bottom_wages(employee_t* p_emp, unsigned bottom_wages);
void set_bonus(employee_t* p_emp, unsigned bonus);
void set_withholding_wages(employee_t* p_emp, unsigned withholding_wages);
void set_actual_wages(employee_t* p_emp, unsigned actual_wages);
void set_bankcard(employee_t* p_emp, char const* bankcard);

// �Ӽ��̶�ȡԱ����Ϣ���뵽Ա���ṹ��
void get_info(employee_t* p_emp);
// �����ʾԱ���ṹ��
void show(employee_t const* p_emp);

#endif      // __EMPLOYEE_H__
