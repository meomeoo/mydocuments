<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="model.UserBean" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Login success</title>
    </head>
    <body>
        <p>You are successfully logged in!</p>
        <%
            UserBean bean = (UserBean) request.getAttribute("bean");
            out.print("Welcome, " + bean.getName());
        %>
    </body>
</html>