package com.atguigu.test;

import com.atguigu.projo.User;
import com.atguigu.service.UserService;
import com.atguigu.service.impl.UserServiceImpl;
import org.junit.Test;

import static org.junit.Assert.*;

public class UserServiceTest {

    UserService userService = new UserServiceImpl();

    @Test
    public void registerUser() {
        userService.registerUser(new User(null, "bibi", "666", "666@qq.com"));
        userService.registerUser(new User(null, "苏C88888", "7758", "7758@qq.com"));
    }

    @Test
    public void login() {
        System.out.println(userService.login(new User(null, "bibi", "6662", "666@qq.com")));
    }

    @Test
    public void existUsername() {
        if (userService.existUsername("bibi")) {
            System.out.println("用户名已存在");
        } else {
            System.out.println("用户名可注册");
        }
    }
}