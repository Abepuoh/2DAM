import { Component, OnInit } from '@angular/core';
import { FormGroup, Validators, FormBuilder } from '@angular/forms';
import { AuthService } from 'src/app/servicios/auth.service';
import { Router, ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-registro',
  templateUrl: './registro.component.html',
  styleUrls: ['./registro.component.css'],
})
export class RegistroComponent implements OnInit {
  registerForm!: FormGroup;
  userdata: any;
  
  erroresForm:any = {
    'email': '',
    'password': ''
  }
  mensajesValidacion:any = {
    'email': {
    'required': 'Email obligatorio',
    'email': 'Introduzca una dirección email correcta'
    },
    'password': {
    'required': 'Contraseña obligatoria',
    'pattern': 'La contraseña debe tener al menos una letra un número ',
    'minlength': 'y más de 6 caracteres'
    } 
  };

  constructor(
    private formBuilder: FormBuilder,
    private autService: AuthService,
    private router: Router,
  ) {}

  ngOnInit() {
    this.registerForm = this.formBuilder.group({
      email: ['', [Validators.required, Validators.email]],
      password: [
        '',
        [
          Validators.required,
          Validators.pattern('^(?=.*[0-9])(?=.*[a-zA-Z])([a-zA-Z0-9]+)$'),
          Validators.minLength(6),
        ],
      ],
    });
    this.registerForm.valueChanges.subscribe(data =>this.onValueChanged(data));
    this.onValueChanged();
  }
  async onSubmit() {
    this.userdata = this.saveUserdata();
    this.autService.registroUsuario(this.userdata);
    this.router.navigate(['/login']);
  }

  saveUserdata() {
    const saveUserdata = {
      email: this.registerForm.get('email')?.value,
      password: this.registerForm.get('password')?.value,
    };
    return saveUserdata;
  }
  onValueChanged(data?: any) {
    if (!this.registerForm) {
      return;
    }
    const form = this.registerForm;
    for (const field in this.erroresForm) {
      this.erroresForm[field] = '';
      const control = form.get(field);
      if (control && control.dirty && !control.valid) {
        const messages = this.mensajesValidacion[field];
        for (const key in control.errors) {
          this.erroresForm[field] += messages[key] + ' ';
        }
      }
    }
  }
}
