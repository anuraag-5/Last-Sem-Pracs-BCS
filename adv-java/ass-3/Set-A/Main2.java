import java.sql.*;

public class Main2 {
    public static void main(String[] args) {
        try {
            Class.forName("org.postgresql.Driver");
            Connection con = DriverManager.getConnection(
                "jdbc:postgresql://localhost:5432/postgres", "postgres", "postgres");

            Statement stmt = con.createStatement();

            // Create table
            stmt.executeUpdate("CREATE TABLE IF NOT EXISTS Student(id INT, name VARCHAR(50), marks INT)");

            // Insert records
            stmt.executeUpdate("INSERT INTO Student VALUES(1, 'Amit', 85)");
            stmt.executeUpdate("INSERT INTO Student VALUES(2, 'Neha', 90)");
            stmt.executeUpdate("INSERT INTO Student VALUES(3, 'Rahul', 78)");

            System.out.println("Table created and records inserted!");

            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}