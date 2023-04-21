import { Component, OnInit } from '@angular/core';
import { EjemploService } from 'src/app/services/ejemplo.service';

@Component({
  selector: 'app-inicio',
  templateUrl: './inicio.component.html',
  styleUrls: ['./inicio.component.css']
})
export class InicioComponent implements OnInit {

  entrada = "";
  salida = "";

  constructor(private service: EjemploService) { }

  ngOnInit(): void {
  }

  public async onFileSelected(event: any) {
    const file: File = event.target.files[0];
    this.entrada = await file.text();
  }

  ejecutar() {
    this.salida = "--- Resultados ---\n";
    let split_entrada = this.entrada.split("\n");
    for (let i = 0; i < split_entrada.length; i++) {
      const cmd = split_entrada[i];
      if (cmd != "") {
        this.service.postEntrada(cmd).subscribe(async (res: any) => {
          this.salida += await res.result + "\n";
        });
      }
    }
  }
}
