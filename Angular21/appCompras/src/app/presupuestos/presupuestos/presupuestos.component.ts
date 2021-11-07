import { Component, OnInit } from '@angular/core';
import { Observable } from 'rxjs';
import { PresupuestosService } from '../../servicios/presupuestos.service';
import { AddpresComponent } from '../addpres/addpres.component';


@Component({
  selector: 'app-presupuestos',
  templateUrl: './presupuestos.component.html',
  styleUrls: ['./presupuestos.component.css'],
})
export class PresupuestosComponent implements OnInit {

  presupuestos: any[] = [];
  presupuesto: any;

  constructor(private presupuestosService: PresupuestosService) {
    this.presupuestos =this.presupuestosService.getPresupuestos();

  }
  ngOnInit(): void {}
  


  eliminarPresupuesto(presupuesto: AddpresComponent){
    this.presupuestosService.delPresupuesto(presupuesto.key);
    this.presupuestos = this.presupuestosService.getPresupuestos();
  }

}
