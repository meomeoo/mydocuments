package com.phuc.controller;

import com.phuc.entity.StudentEntity;
import com.phuc.entity.StudentValidator;
import org.springframework.stereotype.Controller;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.ModelAndView;

import javax.validation.Valid;

@Controller
public class StudentValidController {
    @RequestMapping(value = "student-valid/add")
    public ModelAndView add() {
        return new ModelAndView("auto-mapping", "command", new StudentValidator());
    }

    @RequestMapping(value = "student-valid/save", method = RequestMethod.POST)
    public ModelAndView save(@Valid @ModelAttribute("command") StudentValidator student, BindingResult bindingResult) {
        ModelAndView modelAndView = new ModelAndView("student-valid-form", "command", student);
        if (bindingResult.hasErrors()) {
            modelAndView.addObject("errors", bindingResult);
        }
        modelAndView.addObject("student", student);
        return modelAndView;
    }
}
