import { Injectable } from '@angular/core';
import { ControlValueAccessor } from '@angular/forms';
import { contacto } from 'src/model/contacto';

@Injectable({
  providedIn: 'root',
})
export class ListadoService {
  private listaContactos: Array<contacto> = new Array();

  constructor() {}

  nuevoContacto(c:contacto){
    this.listaContactos.push(c);
  }
  leeContacto():contacto[]{        
    return this.listaContactos;
  }
  /*
  *  Siempre que queramos que un servicio sea inyectado edebemos
   de añadirlo a la lsta de providers del compomente padre -> ~singleton */
}
