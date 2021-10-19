import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class Ejecutable {
	public static void main(String[] args) {
		String uri="jdbc:mysql://localhost/olimpiadas";
		Connection con=null;
		try {
			con=DriverManager.getConnection(uri,
					"root", "");
			Statement st=con.createStatement();
			ResultSet rs=st.executeQuery("SELECT localizacion,deporte FROM area");
			while(rs.next()) {
				System.out.println(rs.getString("localizacion")+"-"+
							rs.getString("deporte"));
			}
				rs.close();
				st.close();
				
			PreparedStatement pst=con.prepareStatement("SELECT * FROM area WHERE id=?");
			pst.setInt(1, 1);
			rs=pst.executeQuery();
			if(rs.next()) {
				System.out.println(rs.getString("localizacion")+"-"+
						rs.getString("deporte"));
			}else {
				System.out.println("nada a mostrar");
			}
			
			rs.close();
			pst.close();
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				con.close();
			}catch(SQLException e) {
				e.printStackTrace();
			}
		}
	}
}
