import { Component, OnInit } from '@angular/core';
import { ProveedoresService } from 'src/app/servicios/proveedores.service';


@Component({
  selector: 'app-proveedores',
  templateUrl: './proveedores.component.html',
  styles: [
  ]
})
export class ProveedoresComponent implements OnInit {
  
  public proveedores: any;
  
  constructor( private proveedoresService: ProveedoresService) { } 
 
  ngOnInit(): void {
    this.proveedores = this.proveedoresService.getProveedores();
  }

}
