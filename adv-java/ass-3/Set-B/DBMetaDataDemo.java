import java.sql.*;

public class DBMetaDataDemo {
    public static void main(String[] args) {
        try {
            Class.forName("org.postgresql.Driver");

            Connection con = DriverManager.getConnection(
                "jdbc:postgresql://localhost:5432/postgres?options=-c%20TimeZone=Asia/Kolkata",
                "postgres",
                "postgres"
            );

            DatabaseMetaData dbmd = con.getMetaData();

            System.out.println("Database Product Name: " + dbmd.getDatabaseProductName());
            System.out.println("Database Version: " + dbmd.getDatabaseProductVersion());
            System.out.println("Driver Name: " + dbmd.getDriverName());
            System.out.println("Driver Version: " + dbmd.getDriverVersion());
            System.out.println("User Name: " + dbmd.getUserName());

            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}