import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { Routes, RouterModule } from '@angular/router';
import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { ProveedoresComponent } from './proveedores/proveedores/proveedores.component';
import { ProveedoresService } from './servicios/proveedores.service';
import { InicioComponent } from './pages/inicio/inicio.component';
import { HeaderComponent } from './commons/header/header.component';
import { AddproveeComponent } from './proveedores/addprovee/addprovee.component';
import { FormsModule, ReactiveFormsModule } from '@angular/forms';
import { AddpresComponent } from './presupuestos/addpres/addpres.component';
import {AngularFireAuth, AngularFireAuthModule} from '@angular/fire/compat/auth';
import {AngularFirestore, AngularFirestoreModule} from '@angular/fire/compat/firestore';
import { environment } from 'src/environments/environment';
import { AngularFireModule } from '@angular/fire/compat';
import { PresupuestosComponent } from './presupuestos/presupuestos/presupuestos.component';
import { EditpresComponent } from './presupuestos/editpres/editpres.component';
import { RegistroComponent } from './auth/registro/registro.component';
import { LoginComponent } from './auth/login/login.component';
import { AuthService } from './servicios/auth.service';
import { EditproveedoresComponent } from './proveedores/editproveedores/editproveedores.component';

const routes: Routes = [
  { path: '', component: LoginComponent},
  { path: 'proveedores', component: ProveedoresComponent },
  { path: 'login', component: LoginComponent },
  { path: 'addprovee', component:AddproveeComponent},
  { path: 'addpres', component: AddpresComponent},
  { path: 'registro', component: RegistroComponent },
  { path: 'presupuestos', component: PresupuestosComponent },
  { path: 'editpres/:key', component: EditpresComponent },
  { path: 'editproveedores/:key', component: EditproveedoresComponent },
  { path: '**', component: InicioComponent },
];

@NgModule({
  declarations: [
    AppComponent,
    ProveedoresComponent,
    InicioComponent,
    HeaderComponent,
    AddproveeComponent,
    AddpresComponent,
    PresupuestosComponent,
    EditpresComponent,
    RegistroComponent,
    LoginComponent,
    EditproveedoresComponent,
    
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    ReactiveFormsModule,
    RouterModule.forRoot(routes),
    FormsModule,
    AngularFireModule.initializeApp(environment.firebaseConfig),
    AngularFireAuthModule,
    AngularFirestoreModule,
  ],
  providers: [ProveedoresService,AngularFireAuth,AngularFirestore,AuthService,LoginComponent],
  bootstrap: [AppComponent],
})
export class AppModule {}
