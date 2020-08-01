package com.atguigu.dao;

import com.atguigu.projo.User;

public interface UserDao {

    /**
     *  根绝用户名查询用户信息（注册页面）
     *     查询不到返回null
     * */
    public User queryUserByUsername(String username);

    /**
     *   根据用户名和密码验证用户信息(登录界面)
     *     没有查询到返回null
     * */
    public User queryUserByUsernameAndPassword (String username, String password);

    /**
     *   保存用户信息
     *      返回-1表示操作失败
     *      成功返回影响的行数
     * */
    public int saveUser(User user);
}
