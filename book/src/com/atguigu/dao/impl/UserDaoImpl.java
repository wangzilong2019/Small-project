package com.atguigu.dao.impl;

import com.atguigu.dao.UserDao;
import com.atguigu.projo.User;

public class UserDaoImpl extends BaseDao implements UserDao {
    @Override
    public User queryUserByUsername(String username) {
        String sql = "select * from t_user where username = ?;";
        return queryOne(User.class, sql, username);
    }

    @Override
    public User queryUserByUsernameAndPassword(String username, String password) {
        String sql = "select * from t_user where username = ? and password = ?;";
        return queryOne(User.class, sql, username, password);
    }

    @Override
    public int saveUser(User user) {
        String sql = "insert into t_user(username, password, email) values(?, ?, ?);";
        return update(sql, user.getUsername(), user.getPassword(), user.getEmail());
    }
}
