package com.atguigu.service;

import com.atguigu.projo.Book;
import com.atguigu.projo.Page;

import java.util.List;

public interface BookService {

    public void addBook(Book book);

    public void deleteById(Integer id);

    public void updateBook(Book book);

    public Book queryBookById(Integer id);

    public List<Book> queryBooks();

    public Page<Book> page(int pageNo, int pageSize);
}
