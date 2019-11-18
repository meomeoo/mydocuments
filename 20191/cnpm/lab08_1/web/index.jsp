<%-- 
    Document   : index
    Created on : Oct 30, 2019, 1:51:10 PM
    Author     : Admin
--%>

<%@page import="java.util.ArrayList"%>
<%@page import="entity.Product"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<div id="container">
    <div id="prod_wrapper">
        <div id="panes">
            <c:forEach var="product" items="${newProducts}">
                <div>
    o                <img src="${initParam.imgProductPath}${product.getImage()}" alt="" width="300" height="300">
                    <h5>${product.getName()}</h5>
                    <p>${product.getDescriptionDetail()}</p>
                    <p style="text-align: right; margin-right: 16px">
                        <a href="#" class="button">More Info</a>
                        <a href="#" class="button">Buy Now</a>
                    </p>
                </div>
            </c:forEach>
        </div>
        <!-- END tab panes -->
        <br clear="all">
        <!-- navigator -->
        <div id="prod_nav">
            <ul>
                <c:set var="countProduct" scope="request" value="${1}" />
                <c:forEach var="product" items="${newProducts}">
                    <li>
                        <a href="#${countProdcut}">
                            <img src="${initParam.imgProductPath}${product.getThumbImage()}" alt="">
                            <strong>${product.getName()}</strong> $ ${product.getPrice()}
                        </a>
                    </li>
                    <c:set var="countProduct" scope="request" value="${product.getPrice()}" />
                </c:forEach>
            </ul>
        </div>
        <!-- close navigator -->
    </div>
                <div style="clear:both"></div>  
                <div class="one-fourth frist_one_fourth">
                    <div class="heading_bg">
                        <h2>Mac</h2>
                    </div>
                    <img src="img/demo/4.jpg" width="217" alt="">
                </div>
                <div class="one-fourth">
                    <div class="heading_bg">
                        <h2>ipad</h2>
                    </div>
                    <img src="img/demo/6.jpg" width="217" alt="">
                </div>
                <div class="one-fourth">
                    <div class="heading_bg">
                        <h2>iPhone</h2>
                    </div>
                    <img src="img/demo/3.jpg" width="217" alt="">
                </div>
                <div class="one-fourth">
                    <div class="heading_bg">
                        <h2>Accessories</h2>
                    </div>
                    <img src="img/demo/1.jpg" width="217" alt="">
                </div>
                <div style="clear:both; height: 40px"></div>
</div>