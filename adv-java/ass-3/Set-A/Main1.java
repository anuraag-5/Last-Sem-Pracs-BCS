import java.sql.*;

public class Main1 {
    public static void main(String[] args) {
        try {
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/test", "root", "password");

            System.out.println("Database Connected Successfully!");

            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
