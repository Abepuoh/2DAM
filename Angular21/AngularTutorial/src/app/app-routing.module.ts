import { Component, NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { InicioComponent } from './pages/inicio/inicio.component';
import { Page404Component } from './pages/page404/page404.component';
import { Paso2Component } from './pages/paso2/paso2.component';
import { Paso3Component } from './pages/paso3/paso3.component';
import { Paso4Component } from './pages/paso4/paso4.component';

const routes: Routes = [
  {path: '', component:InicioComponent},
  {path: 'paso2', component:Paso2Component},
  {path: 'paso3', component:Paso3Component},
  {path: 'paso4', component:Paso4Component},
  {path: '**', component:Page404Component}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
