#include "nodo.h"

Nodo::Nodo(const std::string& nombre, const std::string& token, const std::string& tipo)
{
    this->Nombre = nombre;
    this->Token = token;
    this->Tipo = tipo;
}

void Nodo::addHijo(Nodo *hoja){
    this->Hojas.push_back(hoja);
}
