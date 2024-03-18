//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
package utils;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.sql.*;
import java.util.Properties;


public class JDBCUtils {
    private static String driver;       //Driver驱动
    private static String url;          //Uniform Resource Locator，包含数据库信息
    private static String user;         //用户名
    private static String password;     //用户密码

    static {
        Properties properties = new Properties();
        try {


            properties.load(new FileReader("db.properties"));
            driver = properties.getProperty("driver");
            url = properties.getProperty("url");
            user = properties.getProperty("user");
            password = properties.getProperty("password");
            Class.forName(driver);
        } catch (ClassNotFoundException | IOException e) {
            throw new RuntimeException(e);
        }
    }

    //获取连接
    public static Connection getConnection() {
        try {
            return DriverManager.getConnection(url, user, password);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }


    public static void close(Connection connection) {
        /*
            DML的执行不产生ResultSet结果集，可以传入一个null;
            因此要先判断传入的对象是否为空，若非空则调用close方法关闭资源（动态绑定）
         */
        try {
            if (connection != null) {
                connection.close();
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        Connection connection=getConnection();
        close(connection);

    }
}