package DAO.MariaDB;


import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import DAO.complejoDAO;
import DAO.model.Complejo;
import DAO.model.Sede;

public class ComplejoDAOImpMariaDB extends Complejo implements complejoDAO{
	private static final String INSERT = "INSERT INTO complejo " + "(nombre,localizacion,jefe,area_total,tipo,id_sede) VALUES (?,?,?,?,?,?)";
	private static final String MOSTRARTODOS = "SELECT id,nombre,localizacion,jefe,area_total,tipo,id_sede FROM complejo";
	private static final String MOSTRARPORID = "SELECT id,nombre,localizacion,jefe,area_total,tipo,id_sede FROM complejo WHERE id=?";
	private static final String EDITAR = "UPDATE complejo SET nombre=?,localizacion=?,jefe=?,area_total=?,tipo=?,id_sede=? WHERE id=?";
	private static final String BORRAR = "DELETE FROM complejo WHERE id=?";
	private static final String MOSTRARPORSEDE = "SELECT id,nombre,localizacion,jefe,area_total,tipo,id_sede FROM complejo WHERE id_sede=?";

	private Connection con = null;

	public ComplejoDAOImpMariaDB() {
		super();
	}

	public ComplejoDAOImpMariaDB(String nombre, String localizacion, String jefe, 
			float area_total, boolean tipo, Sede sede) {
		super(nombre,localizacion,jefe,area_total,tipo,sede);
	}

	public ComplejoDAOImpMariaDB(int id, String nombre, String localizacion, String jefe, float area_total, boolean tipo, Sede sede) {
		super(id, nombre,localizacion,jefe,area_total,tipo,sede);
	}
	public ComplejoDAOImpMariaDB(Complejo c) {
		super(c.getId(),c.getNombre(),
				c.getLocalizacion(),c.getJefe(),c.getArea_total(),
				c.isTipo(),c.getSede());
	}

	public void guardar() {
		if (id != -1) {
			editar();
		} else {
			con = MariaDBConexion.getConexion();
			if (con != null) {
				PreparedStatement ps=null;
				ResultSet rs=null;
				try {
					ps = con.prepareStatement(INSERT, Statement.RETURN_GENERATED_KEYS);

					ps.setString(1, this.nombre);
					ps.setString(2, this.localizacion);
					ps.setString(3, this.jefe);
					ps.setFloat(4, this.area_total);
					ps.setBoolean(5, this.tipo);
					ps.setInt(6, this.sede.getId());
					
					ps.executeUpdate();
					// Solo lo puedes ejecutar si has puesto RETURN_GENERATED_KEYS
					rs = ps.getGeneratedKeys();
					if (rs.next()) {
						this.id = rs.getInt(1);
					}
					// fin de extraer el id generado automaticamente en la db
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} finally {
					try {
						ps.close();
						rs.close();
					}catch (SQLException e) {
						// TODO: handle exception
					}
				}
			}
		}
	}

	public void editar() {
		con = MariaDBConexion.getConexion();
		if (con != null) {
			PreparedStatement ps=null;
			try {
				ps = con.prepareStatement(EDITAR);

				ps.setString(1, this.nombre);
				ps.setString(2, this.localizacion);
				ps.setString(3, this.jefe);
				ps.setFloat(4, this.area_total);
				ps.setBoolean(5, this.tipo);
				ps.setInt(6, this.sede.getId());
				ps.setInt(7, this.id);
				ps.executeUpdate();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				try {
					ps.close();
				}catch (SQLException e) {
					// TODO: handle exception
				}
			}
		}

	}

	public void borrar() {
		con = MariaDBConexion.getConexion();
		if (con != null) {
			PreparedStatement ps=null;
			try {
				ps = con.prepareStatement(BORRAR);
				ps.setInt(1, this.id);
				ps.executeUpdate();
				this.id=-1;
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				try {
					ps.close();
				}catch (SQLException e) {
					// TODO: handle exception
				}
			}
		}

	}

	public List<Complejo> mostrarTodos() {
		List<Complejo> resultado=new ArrayList<Complejo>();
		
		con = MariaDBConexion.getConexion();
		if (con != null) {
			PreparedStatement ps=null;
			ResultSet rs=null;
			try {
				ps = con.prepareStatement(MOSTRARTODOS);
				rs=ps.executeQuery();
				
				while(rs.next()) {
					
					SedeDAOImpMariaDB x = new SedeDAOImpMariaDB();
					Sede xs = x.mostrar(rs.getInt("id_sede"));
					
					resultado.add(new Complejo(rs.getInt("id"),
							rs.getString("nombre"),
							rs.getString("localizacion"),
							rs.getString("jefe"),
							rs.getFloat("area_total"),
							rs.getBoolean("tipo"),
							xs));
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				try {
					ps.close();
					rs.close();
				}catch (SQLException e) {
					// TODO: handle exception
				}
			}
		}
		return resultado;
	}

	public Complejo mostrar(int id) {
		Complejo resultado=new Complejo();
		
		con = MariaDBConexion.getConexion();
		if (con != null) {
			PreparedStatement ps=null;
			ResultSet rs=null;
			try {
				ps = con.prepareStatement(MOSTRARPORID);
				ps.setInt(1,id);
				rs=ps.executeQuery();
				if(rs.next()) {
					
					SedeDAOImpMariaDB x = new SedeDAOImpMariaDB();
					Sede xs = x.mostrar(rs.getInt("id_sede"));
					
					resultado=new Complejo(rs.getInt("id"),
							rs.getString("nombre"),
							rs.getString("localizacion"),
							rs.getString("jefe"),
							rs.getFloat("area_total"),
									rs.getBoolean("tipo"),
									xs);
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				try {
					ps.close();
					rs.close();
				}catch (SQLException e) {
					// TODO: handle exception
				}
			}
		}
		return resultado;
	}
	
	public List<Complejo> mostrarPorSede(int id) {
		List<Complejo> resultado=new ArrayList<Complejo>();
		
		con = MariaDBConexion.getConexion();
		if (con != null) {
			PreparedStatement ps=null;
			ResultSet rs=null;
			try {
				ps = con.prepareStatement(MOSTRARPORSEDE);
				ps.setInt(1,id);
				rs=ps.executeQuery();
				if(rs.next()) {
					
					SedeDAOImpMariaDB x = new SedeDAOImpMariaDB();
					Sede xs = x.mostrar(rs.getInt("id_sede"));
					
					resultado.add(new Complejo(rs.getInt("id"),
							rs.getString("nombre"),
							rs.getString("localizacion"),
							rs.getString("jefe"),
							rs.getFloat("area_total"),
									rs.getBoolean("tipo"),
									xs));
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				try {
					ps.close();
					rs.close();
				}catch (SQLException e) {
					// TODO: handle exception
				}
			}
		}
		return resultado;
	}
	
	public Complejo mostrarPorNombre(String nombre) {
		// TODO Auto-generated method stub
		return null;
	}
	
}
