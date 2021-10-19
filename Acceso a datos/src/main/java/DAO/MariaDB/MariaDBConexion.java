package DAO.MariaDB;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class MariaDBConexion {
	private static Connection con=null;
	
	/**
	 * Debe ir cargado desde un xml externo
	 */
	private static String uri="jdbc:mysql://localhost/olimpiadas";
	private static String user="root";
	private static String password="";
	
	public static Connection getConexion() {
		if(con==null) {
			try {
				con=DriverManager.getConnection(uri,user,password);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				con=null;
			}
		}
		return con;
	}
	public static void cerrar() {
		if(con!=null) {
			try {
				con.close();
			}catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}
}
