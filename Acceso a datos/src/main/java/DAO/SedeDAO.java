package DAO;

import java.util.List;

import DAO.model.Sede;

public interface SedeDAO extends IDAO<Sede>{
	//l�gica particular de una sede
	List<Sede> mostrarPorNombre(String nombre);
}
