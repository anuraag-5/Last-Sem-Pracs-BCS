import java.sql.*;

public class Main2 {
    public static void main(String[] args) {
        try {
            Class.forName("org.postgresql.Driver");

            Connection con = DriverManager.getConnection(
                "jdbc:postgresql://localhost:5432/postgres?options=-c%20TimeZone=Asia/Kolkata",
                "postgres",
                "postgres"
            );

            con.setAutoCommit(false); // start transaction

            Statement stmt = con.createStatement();

            stmt.executeUpdate("INSERT INTO Student VALUES(10, 'Test1', 80)");
            stmt.executeUpdate("INSERT INTO Student VALUES(11, 'Test2', 85)");

            // Commit changes
            con.commit();
            System.out.println("Transaction committed!");

            con.close();

        } catch (Exception e) {
            System.out.println("Error occurred! Rolling back...");
            try {
                // rollback if error
                Connection con = DriverManager.getConnection(
                    "jdbc:postgresql://localhost:5432/postgres",
                    "postgres",
                    "postgres"
                );
                con.rollback();
            } catch (Exception ex) {
                System.out.println(ex);
            }
        }
    }
}