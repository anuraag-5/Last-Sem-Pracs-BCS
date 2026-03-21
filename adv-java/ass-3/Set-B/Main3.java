import java.sql.*;
import java.util.Scanner;

public class Main3 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        try {
            Class.forName("org.postgresql.Driver");

            Connection con = DriverManager.getConnection(
                "jdbc:postgresql://localhost:5432/postgres?options=-c%20TimeZone=Asia/Kolkata",
                "postgres",
                "postgres"
            );

            while (true) {
                System.out.println("\n1.Insert 2.Display 3.Search 4.Update 5.Delete 6.Exit");
                int ch = sc.nextInt();

                switch (ch) {

                    case 1: // Insert
                        System.out.print("Enter ID: ");
                        int id = sc.nextInt();
                        sc.nextLine();
                        System.out.print("Enter Name: ");
                        String name = sc.nextLine();
                        System.out.print("Enter Marks: ");
                        int marks = sc.nextInt();

                        PreparedStatement ps = con.prepareStatement(
                                "INSERT INTO Student VALUES (?, ?, ?)");
                        ps.setInt(1, id);
                        ps.setString(2, name);
                        ps.setInt(3, marks);
                        ps.executeUpdate();

                        System.out.println("Inserted!");
                        break;

                    case 2: // Display
                        Statement stmt = con.createStatement();
                        ResultSet rs = stmt.executeQuery("SELECT * FROM Student");

                        while (rs.next()) {
                            System.out.println(rs.getInt(1) + " " +
                                               rs.getString(2) + " " +
                                               rs.getInt(3));
                        }
                        break;

                    case 3: // Search
                        System.out.print("Enter ID to search: ");
                        int sid = sc.nextInt();

                        PreparedStatement ps2 = con.prepareStatement(
                                "SELECT * FROM Student WHERE id=?");
                        ps2.setInt(1, sid);
                        ResultSet rs2 = ps2.executeQuery();

                        if (rs2.next()) {
                            System.out.println("Found: " +
                                    rs2.getInt(1) + " " +
                                    rs2.getString(2) + " " +
                                    rs2.getInt(3));
                        } else {
                            System.out.println("Not Found");
                        }
                        break;

                    case 4: // Update
                        System.out.print("Enter ID to update: ");
                        int uid = sc.nextInt();
                        System.out.print("Enter new marks: ");
                        int newMarks = sc.nextInt();

                        PreparedStatement ps3 = con.prepareStatement(
                                "UPDATE Student SET marks=? WHERE id=?");
                        ps3.setInt(1, newMarks);
                        ps3.setInt(2, uid);

                        int rows = ps3.executeUpdate();
                        System.out.println(rows > 0 ? "Updated!" : "Not Found");
                        break;

                    case 5: // Delete
                        System.out.print("Enter ID to delete: ");
                        int did = sc.nextInt();

                        PreparedStatement ps4 = con.prepareStatement(
                                "DELETE FROM Student WHERE id=?");
                        ps4.setInt(1, did);

                        int drows = ps4.executeUpdate();
                        System.out.println(drows > 0 ? "Deleted!" : "Not Found");
                        break;

                    case 6:
                        con.close();
                        sc.close();
                        System.exit(0);
                }
            }

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}