import { Component, OnInit } from '@angular/core';
import { AddpresComponent } from 'src/app/presupuestos/addpres/addpres.component';
import { ProveedoresService } from 'src/app/servicios/proveedores.service';


@Component({
  selector: 'app-proveedores',
  templateUrl: './proveedores.component.html',
  styles: [
  ]
})
export class ProveedoresComponent implements OnInit {
  
  proveedores: any[] = [];
  proveedor: any;
  
  constructor( private proveedoresService: ProveedoresService) {
     this.proveedores = this.proveedoresService.getProveedores();
  } 
 
  ngOnInit(): void {
  }

  eliminarProveedores(proveedor: AddpresComponent){
    this.proveedoresService.delProveedor(proveedor.key);
    this.proveedor = this.proveedoresService.getProveedores();
  }

}
