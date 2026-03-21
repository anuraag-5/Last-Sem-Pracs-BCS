import java.sql.*;
import java.util.Scanner;

public class Main1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            Class.forName("org.postgresql.Driver");

            Connection con = DriverManager.getConnection(
                "jdbc:postgresql://localhost:5432/postgres",
                "postgres",
                "postgres"
            );

            String query = "INSERT INTO Student(id, name, marks) VALUES (?, ?, ?)";
            PreparedStatement ps = con.prepareStatement(query);

            System.out.print("Enter ID: ");
            ps.setInt(1, sc.nextInt());

            sc.nextLine(); // clear buffer

            System.out.print("Enter Name: ");
            ps.setString(2, sc.nextLine());

            System.out.print("Enter Marks: ");
            ps.setInt(3, sc.nextInt());

            ps.executeUpdate();

            System.out.println("Record inserted successfully!");

            con.close();
            sc.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}