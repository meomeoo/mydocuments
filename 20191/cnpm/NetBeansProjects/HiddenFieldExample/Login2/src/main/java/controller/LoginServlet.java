/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package controller;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import model.UserBean;

public class LoginServlet extends HttpServlet {

    protected  void doPost(HttpServletRequest request, HttpServletResponse response) 
            throws IOException, ServletException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        String name = request.getParameter("name");
        String password = request.getParameter("password");

        UserBean bean = new UserBean();
        bean.setName(name);
        bean.setPassword(password);
        request.setAttribute("bean", bean);

        boolean status = bean.validate();

        if (status) {
            RequestDispatcher rd = request.getRequestDispatcher("login-success.jsp");
            rd.forward(request, response);
        } else {
            RequestDispatcher rd = request.getRequestDispatcher("login-error.jsp");
            rd.forward(request, response);
        }
    }

    protected  void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException, ServletException {
        doPost(req, resp);
    }
}
