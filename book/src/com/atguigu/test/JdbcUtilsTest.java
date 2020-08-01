package com.atguigu.test;

import com.atguigu.utils.JdbcUtils;
import org.junit.Test;

import java.sql.Connection;

public class JdbcUtilsTest {

    @Test
    public void testJdbcUtils() {
//        //此种方式只能连接十次
//        for (int i = 0; i < 100; i++) {
//            System.out.println(JdbcUtils.getConnection());
//        }
        //若要连接100次每次连接之和要释放
        for (int i = 0; i < 100; i++) {
            Connection conn = JdbcUtils.getConnection();
            System.out.println(conn);
            JdbcUtils.close(conn);
        }
    }

}
