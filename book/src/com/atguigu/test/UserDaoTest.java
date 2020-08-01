package com.atguigu.test;

import com.atguigu.dao.UserDao;
import com.atguigu.dao.impl.UserDaoImpl;
import com.atguigu.projo.User;
import org.junit.Test;

import static org.junit.Assert.*;

public class UserDaoTest {

    UserDao userDao = new UserDaoImpl();
    @Test
    public void queryUserByUsername() {
        if (userDao.queryUserByUsername("admin") == null) {
            System.out.println("用户名可用");
        } else {
            System.out.println("用户名已存在");
        }
    }

    @Test
    public void queryUserByUsernameAndPassword() {
        if (userDao.queryUserByUsernameAndPassword("admin", "admin") == null) {
            System.out.println("用户名或密码错误，登陆失败");
        } else {
            System.out.println("登录成功");
        }
    }

    @Test
    public void saveUser() {
        if (userDao.saveUser(new User(null, "王子龙", "123456", "1428075@qq.com")) == -1) {
            System.out.println("此用户保存失败");
        } else {
            System.out.println("此用户保存成功");
        }
    }
}