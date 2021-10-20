package DAO.MariaDB;

import java.sql.Connection;

public class ComplejoDAOImpMariaDB {

	private static final String INSERT = "INSERT INTO complejo " + "(nombre,localizacion,jefe,area_total,tipo,id_sede) "
			+ "VALUES (?,?,?,?,?,?)";
	private static final String MOSTRARTODOS = "SELECT id,nombre,presupuesto,ncomplejos FROM sede";
	private static final String MOSTRARPORID = "SELECT id,nombre, presupuesto,ncomplejos FROM sede WHERE id=?";
	private static final String EDITAR = "UPDATE sede SET nombre=?, presupuesto=?,ncomplejos=? WHERE id=?";
	private static final String BORRAR = "DELETE FROM complejo WHERE id=?";
	private static final String MOSTRARPORNOMBRE = "SELECT id,nombre,presupuesto,ncomplejos FROM complejo "
			+ "WHERE nombre LIKE ?";

	private Connection con = null;

	public ComplejoDAOImpMariaDB() {
		super();
	}
}
