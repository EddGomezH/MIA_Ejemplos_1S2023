import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent implements OnInit {

  idparticion = "";
  user = "";
  pwd = "";

  constructor() { }

  ngOnInit(): void {
  }

  ingresar() {
    console.log("ID Particion: ", this.idparticion);
    console.log("User: ", this.user);
    console.log("Password: ", this.pwd);
  }
}
