import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class EjemploService {

  constructor(private httpClient: HttpClient) { }

  postEntrada(entrada: string) {
    return this.httpClient.post("http://localhost:5000/analizar", { Cmd: entrada });
  }

  getReporte() {
    return this.httpClient.get("http://localhost:5000/reportes");
  }
}
