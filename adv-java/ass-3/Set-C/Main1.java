import java.sql.*;

public class Main1 {
    public static void main(String[] args) {
        try {
            Class.forName("org.postgresql.Driver");

            Connection con = DriverManager.getConnection(
                "jdbc:postgresql://localhost:5432/postgres?options=-c%20TimeZone=Asia/Kolkata",
                "postgres",
                "postgres"
            );

            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM Student");

            ResultSetMetaData rsmd = rs.getMetaData();

            int colCount = rsmd.getColumnCount();

            // Display column names
            System.out.println("Columns:");
            for(int i = 1; i <= colCount; i++) {
                System.out.print(rsmd.getColumnName(i) + "\t");
            }

            System.out.println("\n\nData:");

            // Display records
            while(rs.next()) {
                for(int i = 1; i <= colCount; i++) {
                    System.out.print(rs.getString(i) + "\t");
                }
                System.out.println();
            }

            con.close();

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}