import java.util.Iterator;
import java.util.List;

import DAO.MariaDB.ComplejoDAOImpMariaDB;
import DAO.MariaDB.SedeDAOImpMariaDB;
import DAO.model.Complejo;
import DAO.model.Sede;

public class Ejecutable2 {
	public static void main(String[] args) {
		/*SedeDAOImpMariaDB s=new SedeDAOImpMariaDB("nueva", 100f, 5);
		s.setId(3);
		s.guardar(); //s.editar();
		System.out.println(s);*/
		/*SedeDAOImpMariaDB s=new SedeDAOImpMariaDB();
		List<Sede> todas=s.mostrarTodos();
		for(Sede n:todas) {
			System.out.println(n);
		}
		SedeDAOImpMariaDB s=new SedeDAOImpMariaDB();
		Sede x=s.mostrar(3);
		System.out.println(x);
		s=new SedeDAOImpMariaDB(x);
		s.borrar(); */
		
		ComplejoDAOImpMariaDB c = new ComplejoDAOImpMariaDB();
		List<Complejo> todo = c.mostrarTodos();
		for(Complejo aux : todo) {
			System.out.println(aux);
		}
	}
}
