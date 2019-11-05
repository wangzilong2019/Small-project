#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

void set_id(employee_t* p_emp, unsigned id) {
    p_emp->id = id;
}
void set_name(employee_t* p_emp, char const* name) {
    strcpy(p_emp->name, name);
}
void set_age(employee_t* p_emp, unsigned age) {
    p_emp->age = age;
}
void set_department(employee_t* p_emp, char const* department) {
    strcpy(p_emp->department, department);
}
void set_date(employee_t* p_emp, char const* date) {
	strcpy(p_emp->date, date);
}
void set_bottom_wages(employee_t* p_emp, unsigned bottom_wages){
	p_emp->bottom_wages = bottom_wages;
}
void set_bonus(employee_t* p_emp, unsigned bonus){
	p_emp->bonus = bonus;
}
void set_withholding_wages(employee_t* p_emp, unsigned withholding_wages){
	p_emp->withholding_wages = withholding_wages;
}
void set_actual_wages(employee_t* p_emp, unsigned actual_wages){
	p_emp->actual_wages = actual_wages;
}
void set_bankcard(employee_t* p_emp, char const* bankcard){
	strcpy(p_emp->bankcard, bankcard);
}
void get_info(employee_t* p_emp) {
    printf("请输入员工信息：(id,name,age,department,date,bottom_wages,bonus,withholding_wages,actual_wages,bankcard):");
    scanf("%u %s %u %s %s %u %u %u %u %s", &p_emp->id, p_emp->name, &p_emp->age, p_emp->department, p_emp->date, &p_emp->bottom_wages, &p_emp->bonus, &p_emp->withholding_wages, &p_emp->actual_wages, p_emp->bankcard);
}

void show(employee_t const* p_emp) {
    printf("%u\t%s\t%u\t%s\t%s\t%u\t%u\t%u\t%u\t%s\n", p_emp->id, p_emp->name,
        p_emp->age, p_emp->department, p_emp->date, p_emp->bottom_wages, p_emp->bonus, p_emp->withholding_wages, p_emp->actual_wages, p_emp->bankcard);
}
