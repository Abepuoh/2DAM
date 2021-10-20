package DAO;

import java.util.List;

import DAO.model.Complejo;
import DAO.model.Sede;

public interface complejoDAO extends IDAO<Complejo> {
	
	List<Sede> mostrarPorNombre(String nombre);
}
