package com.stu.view;

import com.stu.entity.Student;
import com.stu.service.StudentService;
import com.stu.service.impl.StudentServiceImpl;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

/**
 *  视图层
 *  控制台内容的显示、以及学生各种操作和控制层的交流
 * */

public class StudentSystem {
    //用于从键盘获取信息
    private Scanner input = new Scanner(System.in);

    /**
     * 控制层对象
     * */
    private StudentService service = new StudentServiceImpl();

    /**
     * 启动系统，显示欢迎界面、提示信息、显示菜单
     * */
    public void start() {
        System.out.println("------欢迎启动系统------");
    }

    /**
     * 退出系统
     * */
    public void exit() {
        System.out.println("------退出系统------");
        System.exit(0);
    }

    /**
     *  显示菜单
     *    1、查看所有
     *    2、修改所有
     *    3、添加学生
     *    4、删除学生
     *    5、查找学生
     *    6、退出系统
     *
     * */
    public void menu() {
        System.out.println("--------------------");
        System.out.println("----1、查看学生-----");
        System.out.println("----2、添加学生-----");
        System.out.println("----3、删除学生-----");
        System.out.println("----4、修改学生-----");
        System.out.println("----5、查找学生-----");
        System.out.println("----6、退出系统-----");
        System.out.println("--------------------");
    }

    /**选择菜单*/
    public int selectMenu() {
        System.out.println("请输入所要选择的功能");
        return input.nextInt();
    }

    /**
     * 查询所有学生信息
     * */
    public void selectAll() {
        List<Student> stus = service.selectAll();
        //需要在视图层展示

        System.out.println("-------返回所有的学生信息-------");
        if (stus == null || stus.size() == 0) {
            System.out.println("没有学生信息");
        } else {
            for (Student stu : stus) {
                System.out.println(stu);
            }
        }
        System.out.println("---------------------------------");
    }

    /**
     *  创建学生对象
     * */
    public Student createStudent() throws Exception{
        System.out.println("请输入学生学号：");
        int sid = input.nextInt();
        System.out.println("请输入学生姓名：");
        String sname = input.next();
        System.out.println("请输入学生年龄：");
        int sage = input.nextInt();
        System.out.println("请输入学生性别（男、女）：");
        String sgender = input.next();
        System.out.println("请输入学生入学日期yyyy-mm-dd：");
        String date = input.next();
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-mm-dd");
        Date enterdate = sdf.parse(date);
        System.out.println("请输入学生班级编号：");
        int cid = input.nextInt();
        System.out.println("请输入学生分数：");
        double score = input.nextDouble();

        //生成一个student对象交给控制层处理
        return new Student(sid, sname, sage, sgender, enterdate, cid, score);
    }

    /**
     *  添加学生信息
     **/
    public void addStudent() {
        try {

            //生成一个student对象交给控制层处理
            Student student = createStudent();
            int count = service.addStudent(student);
            System.out.println("-----" + (count > 0 ?"添加成功" : "添加失败") + "-----");
        } catch (Exception e) {
            System.out.println("-----添加学生信息失败-----");
            e.printStackTrace();
        }
    }

    /**
     *  删除学生信息
     * */
    public void delStudent() {
        System.out.println("请输入要删除学生的学号：");
        int sid = input.nextInt();
        int count = service.delStudent(sid);
        System.out.println("-----" + (count > 0 ?"删除成功" : "删除失败") + "-----");
    }

    /**
     * 修改学生信息
     * */

    public void updateStudent() {
        System.out.println("请输入要修改学生的学号：");
        int sid = input.nextInt();
        System.out.println("下面开始修改之后的内容：");
        try {
            Student student = createStudent();
            int count = service.updateStudent(sid, student);
            System.out.println("-----" + (count > 0 ?"修改成功" : "修改失败") + "-----");
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    /**
     *  查找学生信息（按学号查找）
     * */
    public void findStudent() {
        System.out.println("请输入要查找学生的学号：");
        int sid = input.nextInt();
        Student stu = service.findStudent(sid);
        //需要在视图层展示
        System.out.println("-------返回查找的学生信息-------");
        if (stu == null) {
            System.out.println("没有此学生信息");
        } else {
            System.out.println(stu);
        }
        System.out.println("---------------------------------");
    }
}
