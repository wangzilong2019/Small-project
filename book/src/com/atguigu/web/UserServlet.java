package com.atguigu.web;

import com.atguigu.projo.User;
import com.atguigu.service.UserService;
import com.atguigu.service.impl.UserServiceImpl;
import com.atguigu.utils.WebUtils;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.lang.reflect.Method;

public class UserServlet extends BaseServlet {
    private UserService userService = new UserServiceImpl();

    protected void login(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //1、获取请求参数
        String username = req.getParameter("username");
        String password = req.getParameter("password");

        //2、调用userService.login()处理登录业务
        User loginUser = userService.login(new User(null, username, password, null));
        //如果user为null则表明登录失败
        if (loginUser == null) {
            //把错误的信息和会显的表单项信息，保存到request域中
            req.setAttribute("msg", "用户名或密码错误");
            req.setAttribute("username", username);
            //登录失败，跳转到登录页面
            req.getRequestDispatcher("/pages/user/login.jsp").forward(req, resp);
        } else {
            //登录成功，跳转到登录成功页面
            req.getRequestDispatcher("/pages/user/login_success.jsp").forward(req, resp);
        }
    }
    protected void regist(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //1、获取请求参数
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        String email = req.getParameter("email");
        String code = req.getParameter("code");

        //使用bean注入技术
        User user =  WebUtils.copyParamToBean(req.getParameterMap(), new User());

        //2、判断验证码是否正确，这里写死 avdf
        if ("avdf".equalsIgnoreCase(code)) {
            //3、检查用户名是否可用
            if (userService.existUsername(username)) {
                //用户名已存在回显数据
                req.setAttribute("msg", "用户名已存在");
                req.setAttribute("email", email);
                //用户名已存在不可用，返回注册页面
                req.getRequestDispatcher("/pages/user/regist.jsp").forward(req, resp);
            } else {
                //可用，保存到数据库
                userService.registerUser(new User(null, username, password, email));

                //跳转到注册成功页面
                req.getRequestDispatcher("/pages/user/regist_success.jsp").forward(req, resp);
            }
        } else {
            //正确跳转到注册页面
            req.setAttribute("msg", "验证码错误！");
            //回写数据
            req.setAttribute("username", username);
            req.setAttribute("email", email);
            System.out.println("验证码" + code + "错误");
            req.getRequestDispatcher("/pages/user/regist.jsp").forward(req, resp);
        }
    }

/*    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //获取请求参数
        String action = req.getParameter("action");

        //获取action业务的字符串，获取相应的业务方法反射对象
        try {
            Method method = this.getClass().getDeclaredMethod(action, HttpServletRequest.class, HttpServletResponse.class);
            //调用目标业务方法
            method.invoke(this, req, resp);
        } catch (Exception e) {
            e.printStackTrace();
        }

*//*        if ("login".equals(action)) {
            //处理登录请求
            login(req, resp);
        } else if ("regist".equals(action)) {
            //处理注册请求
            regist(req, resp);
        }*//*
    }*/
}
