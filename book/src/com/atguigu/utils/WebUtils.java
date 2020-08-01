package com.atguigu.utils;

import org.apache.commons.beanutils.BeanUtils;

import javax.servlet.http.HttpServletRequest;
import java.lang.reflect.InvocationTargetException;
import java.util.Map;

public class WebUtils {

    /**
     * 把Map集合中的值注入到JavaBean属性中，耦合度低，易于扩充
     * @param value
     * @param bean
     * @param <T>
     * @return
     */
    public static <T> T copyParamToBean (Map value, T bean) {
        /**
         *   把所有的请求参数注入到User对象中
         *   使用泛型避免了类型转换
         */
        try {
            System.out.println("注入之前：" + bean);
            BeanUtils.populate(bean, value);
            System.out.println("注入之后：" + bean);
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        }
        return bean;
    }

    /**
     *  将字符串数字转换为整数
     * @param strInt
     * @param defaultValue
     * @return
     */
    public static int parseInt(String strInt, int defaultValue) {
        try {
            return Integer.parseInt(strInt);
        } catch (Exception e) {
            return defaultValue;
        }
    }
}
