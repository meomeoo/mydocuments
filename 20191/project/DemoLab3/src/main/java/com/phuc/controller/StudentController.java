package com.phuc.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class StudentController {
    @RequestMapping(value = "student/add")
    public ModelAndView add() {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("student-form");
        return modelAndView;
    }

    @RequestMapping(value = "student/save", method = RequestMethod.POST)
    public ModelAndView save(@RequestParam(value = "name", required = false) String name, @RequestParam String age) {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("student-view");
        modelAndView.addObject("name", name);
        modelAndView.addObject("age", age);
        return modelAndView;
    }
}
