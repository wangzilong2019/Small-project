package com.stu.dao;

import com.stu.entity.Student;

import java.sql.SQLException;
import java.util.List;

/**
 * 访问数据库的接口
 * 对数据库的基本各种操作
 * */

public interface StudentDao {
    /**
     * 根据sql语句查询所有学生的信息
     * */
    List<Student> selectStudent(String sql);

    /**
     * 插入学生信息
     *  插入失败返回0，否则返回插入信息的条数
     * */
    int add(String sql, Student student);

    /**
     * 删除学生信息
     *   删除失败则返回0 ，否则返回1
     * */
    int del(String sql, int sid);

    /**
     *  修改学生信息
     * */
    int update(String sql, int sid, Student student);

    /**
     * 查找学生信息
     * */
    Student find(String sql, int sid);
}
