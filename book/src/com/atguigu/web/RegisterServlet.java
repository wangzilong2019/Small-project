package com.atguigu.web;

import com.atguigu.projo.User;
import com.atguigu.service.UserService;
import com.atguigu.service.impl.UserServiceImpl;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class RegisterServlet extends HttpServlet {
    /**
     *   1、获取请求参数
     *   2、检查验证码是否正确
     *      正确
     *         3、检查用户名是否可用
     *            可用
     *                调用service保存到数据库
     *                跳转到注册成功页面
     *            不可用
     *                返回注册成功页面
     *      错误
     *          返回注册页面
     *
     * */

    private UserService userService = new UserServiceImpl();
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //1、获取请求参数
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        String email = req.getParameter("email");
        String code = req.getParameter("code");

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

}
