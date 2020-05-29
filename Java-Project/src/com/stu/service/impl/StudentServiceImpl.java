package com.stu.service.impl;

import com.stu.dao.StudentDao;
import com.stu.dao.impl.StudentDaoImpl;
import com.stu.entity.Student;
import com.stu.service.StudentService;

import java.util.Date;
import java.util.List;

/**
 * 学生约业务逻辑的集体实现类
 * */

public class StudentServiceImpl implements StudentService {
    //通过到层取访问数据库，并得到查询结果
    StudentDao dao = new StudentDaoImpl();

    /**
     * 查询所有的学生信息
     * */
    @Override
    public List<Student> selectAll() {
        String sql = "select * from student2";
        return dao.selectStudent(sql);
    }

    /**
     * 添加学生信息
     * */
    @Override
    public int addStudent(Student student) {
        //获取待添加学生的信息
        String sql = "insert into student2 values(?, ?, ?, ?, ?, ?, ?)";
        return dao.add(sql, student);
    }

    /**
     * 删除学生信息
     * */
    @Override
    public int delStudent(int sid) {
        String sql = "delete from student2 where sid = ?";
        return dao.del(sql, sid);
    }

    /**
     *  修改学生信息
     * */
    @Override
    public int updateStudent(int sid, Student student) {
        String sql = "update student2 set sid = ?, sname = ?, sage = ?, sgender = ?,"
                + " enterdate = ?, cid = ?, score = ? where sid = ?";
        return dao.update(sql, sid, student);
    }

    /**
     *  查找学生信息（按照学号查找）
     * */
    @Override
    public Student findStudent(int sid) {
        String sql = "select * from student2 where sid = ?";
        return dao.find(sql, sid);
    }
}
