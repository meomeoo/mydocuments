package com.phuc.controller;

import com.phuc.entity.StudentEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class StudentAutoController {
    @RequestMapping(value = "student-auto/add")
    public ModelAndView add() {
        return new ModelAndView("auto-mapping", "command", new StudentEntity());
    }

    @RequestMapping(value = "student-auto/save", method = RequestMethod.POST)
    public ModelAndView save(@ModelAttribute("student") StudentEntity student) {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("student-obj-view");
        modelAndView.addObject("student", student);
        return modelAndView;
    }
}
