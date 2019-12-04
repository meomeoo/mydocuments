<%--
  Created by IntelliJ IDEA.
  User: ITVND
  Date: 2019-08-01
  Time: 10:22
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Student form</title>
</head>
<body>
    <h2>Please input student information:</h2>
    <form method="POST" action="save">
        <table>
            <tr>
                <td>Name:</td>
                <td><input name="name" type="text"></td>
            </tr>
            <tr>
                <td>Age:</td>
                <td><input name="age" type="text"></td>
            </tr>
            <tr>
                <td colspan="2"><input value="Submit" type="submit"></td>
            </tr>
        </table>
    </form>
</body>
</html>
