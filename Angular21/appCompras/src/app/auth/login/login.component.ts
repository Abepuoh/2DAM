import { AuthService } from 'src/app/servicios/auth.service';
import { Router, ActivatedRoute } from '@angular/router';
import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css'],
})
export class LoginComponent implements OnInit {
  loginForm: FormGroup | any;
  userdata: any;
  mensaje = false;

  constructor(
    private formBuilder: FormBuilder,
    private authS: AuthService,
    private router: Router
  ) {}

  ngOnInit() {
    this.loginForm = this.formBuilder.group({
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
  }
  onSubmit() {
    this.userdata = this.saveUserdata();
    this.authS.inicioSesion(this.userdata);
    setTimeout(() => {
      if (this.authS.isLogged === false) {
        this.mensaje = true;
      }
    }, 2000);
  }

  saveUserdata() {
    const saveUserdata = {
      email: this.loginForm.get('email').value,
      password: this.loginForm.get('password').value,
    };
    return saveUserdata;
  }

  loginGoogle() {
    this.authS
      .googleLogin()
      .then((data: any) => {
        console.log(data);
        this.authS.setUser(data);
        if (this.authS.isLogged) {
          this.router.navigate(['/proveedores']);
        }
      })
      .catch((err: any) => {
        console.log(err);
      });
  }
}
