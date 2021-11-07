import { Injectable } from '@angular/core';
import { AngularFireAuth } from '@angular/fire/compat/auth';
import { Router } from '@angular/router';
import { GoogleAuthProvider } from 'firebase/auth';
import * as firebase from 'firebase/compat/app';
import { Observable } from 'rxjs';
import { User } from '../shared/User.inteface';

@Injectable({
  providedIn: 'root',
})
export class AuthService {
  public user: any | null;
  public ready?: boolean;
  public $ready!: Observable<boolean>;

  constructor(private authf: AngularFireAuth, private router: Router) {
    //los servicios se invocan desde el constructor
    this.checkSSO();
  }

  public googleLogin(): Promise<firebase.default.auth.UserCredential> {
    return this.authf.signInWithPopup(new GoogleAuthProvider());
  }

  public setUser(u: firebase.default.auth.UserCredential | any | null): void {
    if (u && u.user) {
      this.user = {
        uid: u.user.uid,
        email: u.user.email,
        displayName: u.user.displayName,
        password: u.user.password
      };
    } else {
      this.user = null;
    }
  }

  public get isLogged(): boolean {
    return this.user ? true : false;
  }

  public checkSSO(): void {
    this.$ready = new Observable((observer) => {
      try {
        this.authf.user.subscribe((data) => {
          console.log(data);
          this.ready = true;
          if (data != null) {
            this.setUser({ user: data });
            observer.next(true);
          } else {
            this.setUser(null);
            observer.next(false);
          }
          observer.complete();
        })
      } catch (err) {
        console.log(err);
        this.setUser(null);
        this.ready = true;
        observer.next(false);
        observer.complete();
      }
    }
    )
  }


  public logout(): Promise<void> {
    return new Promise(async (resolve, reject) => {
      if (this.isLogged) {
        try {
          await this.authf.signOut();
          this.setUser(null);
          resolve();
        } catch (error) {
          reject(error);
        }
      }
    })
  }
  
  public registroUsuario(userdata: {
    email: any;
    password: any;
  }): Promise<firebase.default.auth.UserCredential> {
    return this.authf.createUserWithEmailAndPassword(
      userdata.email,
      userdata.password
    );
  }

  async inicioSesion(userdata:any) {
    try {
      const user = await this.authf.signInWithEmailAndPassword(
        userdata.email,
        userdata.password,
        );
        this.setUser(userdata);
        console.log(userdata);
        this.router.navigate(['/inicio']);
      return user;
    } catch (error) {
      console.log(error);
      return error;
    }
  }
}

  

