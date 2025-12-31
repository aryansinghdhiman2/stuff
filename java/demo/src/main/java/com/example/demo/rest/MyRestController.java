package com.example.demo.rest;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.Random;

@RestController
public class MyRestController {
    @GetMapping("/")
    public String hello()
    {
        return "Hello World!";
    }

    @GetMapping("/Bye")
    public String bye()
    {
        return "Good Bye!";
    }

    @GetMapping("/number")
    public String num()
    {
        return Integer.toString(new Random().nextInt(1, 101));
    }

}
