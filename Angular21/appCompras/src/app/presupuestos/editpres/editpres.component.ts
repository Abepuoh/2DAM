import { ChangeDetectorRef, Component, OnInit } from '@angular/core';
import {
  FormControl,
  FormGroup,
  FormBuilder,
  Validators,
} from '@angular/forms';
import { PresupuestosService } from '../../servicios/presupuestos.service';
import { Router, ActivatedRoute } from '@angular/router';
import { Presupuesto } from 'src/app/shared/Presupuesto';

@Component({
  selector: 'app-editpres',
  templateUrl: './editpres.component.html',
  styleUrls: ['./editpres.component.css'],
})
export class EditpresComponent implements OnInit {
  presupuestoForm!: FormGroup;
  presupuesto?: Presupuesto | any;
  base: any= '';
  tipo: any ='';
  iva: any = 0;
  total: any = 0;
  key: string = '';

  constructor(private pf: FormBuilder, private presupuestoService: PresupuestosService,
     private router: Router, private activatedRouter: ActivatedRoute, private cdref: ChangeDetectorRef) {
    this.activatedRouter.params.subscribe(parametros => {
      this.key = parametros['key'];      
      (async ()=>{
        this.presupuesto=await this.presupuestoService.getPresupuesto(this.key);        
      })();
      
    });
  }
  async ngOnInit() {

    this.presupuestoForm = this.pf.group({
      proveedor: ['', Validators.required],
      fecha: ['', Validators.required],
      concepto: ['', [Validators.required, Validators.minLength(10)]],
      base: ['', Validators.required],
      tipo: ['', Validators.required],
      iva: [{value: '', disabled: true}, Validators.required],
      total: [{value: '', disabled: true}, Validators.required],
    });
    let tmp =await this.presupuestoService.getPresupuesto(this.key);
    this.presupuesto =tmp.val();
    this.setPresupuesto();
     //LOADING
     //this.presupuesto = await this.presupuestoService.getPresupuesto(this.key);    //OCULTAR LOADING
  }

  onChanges(): void {
    this.presupuestoForm.valueChanges.subscribe(valor => { 
      this.base = valor.base; 
      this.tipo = valor.tipo;
      this.presupuestoForm.value.iva = this.base * this.tipo; 
      this.presupuestoForm.value.total = this.base + (this.base * this.tipo);
      
      });
  }

  onSubmit() {
    this.presupuesto = this.savePresupuesto();
    this.presupuestoService.putPresupuesto(this.presupuesto, this.key);
    this.router.navigate(['/presupuestos']);
  }
  savePresupuesto() {
    const savePresupuesto = {
      proveedor: this.presupuestoForm.get('proveedor')!.value,
      fecha: this.presupuestoForm.get('fecha')!.value,
      concepto: this.presupuestoForm.get('concepto')!.value,
      base: this.presupuestoForm.get('base')!.value,
      tipo: this.presupuestoForm.get('tipo')!.value,
      iva: this.presupuestoForm.get('iva')!.value,
      total: this.presupuestoForm.get('total')!.value
    };
    return savePresupuesto;
  }
  updatePresupuesto(){
    this.presupuesto = this.savePresupuesto();
    this.presupuestoService.putPresupuesto(this.presupuesto,this.key);
    console.log(this.presupuesto);
    this.router.navigate(['/presupuestos']);
  }
  setPresupuesto(){
    this.presupuestoForm.setValue({
      proveedor: this.presupuesto.proveedor,
      fecha: this.presupuesto.fecha,
      concepto: this.presupuesto.concepto,
      base: this.presupuesto.base,
      tipo: this.presupuesto.tipo,
      iva: this.presupuesto.iva,
      total: this.presupuesto.total
    });
    this.onChanges();
    this.cdref.detectChanges(); 
  }

}
