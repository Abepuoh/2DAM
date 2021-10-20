import { Component, OnInit } from '@angular/core';
import { ListadoService } from 'src/app/services/listado.service';
import { contacto } from 'src/model/contacto';

@Component({
  selector: 'app-paso3',
  templateUrl: './paso3.component.html',
  styleUrls: ['./paso3.component.css']
})
export class Paso3Component implements OnInit {
  public contactos: contacto[]= [];
  public contactoElegido: contacto | any = null;

  constructor(private ls: ListadoService) { }

  ngOnInit(): void {
    this.contactos = this.ls.leeContacto();
  }

  seleccionarContacto(c:contacto):void {
    this.contactoElegido = c;
  }
  deseleccionar():void{
    this.contactoElegido = null;
  }
}
