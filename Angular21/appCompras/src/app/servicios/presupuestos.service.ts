import { Injectable } from '@angular/core';
import { AngularFireAuth } from '@angular/fire/compat/auth';
import {AngularFireDatabase} from '@angular/fire/compat/database';
import { Presupuesto } from '../shared/Presupuesto';


@Injectable({
  providedIn: 'root',
})
export class PresupuestosService {

  constructor(private authf: AngularFireAuth,private db:AngularFireDatabase) {
    
  }
 
  public addPresupuesto(presupuesto:any):void{
    this.db.database.ref().child("presupuesto").push(presupuesto);
  }
 
  async getPresupuesto(key: string): Promise<firebase.default.database.DataSnapshot> {
    return this.db.database.ref().child("presupuesto").child(key).get();
  }

  putPresupuesto(presupuesto:any,key:string){
    this.db.object("presupuesto/"+key).update(presupuesto);
  }

  getPresupuestos(){
    let result: Presupuesto[]= [];
    this.db.database.ref().child("presupuesto").get().then((data)=>{
      const presupuestos =data.val();
      for(let presupuesto in presupuestos){
        result.push({key:presupuesto,...presupuestos[presupuesto]});
      }
    })  
    return result;
  }
  /**
   * metodo que borrar un presupuesto de la base de datos mediante un id
   * @param id del presupuesto
   */
  delPresupuesto(id:string){
    const confirmation = confirm("¿Seguro que quieres borrarlo?");
    if(confirmation){
      this.db.database.ref().child("presupuesto").child(id).remove();
    }
  }

 }
