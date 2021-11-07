package DAO.MariaDB;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import DAO.SedeDAO;
import DAO.model.Complejo;
import DAO.model.Sede;

public class SedeDAOImpMariaDB extends Sede implements SedeDAO {

	private static final String INSERT = "INSERT INTO sede " + "(nombre,presupuesto,ncomplejos) VALUES (?,?,?)";
	private static final String MOSTRARTODOS = "SELECT id,nombre" + ",presupuesto,ncomplejos FROM sede";
	private static final String MOSTRARPORID = "SELECT id,nombre" + ",presupuesto,ncomplejos FROM sede WHERE id=?";
	private static final String EDITAR = "UPDATE sede SET nombre=?" + ",presupuesto=?,ncomplejos=? WHERE id=?";
	private static final String BORRAR = "DELETE FROM sede WHERE id=?";

	private static final String MOSTRARPORNOMBRE = "SELECT id,nombre"
			+ ",presupuesto,ncomplejos FROM sede WHERE nombre LIKE ?";

	private Connection con = null;
	private boolean persisted = false;
	
	public SedeDAOImpMariaDB() {
		super();
	}

	public SedeDAOImpMariaDB(String nombre, float presupuesto, int ncomplejos) {
		super(nombre, presupuesto, ncomplejos);
	}

	public SedeDAOImpMariaDB(int id, String nombre, float presupuesto, int ncomplejos) {
		super(id, nombre, presupuesto, ncomplejos);
	}
	public SedeDAOImpMariaDB(Sede s) {
		super(s.getId(),s.getNombre(),s.getPresupuesto(),s.getNcomplejos());
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
					ps.setFloat(2, this.presupuesto);
					ps.setInt(3, this.ncomplejos);
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
				ps.setFloat(2, this.presupuesto);
				ps.setInt(3, this.ncomplejos);
				ps.setInt(4, this.id);
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

	public List<Sede> mostrarTodos() {
		List<Sede> resultado=new ArrayList<Sede>();
		
		con = MariaDBConexion.getConexion();
		if (con != null) {
			PreparedStatement ps=null;
			ResultSet rs=null;
			try {
				ps = con.prepareStatement(MOSTRARTODOS);
				rs=ps.executeQuery();
				while(rs.next()) {
					resultado.add(new SedeDAOImpMariaDB(rs.getInt("id"),
							rs.getString("nombre"),
							rs.getFloat("presupuesto"),
							rs.getInt("ncomplejos")));
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

	public Sede mostrar(int id) {
		Sede resultado=new SedeDAOImpMariaDB();
		
		con = MariaDBConexion.getConexion();
		if (con != null) {
			PreparedStatement ps=null;
			ResultSet rs=null;
			try {
				ps = con.prepareStatement(MOSTRARPORID);
				ps.setInt(1,id);
				rs=ps.executeQuery();
				if(rs.next()) {
					resultado=new Sede(rs.getInt("id"),
							rs.getString("nombre"),
							rs.getFloat("presupuesto"),
							rs.getInt("ncomplejos"));
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
	@Override
	public List<Complejo> getComplejos(){
		if(!persisted) {
			//Ir a la base de datos y traer la lista de complejos
			ComplejoDAOImpMariaDB c = new ComplejoDAOImpMariaDB();
			this.setComplejos(c.mostrarPorSede(this.id));
			persisted =true;
		}
		return super.getComplejos();
	}

	
	public List<Sede> mostrarPorNombre(String nombre) {
		// TODO Auto-generated method stub
		return null;
	}

	public void addComplejo(Complejo x) {
		if(x!=null) {
			x.setSede(this);
			ComplejoDAOImpMariaDB dao = new ComplejoDAOImpMariaDB(x);
			dao.editar();
			if(!this.complejos.contains(dao)) {
				this.complejos.add(dao);			
			}
			ncomplejos ++;
			editar();	//opcional
		}
	}

	public void removeComplejo(Complejo x) {
		// TODO Auto-generated method stub
		if(x!=null) {
			ComplejoDAOImpMariaDB dao = new ComplejoDAOImpMariaDB(x);
			dao.borrar();
			if(this.complejos.contains(dao)) {
				this.complejos.remove(dao);			
				ncomplejos --;
				editar();	//opcional
			}
		}
	}

}
