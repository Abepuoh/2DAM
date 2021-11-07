package DAO.model;

public class Complejo {
	protected int id;
	protected String nombre;
	protected String localizacion;
	protected String jefe;
	protected float area_total;
	protected boolean tipo;
	protected Sede sede;
	//private Sede misede;
	
	public Complejo() {
		this(-1,"","","",0,false,new Sede());
	}
	public Complejo(String nombre, String localizacion, String jefe, float area_total, boolean tipo, Sede sede) {
		this(-1,nombre,localizacion,jefe,area_total,tipo,sede);
	}
	public Complejo(int id, String nombre, String localizacion, String jefe, float area_total, boolean tipo,
			Sede sede) {
		this.id = id;
		this.nombre = nombre;
		this.localizacion = localizacion;
		this.jefe = jefe;
		this.area_total = area_total;
		this.tipo = tipo;
		this.sede = sede;
	}
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getNombre() {
		return nombre;
	}
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	public String getLocalizacion() {
		return localizacion;
	}
	public void setLocalizacion(String localizacion) {
		this.localizacion = localizacion;
	}
	public String getJefe() {
		return jefe;
	}
	public void setJefe(String jefe) {
		this.jefe = jefe;
	}
	public float getArea_total() {
		return area_total;
	}
	public void setArea_total(float area_total) {
		this.area_total = area_total;
	}
	public boolean isTipo() {
		return tipo;
	}
	public void setTipo(boolean tipo) {
		this.tipo = tipo;
	}
	public Sede getSede() {
		return sede;
	}
	public void setSede(Sede id_sede) {
		this.sede = id_sede;
	}
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + id;
		return result;
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Complejo other = (Complejo) obj;
		if (id != other.id)
			return false;
		return true;
	}
	@Override
	public String toString() {
		return "Complejo [id=" + id + ", nombre=" + nombre + ", localizacion=" + localizacion + ", jefe=" + jefe
				+ ", area_total=" + area_total + ", tipo=" + tipo + ", id_sede=" + sede.getNombre() + "]";
	}
}
