<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form" %>
<%--
  Created by IntelliJ IDEA.
  User: ITVND
  Date: 2019-08-01
  Time: 17:26
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Validator form</title>
</head>
<body>
<form:form method="POST" action="save">
    <table>
        <tr>
            <td><form:label path="name">Name:</form:label></td>
            <td><form:input path="name"/></td>
            <td><form:errors path="name"/></td>
        </tr>
        <tr>
            <td><form:label path="age">Age:</form:label></td>
            <td><form:input path="age" type="number"/></td>
            <td><form:errors path="age"/></td>
        </tr>
        <tr>
            <td colspan="2"><input value="Submit" type="submit"></td>
        </tr>
    </table>
</form:form>
</body>
</html>
