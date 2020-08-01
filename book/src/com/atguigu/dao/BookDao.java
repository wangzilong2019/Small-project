package com.atguigu.dao;

import com.atguigu.projo.Book;

import java.util.List;

public interface BookDao {

    /**
     * 添加图书，返回-1表明添加失败，否则添加成功
     * @param book
     * @return
     */
    public int addBook(Book book);

    /**
     * 根据id删除图书，返回-1则删除失败，否则删除成功
     * @param id
     * @return
     */
    public int deleteBookById(Integer id);

    /**
     * 修改图书，若返回-1则修改失败，否则修改成功
     * @param book
     * @return
     */
    public int updateBook(Book book);
    /**
     * 根据id查询图书，有则返回Book对象，否则返回null
     * @param id
     * @return
     */
    public Book queryBookById(Integer id);

    /**
     * 查询所有图书将结果放在一个list集合中返回
     * @return
     */
    public List<Book> queryBooks();

    public int queryForPageTotalCount();

    public List<Book> queryForPageItems(int begin, int pageSize);
}
