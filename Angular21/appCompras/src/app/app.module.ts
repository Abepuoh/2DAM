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

const routes: Routes = [
  { path: '', component: InicioComponent },
  { path: 'proveedores', component: ProveedoresComponent },
  { path: 'addprovee', component:AddproveeComponent},
  { path: 'addpres', component: AddpresComponent},
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
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    ReactiveFormsModule,
    RouterModule.forRoot(routes),
    FormsModule
  ],
  providers: [ProveedoresService],
  bootstrap: [AppComponent],
})
export class AppModule {}
