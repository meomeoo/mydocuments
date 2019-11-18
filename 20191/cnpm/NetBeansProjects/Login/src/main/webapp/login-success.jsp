<%-- 
    Document   : login-success
    Created on : 1 Oct 2019, 11:08:03
    Author     : meomeo
--%>

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
UserBean bean=(UserBean)request.getAttribute("bean");
out.print("Welcome, "+bean.getName());
%>
</body>
</html>
File login-error.jsp:
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Login failed</title>
</head>
<body>
<p>Sorry! username or password error</p>
<%@ include file="index.jsp" %>
</body>
</html>