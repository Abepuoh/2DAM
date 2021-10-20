export class contacto {
  private nombre: string;
  private telefono: number;

  constructor(n:string, t:number){
      this.nombre = n;
      this.telefono = t;
  }
/*
  constructo(private nombre:string, private telefono: number){}
*/
  public setNombre(n:string):void{
    this.nombre = n;
  }
  public setTelefono(n:number):void{
    this.telefono = n;
  }
  public getTelefono():number{
    return this.telefono;
  }
  public getNombre():string{
    return this.nombre;
  }
}
