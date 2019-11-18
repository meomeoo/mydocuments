<%-- 
    Document   : hello
    Created on : 1 Oct 2019, 08:31:40
    Author     : meomeo
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>JSP Page</title>
</head>
<body>
<h1>Helloooooooooo <%= request.getParameter("username") %></h1>
</body>
</html>