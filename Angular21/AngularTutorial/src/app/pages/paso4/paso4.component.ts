
import { Component, OnInit } from '@angular/core';
import { JSONService } from 'src/app/services/json.service';
import { contacto } from 'src/model/contacto';

@Component({
  selector: 'app-paso4',
  templateUrl: './paso4.component.html',
  styleUrls: ['./paso4.component.css']
})
export class Paso4Component implements OnInit {
  public contactos: contacto[] | any =[];
  public contactoElegido: contacto | any = null;
  public cargando: boolean = false;

  constructor(private json:JSONService) { }

  ngOnInit(): void {
  }
  seleccionarContacto(c:contacto):void {
    this.contactoElegido = c;
  }
  deseleccionar():void{
    this.contactoElegido = null;
  }
  cargaDatos():void{
    this.cargando =true;
    try {
      this.json.loadJSON().subscribe(data=>{
      this.contactos = data["contactos"];
      this.cargando =false;
      })
    } catch (err){
      this.cargando =false;
      console.log(err);;
    }
  }
}
