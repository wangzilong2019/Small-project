package com.stu.app;

import com.stu.view.StudentSystem;

/**
 * 系统入口类
 * */

public class StudentSystemApp {
    public static void main (String args[]) {
        final int SELECT_ALL = 1;
        final int ADD_STUDENT = 2;
        final int DEL_STUDENT = 3;
        final int UPDATE_STUDENT = 4;
        final int FIND_STUDENT = 5;
        final int EXIT_SYSTEM = 6;
        StudentSystem system = new StudentSystem();
        //启动系统
        system.start();

        //循环操作
        while (true) {
            //显示菜单
            system.menu();
            //选择菜单
            int index = system.selectMenu();

            switch (index) {
                case SELECT_ALL:
                    system.selectAll();
                    break;
                case ADD_STUDENT:
                    system.addStudent();
                    break;
                case DEL_STUDENT:
                    system.delStudent();
                    break;
                case UPDATE_STUDENT:
                    system.updateStudent();
                    break;
                case FIND_STUDENT:
                    system.findStudent();
                    break;
                case EXIT_SYSTEM:
                    system.exit();
                    break;
            }
        }
    }
}
