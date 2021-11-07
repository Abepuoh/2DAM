import { ChangeDetectorRef, Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { ActivatedRoute, Router } from '@angular/router';
import { ProveedoresService } from 'src/app/servicios/proveedores.service';

@Component({
  selector: 'app-editproveedores',
  templateUrl: './editproveedores.component.html',
  styleUrls: ['./editproveedores.component.css']
})
export class EditproveedoresComponent implements OnInit {

  proveedor: any;
  proveedorForm!: FormGroup;
  
    nombre: any;
    cif: any;
    direccion: any;
    codigoPostal: any;
    localidad: any;
    provincia: any;
    telefono: any;
    email: any;
    contacto: any;
    key: string = '';

  provincias: string[] = [
    'Álava','Albacete','Alicante','Almería','Asturias','Ávila','Badajoz','Barcelona',
      'Burgos', 'Cáceres', 'Cádiz','Cantabria','Castellón','Ciudad Real','Córdoba',
      'La Coruña','Cuenca','Gerona','Granada','Guadalajara',
      'Guipúzcoa','Huelva','Huesca','IslasBaleares','Jaén','León','Lérida','Lugo',
      'Madrid', 'Málaga','Murcia','Navarra','Orense','Palencia','Las Palmas',
      'Pontevedra','La Rioja','Salamanca','Segovia','Sevilla','Soria','Tarragona',
      'Santa Cruz de Tenerife', 'Teruel', 'Toledo', 'Valencia', 'Valladolid', 'Vizcaya',
      'Zamora','Zaragoza' 
    ]

    constructor(private pf: FormBuilder, private proveedorService: ProveedoresService,
      private router: Router, private activatedRouter: ActivatedRoute, private cdref: ChangeDetectorRef) {
     this.activatedRouter.params.subscribe(parametros => {
       this.key = parametros['key'];      
       (async ()=>{
         this.proveedor=await this.proveedorService.getProovedor(this.key);        
       })();
       
     });
   }
   async ngOnInit() {
    this.proveedorForm = this.pf.group(
      {nombre: ['',Validators.required ],
      cif: ['', Validators.required ],
      direccion: ['', Validators.required ],
      cp: ['', Validators.required ],
      localidad:['',Validators.required],
      provincia:this.provincia,
      telefono:['', [ Validators.required, Validators.minLength(9)]],
      email:['',Validators.required],
      contacto:['',Validators.required]
    });
    let tmp =await this.proveedorService.getProovedor(this.key);
    this.proveedor =tmp.val();
    this.setProveedor();
     //LOADING
     //this.presupuesto = await this.presupuestoService.getPresupuesto(this.key);    //OCULTAR LOADING
  }

  setProveedor(){
    this.proveedorForm.setValue({
      nombre: this.proveedor.nombre,
      cif: this.proveedor.cif,
      direccion: this.proveedor.direccion,
      cp: this.proveedor.cp,
      localidad: this.proveedor.localidad,
      provincia: this.proveedor.provincia,
      telefono: this.proveedor.telefono,
      email: this.proveedor.email,
      contacto: this.proveedor.contacto,
    });
    this.cdref.detectChanges(); 
  }

  onSubmit() {
    this.proveedor = this.saveProveedor();
    this.proveedorService.putProveedor(this.proveedor, this.key);
    this.router.navigate(['/proveedores']);
  }
  saveProveedor() {
    const saveProveedor = {
      nombre: this.proveedorForm.get('nombre')?.value,
      cif: this.proveedorForm.get('cif')?.value,
      direccion: this.proveedorForm.get('direccion')?.value,
      cp: this.proveedorForm.get('cp')?.value,
      localidad: this.proveedorForm.get('localidad')?.value,
      provincia: this.proveedorForm.get('provincia')?.value,
      telefono: this.proveedorForm.get('telefono')?.value,
      email: this.proveedorForm.get('email')?.value,
      contacto: this.proveedorForm.get('contacto')?.value,
    };
    return saveProveedor;
  }
  updateProveedor(){
    this.proveedor = this.saveProveedor();
    this.proveedorService.putProveedor(this.proveedor,this.key);
    console.log(this.proveedor);
    this.router.navigate(['/proveedores']);
  }


}
