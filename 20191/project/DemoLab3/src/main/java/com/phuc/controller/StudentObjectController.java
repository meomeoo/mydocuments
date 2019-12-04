package com.phuc.controller;

import com.phuc.entity.StudentEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

import java.util.Date;

@Controller
public class StudentObjectController {
    @RequestMapping(value = "student-object/add")
    public ModelAndView add() {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("student-form");
        return modelAndView;
    }

    @RequestMapping(value = "student-object/save", method = RequestMethod.POST)
    public ModelAndView save(@RequestParam(value = "name", required = false) String name, @RequestParam Integer age) {
        ModelAndView modelAndView = new ModelAndView();
        StudentEntity studentEntity = new StudentEntity(name, age);
        modelAndView.setViewName("student-obj-view");
        /*modelAndView.addObject("name", name);
        modelAndView.addObject("age", age);*/
        modelAndView.addObject("student", studentEntity);
        return modelAndView;
    }
}
