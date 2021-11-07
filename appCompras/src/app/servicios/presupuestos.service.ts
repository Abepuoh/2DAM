import { Injectable } from '@angular/core';
import { AngularFireAuth } from '@angular/fire/compat/auth';
import {AngularFireDatabase} from '@angular/fire/compat/database';


@Injectable({
  providedIn: 'root',
})
export class PresupuestosService {

  constructor(private authf: AngularFireAuth,private db:AngularFireDatabase) {
    
  }

  public postPresupuesto(presu:any):void{
    this.db.database.ref().child("presupuesto").push(presu);
  }

  getPresupuestos(){
    let result: PresupuestosService[]= [];
    this.db.database.ref().child("presupuesto").get().then((data)=>{
      const presupuestos =data.val();
      for(let presupuesto in presupuestos){
        result.push({key:presupuesto,...presupuestos[presupuesto]});
      }
    })  
    return result;
  }
  updatePresupuesto( presupuesto: any) { 
   
  }

 }
