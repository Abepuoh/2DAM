package DAO;

import java.util.List;

public interface IDAO<T> {
	void guardar();
	void editar();
	void borrar();
	List<T> mostrarTodos();
	T mostrar(int id);
}
