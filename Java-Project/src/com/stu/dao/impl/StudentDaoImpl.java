package com.stu.dao.impl;

import com.stu.dao.StudentDao;
import com.stu.entity.Student;
import com.stu.util.DBUtil;

import java.sql.*;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Objects;

/**
 * 通过jdbc访问数据库
 * */

public class StudentDaoImpl implements StudentDao {
    @Override
    public List<Student> selectStudent(String sql) {

          List<Student> list = new ArrayList<>();
//        String driver = "com.mysql.jdbc.Driver";
//        String url = "jdbc:mysql://127.0.0.1:3306/test" +
//                "?characterEncoding=UTF-8&useJDBCCompliantTimezoneShift=true&useLegacyDatetimeCode=false&serverTimezone=UTC";
//        String user = "root";
//        String password = "142063qx";

        Connection con = null;
        PreparedStatement ps = null;
        ResultSet rs = null;

        try {
//            //加载数据库驱动程序
//            Class.forName(driver);
//            //连接数据库
//            con = DriverManager.getConnection(url, user, password);
//            //创建用于向数据库发送sql语句的发送器
//            ps = con.prepareStatement(sql);

            con = DBUtil.getConnection();
            ps = DBUtil.getPs(con, sql);


            //将sql语句发送到数据库并返回结果集
            rs = ps.executeQuery();
            //解析结果集
            while (rs.next()) {
                int sid = rs.getInt("sid");
                String sname = rs.getString("sname");
                int sage = rs.getInt("sage");
                String sgender = rs.getString("sgender");
                Date enterdate = rs.getDate("enterdate");
                int cid = rs.getInt("cid");
                double score = rs.getDouble("score");
                Student stu = new Student(sid, sname, sage, sgender, enterdate, cid, score);
                list.add(stu);
            }

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
//            //关闭资源
//            if (rs != null) {
//                try {
//                    rs.close();
//                } catch (SQLException e) {
//                    e.printStackTrace();
//                }
//            }
//
//            if (ps != null) {
//                try {
//                    ps.close();
//                } catch (SQLException e) {
//                    e.printStackTrace();
//                }
//            }
//
//            if (con != null) {
//                try {
//                    con.close();
//                } catch (SQLException e) {
//                    e.printStackTrace();
//                }
//            }
            DBUtil.closeAll(rs, ps, con);
        }
        return list;
    }

    @Override
    public int add(String sql, Student student) {

//        String driver = "com.mysql.jdbc.Driver";
//        String url = "jdbc:mysql://127.0.0.1:3306/test" +
//                "?characterEncoding=UTF-8&useJDBCCompliantTimezoneShift=true&useLegacyDatetimeCode=false&serverTimezone=UTC";
//        String user = "root";
//        String password = "142063qx";

        Connection con = null;
        PreparedStatement ps = null;
        int count;
        try {
            //加载数据库驱动程序
//            Class.forName(driver);
//            //连接数据库
//            con = DriverManager.getConnection(url, user, password);
//            //创建用于向数据库发送sql语句的发送器
//            ps = con.prepareStatement(sql);
            con = DBUtil.getConnection();
            ps = DBUtil.getPs(con, sql);

            //对通配符元素进行赋值
            Object[] parmas = {student.getSid(), student.getSname(), student.getSage(), student.getSgender(),
                    student.getEnterDate(), student.getCid(), student.getScore()};
//            for (int i = 0; i < parmas.length; i++) {
//                ps.setObject(i+1, parmas[i]);
//            }
            //绑定参数
            DBUtil.bindParam(ps, parmas);


            //将sql语句发送到数据库
            count = ps.executeUpdate();
            return count;

        } catch (Exception e) {
            e.printStackTrace();
        } finally {

//            if (ps != null) {
//                try {
//                    ps.close();
//                } catch (SQLException e) {
//                    e.printStackTrace();
//                }
//            }
//
//            if (con != null) {
//                try {
//                    con.close();
//                } catch (SQLException e) {
//                    e.printStackTrace();
//                }
//            }
            DBUtil.closeAll(ps, con);
        }
        return 0;
    }

    @Override
    public int del(String sql, int sid) {
//        String driver = "com.mysql.jdbc.Driver";
//        String url = "jdbc:mysql://127.0.0.1:3306/test" +
//                "?characterEncoding=UTF-8&useJDBCCompliantTimezoneShift=true&useLegacyDatetimeCode=false&serverTimezone=UTC";
//        String user = "root";
//        String password = "142063qx";

        Connection con = null;
        PreparedStatement ps = null;
        int count;
        try {
//            //加载数据库驱动程序
//            Class.forName(driver);
//            //连接数据库
//            con = DriverManager.getConnection(url, user, password);
//            //创建用于向数据库发送sql语句的发送器
//            ps = con.prepareStatement(sql);
            con = DBUtil.getConnection();
            ps = DBUtil.getPs(con, sql);

//            ps.setObject(1, sid);
            //绑定参数
            DBUtil.bindParam(ps, sid);

            //将sql语句发送到数据库
            count = ps.executeUpdate();
            return count;

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
//
//            if (ps != null) {
//                try {
//                    ps.close();
//                } catch (SQLException e) {
//                    e.printStackTrace();
//                }
//            }
//
//            if (con != null) {
//                try {
//                    con.close();
//                } catch (SQLException e) {
//                    e.printStackTrace();
//                }
//            }
            DBUtil.closeAll(ps, con);
        }
        return 0;
    }

    @Override
    public int update(String sql, int sid, Student student) {
        Connection con = null;
        PreparedStatement ps = null;
        int count = 0;
        try {
            con = DBUtil.getConnection();
            ps = DBUtil.getPs(con, sql);

            //对通配符元素进行赋值
            Object[] parmas = {student.getSid(), student.getSname(), student.getSage(), student.getSgender(),
                    student.getEnterDate(), student.getCid(), student.getScore(), sid};
            //绑定参数
            DBUtil.bindParam(ps, parmas);

            //将sql语句发送到数据库
            count = ps.executeUpdate();
            return count;

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            //关闭资源
            DBUtil.closeAll(ps, con);
        }
        return 0;
    }

    @Override
    public Student find(String sql, int sid) {
        Connection con = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        Student student = null;
        try {
            con = DBUtil.getConnection();
            ps = DBUtil.getPs(con, sql);

            //对通配符元素进行赋值
            Object[] parmas = {sid};
            //绑定参数
            DBUtil.bindParam(ps, parmas);

            //将sql语句发送到数据库,并 返回结果集
            rs = ps.executeQuery();
            //解析结果集
            while (rs.next()) {
                int id = rs.getInt("sid");
                String sname = rs.getString("sname");
                int sage = rs.getInt("sage");
                String sgender = rs.getString("sgender");
                Date enterdate = rs.getDate("enterdate");
                int cid = rs.getInt("cid");
                double score = rs.getDouble("score");
                student= new Student(sid, sname, sage, sgender, enterdate, cid, score);
            }
            return student;

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            //关闭资源
            DBUtil.closeAll(ps, con);
        }
        return null;
    }
}
