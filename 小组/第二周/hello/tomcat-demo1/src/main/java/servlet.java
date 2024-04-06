import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/req")
public class servlet extends HttpServlet {


        @Override
        protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
            System.out.println("get...");
            String username = req.getParameter("username");
            String password = req.getParameter("password");

            //若不输入账户密码，设置状态码404
            if (username .equals("") || password .equals("")) {
                System.out.println("Parameter is null");
                resp.setStatus(404);
            }
            //用户名与密码若相等，设置状态码200
            else if (username.equals(password)) {
                System.out.println("username equals to password");
                resp.setStatus(200);
            }
            //其他，设置状态码500
            else {
                System.out.println("username doesn't equal to password");
                resp.setStatus(500);
            }



        }

        //通过req.html传参进行post请求
        @Override
        protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
            System.out.println("post...");
            String username = req.getParameter("username");
            String password = req.getParameter("password");

            //若不输入账户密码，设置状态码404
            if (username .equals("") || password .equals("")) {
                System.out.println("Parameter is null");
                resp.setStatus(404);
            }
            //用户名与密码若相等，设置状态码200
            else if (username.equals(password)) {
                System.out.println("username equals to password");
                resp.setStatus(200);
            }
            //其他，设置状态码500
            else {
                System.out.println("username doesn't equal to password");
                resp.setStatus(500);
            }

        }

    }
