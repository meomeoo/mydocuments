package com.phuc.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

@Controller
@RequestMapping("/hello-post")
public class HelloClazzController3 {
    @RequestMapping(method = RequestMethod.POST)
    public ModelAndView printMessage(@RequestParam(value = "data", required = false) String message) {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("render");
        modelAndView.addObject("message", message);
        return modelAndView;
    }
}
