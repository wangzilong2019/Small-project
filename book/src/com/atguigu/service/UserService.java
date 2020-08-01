package com.atguigu.service;

import com.atguigu.projo.User;

/**
 *  此层为业务层，一个业务，一个方法
 *      登录、注册、验证表单信息都为业务
 * */
public interface UserService {


    /**
     * 注册用户
     * @param user
     */
    public void registerUser(User user);

    /**
     * 登录
     * @param user
     * @return  如果返回null则登录失败，有值则登录成功
     */
    public User login(User user);

    /**
     *  检查用户名是否可用
     * @param username
     * @return
     *    返回true表示用户名已存在不可用，false表示用户名可用
     */
    public boolean existUsername(String username);
}
