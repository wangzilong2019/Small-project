package com.stu.entity;

import java.io.Serializable;
import java.util.Date;

/**
 *  学生的字段：学号、姓名、年龄、性别、入学日期、班级编号、分数
 *   一半基本类型用包装类
 * */

public class Student implements Serializable {

    private static final long serialVersionUID = 1;
    private Integer sid;
    private String sname;
    private Integer sage;
    private String sgender;
    private Date enterdate;
    private Integer cid;
    private Double score;

    //创建无参构造方法
    public Student() {

    }

    //创建带参构造方法

    public Student(Integer sid, String sname, Integer sage, String sgender, Date enterdate, Integer cid, Double score) {
        this.sid = sid;
        this.sname = sname;
        this.sage = sage;
        this.sgender = sgender;
        this.enterdate = enterdate;
        this.cid = cid;
        this.score = score;
    }

    //访问器和修改器

    public static long getSerialVersionUID() {
        return serialVersionUID;
    }

    public Integer getSid() {
        return sid;
    }

    public void setSid(Integer sid) {
        this.sid = sid;
    }

    public String getSname() {
        return sname;
    }

    public void setSname(String sname) {
        this.sname = sname;
    }

    public Integer getSage() {
        return sage;
    }

    public void setSage(Integer sage) {
        this.sage = sage;
    }

    public String getSgender() {
        return sgender;
    }

    public void setSgender(String sgender) {
        this.sgender = sgender;
    }

    public Date getEnterDate() {
        return enterdate;
    }

    public void setEnterDate(Date enterdate) {
        this.enterdate = enterdate;
    }

    public Integer getCid() {
        return cid;
    }

    public void setCid(Integer cid) {
        this.cid = cid;
    }

    public Double getScore() {
        return score;
    }

    public void setScore(Double score) {
        this.score = score;
    }

    @Override
    public String toString() {
        return "Student{" +
                "sid=" + sid +
                ", sname='" + sname + '\'' +
                ", sage=" + sage +
                ", sgender='" + sgender + '\'' +
                ", enterdate=" + enterdate +
                ", cid=" + cid +
                ", score=" + score +
                '}';
    }
}
