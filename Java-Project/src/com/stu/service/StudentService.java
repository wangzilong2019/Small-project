package com.stu.service;

import com.stu.entity.Student;

import java.util.List;

/**
 *  学生系统的业务逻辑层（服务器层）
 * */

public interface StudentService {
    /**
     * 查询所有学生信息
     * */
    List<Student> selectAll();

    /**
     * 添加学生信息
     *  返回0则代表插入失败，返回1则代表插入成功
     * */
    int  addStudent(Student student);

    /**
     * 删除学生
     *   返回0代表删除学生失败，返回1代表删除成功
     * */
    int delStudent(int sid);

    /**
     *  修改学生信息，通过学号修改
     * */
    int updateStudent(int sid, Student student);

    /**
     *  查找学生信息，通过学号查找
     * */
    Student findStudent(int sid);
}
