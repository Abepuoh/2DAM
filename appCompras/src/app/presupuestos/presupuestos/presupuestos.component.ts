import { Component, OnInit } from '@angular/core';
import { PresupuestosService } from '../../servicios/presupuestos.service';

@Component({
  selector: 'app-presupuestos',
  templateUrl: './presupuestos.component.html',
  styleUrls: ['./presupuestos.component.css'],
})
export class PresupuestosComponent implements OnInit {

  presupuestos: any[] = [];
  constructor(private presupuestosService: PresupuestosService) {
    
  }

  ngOnInit(): void {}
}
