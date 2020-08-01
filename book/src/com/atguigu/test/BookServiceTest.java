package com.atguigu.test;

import com.atguigu.projo.Book;
import com.atguigu.projo.Page;
import com.atguigu.service.BookService;
import com.atguigu.service.impl.BookServiceImpl;
import org.junit.Test;

import java.math.BigDecimal;

import static org.junit.Assert.*;

public class BookServiceTest {

    private BookService bookService = new BookServiceImpl();

    @Test
    public void addBook() {
        bookService.addBook(new Book(null, "少龙帅a", "沙龙", new BigDecimal(67), 89, 9, null));
    }

    @Test
    public void deleteById() {
    }

    @Test
    public void updateBook() {
        bookService.updateBook(new Book(null, "社会龙", "沙龙", new BigDecimal(67), 89, 9, null));
    }

    @Test
    public void queryBookById() {
        System.out.println(bookService.queryBookById(3));;
    }

    @Test
    public void queryBooks() {
        for (Book book : bookService.queryBooks()) {
            System.out.println(book);
        }
    }

    @Test
    public void page() {
        System.out.println(bookService.page(1, Page.PAGE_SIZE));
    }
}