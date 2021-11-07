import { Injectable } from '@angular/core';
import { AngularFireDatabase } from '@angular/fire/compat/database';
import { Proveedores } from '../shared/proveedores';

@Injectable({
  providedIn: 'root',
})
export class ProveedoresService {
  
  constructor(private db:AngularFireDatabase) {}

  public addProveedor(proveedor:any):void{
    this.db.database.ref().child("proveedor").push(proveedor);
  }

  getProveedores(){
    let result: Proveedores[]= [];
    this.db.database.ref().child("proveedor").get().then((data)=>{
      const presupuestos =data.val();
      for(let presupuesto in presupuestos){
        result.push({key:presupuesto,...presupuestos[presupuesto]});
      }
    })  
    return result;
  }
  
  async getProovedor(key: string): Promise<firebase.default.database.DataSnapshot> {
    return this.db.database.ref().child("proveedor").child(key).get();
  }

  putProveedor(presupuesto:any,key:string){
    this.db.object("proveedor/"+key).update(presupuesto);
  }

  delProveedor(id:string){
    const confirmation = confirm("¿Seguro que quieres borrarlo?");
    if(confirmation){
      this.db.database.ref().child("proveedor").child(id).remove();
    }
  }

}

