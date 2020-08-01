package com.atguigu.web;

import com.atguigu.dao.impl.BaseDao;
import com.atguigu.projo.Book;
import com.atguigu.projo.Page;
import com.atguigu.service.BookService;
import com.atguigu.service.impl.BookServiceImpl;
import com.atguigu.utils.WebUtils;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

public class BookServlet extends BaseServlet {

    private BookService bookService = new BookServiceImpl();

    protected void add(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        int pageNo = WebUtils.parseInt(req.getParameter("pageNo"), 0);
        pageNo++;
        //1、获取请求参数封装为Book对象
        Book book = WebUtils.copyParamToBean(req.getParameterMap(), new Book());
        //2、调用addBook()方法添加图书
        bookService.addBook(book);
        //3、跳转到图书列表页面
        //这里使用重定向，不适用请求转发，否则按F5会重复提交
        resp.sendRedirect(req.getContextPath() + "/manager/bookServlet?action=page&pageNo=" + pageNo);
    }

    /**
     *  处理分页功能
     * @param req
     * @param resp
     * @throws ServletException
     * @throws IOException
     */
    protected void page(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //1、获取请求参数pageNo和pageSize
        int pageNo = WebUtils.parseInt(req.getParameter("pageNo"), 1);
        int pageSize = WebUtils.parseInt(req.getParameter("pageSize"), Page.PAGE_SIZE);


        //2、调用方法生成Page对象
        Page<Book> page = bookService.page(pageNo, pageSize);
        //将Book对象保存到Request域中
        req.setAttribute("page", page);
        //重定向跳转到页面
        req.getRequestDispatcher("/pages/manager/book_manager.jsp").forward(req, resp);
    }

    protected void delete(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //1、获取请求参数id
        int id = WebUtils.parseInt(req.getParameter("id"), 0);
        //2、调用方法删除图书
        bookService.deleteById(id);
        //重定向到图书页面
        resp.sendRedirect(req.getContextPath()+ "/manager/bookServlet?action=page&pageNo=" + req.getParameter("pageNo"));
    }

    protected void update(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //1、获取请求的参数且封装为Book对象
        Book book = WebUtils.copyParamToBean(req.getParameterMap(), new Book());
        //2、调用方法更新图书
        bookService.updateBook(book);
        //3、重定向到图书展示页面
        resp.sendRedirect(req.getContextPath()+ "/manager/bookServlet?action=page&pageNo=" + req.getParameter("pageNo"));
    }
    protected void getBook(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //1、获取请求的参数
        int id = WebUtils.parseInt(req.getParameter("id"), 0);
        //2、调用方法查询图书
        Book book = bookService.queryBookById(id);
        //3、将图书保存到Request域中
        req.setAttribute("book", book);
        //请求准发到页面
        req.getRequestDispatcher("/pages/manager/book_edit.jsp").forward(req, resp);
    }

    protected void list(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //1、通过bookService查询所有图书
        List<Book> books = bookService.queryBooks();
        //2、将全部图书保存到Request域中
        req.setAttribute("books", books);
        //3、请求转发到/pages/manager/book_manager.jsp页面
        req.getRequestDispatcher("/pages/manager/book_manager.jsp").forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doPost(req, resp);
    }
}
