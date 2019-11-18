/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bll;

import entity.Product;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.sql.DataSource;

/**
 *
 * @author Admin
 */
public class ProductBLL {

    public List<Product> getNewProducts(int number) {

        List<Product> prods = new ArrayList<>();
        try {
            Context initContext = new InitialContext();
            DataSource ds = (DataSource) initContext.lookup("java:comp/env/jdbc/eMarket");
            Connection conn = ds.getConnection();
            Statement sttm = conn.createStatement();
            String sql = "select * from product";
            ResultSet rs = sttm.executeQuery(sql);
            while (rs.next()) {
                Product p = new Product();
                p.setProductID(rs.getInt("product_id"));

                p.setCategoryID(rs.getInt("Categorycategory_id"));
                p.setPrice((rs.getBigDecimal("price").floatValue()));

                p.setName(rs.getString("name"));
                System.out.print(rs.getString("name"));
                p.setDescription(rs.getString("description"));

                p.setImage(rs.getString("image"));

                p.setThumbImage(rs.getString("thumb_image"));
                p.setLastUpdate(rs.getDate("last_update"));
                p.setDescriptionDetail(rs.getString("description_detail"));
                prods.add(p);

            }
        } catch (SQLException ex) {
            System.err.println(ex);
        } catch (NamingException ex) {
            Logger.getLogger(ProductBLL.class.getName()).log(Level.SEVERE, null, ex);
        }

        return prods;
    }
}
