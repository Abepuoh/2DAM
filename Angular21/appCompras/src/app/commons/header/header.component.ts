import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { AuthService } from 'src/app/servicios/auth.service';

@Component({
  selector: 'app-header',
  templateUrl: './header.component.html',
  styleUrls: ['./header.component.css']
})
export class HeaderComponent implements OnInit {

  constructor(public authS: AuthService, public router: Router) { }

  ngOnInit(): void {
  }
  
  async isAuth() {
    return await this.authS.isLogged;
  }

  onLogout() {
    this.authS.logout();
    this.router.navigate(['/login'])
    }
}
