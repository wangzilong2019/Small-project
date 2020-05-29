package com.stu.util;

import java.io.Closeable;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.Properties;

/**
 * 将数据库的相关信息写到配置文件中，当工具类加载时读取到工具类中
 *
 * */

public class DBUtil {

    private static String driver;
    private static String url;
    private static String useName;
    private static String password;

    //类加载的时候读取配置文件的内容,保存到对应的变量中
    static {
        Properties properties = new Properties();
        try {
            properties.load(DBUtil.class.getClassLoader().getResourceAsStream("db.prop"));
            driver = properties.getProperty("driver");
            url = properties.getProperty("url");
            useName = properties.getProperty("useName");
            password = properties.getProperty("password");

            System.out.println(driver);
            System.out.println(url);
            System.out.println(useName);
            System.out.println(password);

            //加载数据库驱动程序 一次就好
            Class.forName(driver);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    //连接数据库
    public static Connection getConnection() {
        try {
            return DriverManager.getConnection(url, useName, password);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    //创建sql语句发送器
    public static PreparedStatement getPs(Connection con, String sql) {
        try {
            return con.prepareStatement(sql);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    //关闭所有资源
    public static void closeAll(AutoCloseable ... closeables) {
        for (AutoCloseable closeable : closeables) {
            if (closeable != null) {
                try {
                    closeable.close();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }

    /**
     *  绑定若干个参数
     * */
    public static void bindParam(PreparedStatement ps, Object ... os) {
        for (int i = 0; i < os.length; i++) {
            try {
                ps.setObject(i + 1, os[i]);
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

}
