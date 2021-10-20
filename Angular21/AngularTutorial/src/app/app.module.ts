import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { InicioComponent } from './pages/inicio/inicio.component';
import { Paso2Component } from './pages/paso2/paso2.component';
import { Page404Component } from './pages/page404/page404.component';
import { HeaderComponent } from './commons/header/header.component';
import { ListadoService } from './services/listado.service';
import { FormsModule, ReactiveFormsModule } from '@angular/forms';
import { Paso3Component } from './pages/paso3/paso3.component';
import { Paso4Component } from './pages/paso4/paso4.component';
import { JSONService } from './services/json.service';
import { HttpClientModule } from '@angular/common/http';

@NgModule({
  declarations: [
    AppComponent,
    InicioComponent,
    Paso2Component,
    Page404Component,
    HeaderComponent,
    Paso3Component,
    Paso4Component
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    FormsModule,
    ReactiveFormsModule,
    HttpClientModule
  ],
  providers: [ListadoService,JSONService],
  bootstrap: [AppComponent]
})
export class AppModule { }
