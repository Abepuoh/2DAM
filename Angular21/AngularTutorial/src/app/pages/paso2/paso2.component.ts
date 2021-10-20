import { Component, OnInit } from '@angular/core';
import { ListadoService } from 'src/app/services/listado.service';
import { FormBuilder, Validators } from '@angular/forms';
import { contacto } from 'src/model/contacto';

@Component({
  selector: 'app-paso2',
  templateUrl: './paso2.component.html',
  styleUrls: ['./paso2.component.css'],
})
export class Paso2Component implements OnInit {
  public errorMensaje: string = '';
  public alertClass: string = 'aler alert-success';

  validator = this.fb.group({
    nombre: ['', [Validators.required, Validators.minLength(4)]],
    telefono: ['', [Validators.pattern('[0-9]{9}'), Validators.required]],
  });
  constructor(private ls: ListadoService, private fb: FormBuilder) {}
  ngOnInit(): void {}

  onSubmit(){
    if(this.validator.status=="VALID"){
      console.log(this.validator.status)
      let c:contacto=new contacto(this.validator.value.nombre,
        this.validator.value.telefono);
        this.ls.nuevoContacto(c);
        this.mostrarMensaje("Contacto insertado satisfactoriamente",false);
       /* this.validator.setValue({
          nombre:"",telefono:""
        });*/
        this.validator.reset();
      console.log(this.ls.leeContacto());
    }else{
      console.log(this.validator.get("nombre")?.errors);
      console.log(this.validator.get("telefono")?.errors);
      let error="";
      if(this.validator.get("nombre")?.errors!=null){
        error+="- Debe introducir un nombre ";
      }
      if(this.validator.get("telefono")?.errors!=null){
        if(this.validator.get("telefono")?.errors?.required)
          error+="- Debe introducir un teléfono ";
        if(this.validator.get("telefono")?.errors?.pattern)
          error+="- Debe introducir un teléfono válido: 666666666 "; 
      }
      this.mostrarMensaje(error,true);
    }
  }
  mostrarMensaje(mensaje: string, isError: boolean): void {
    this.errorMensaje = mensaje;
    if (isError) {
      this.alertClass = 'alert alert-danger';
    } else {
      this.alertClass = 'alert alert-success';
    }
    setTimeout(() => {
      this.errorMensaje = "";
    }, 2000);
  }
}
