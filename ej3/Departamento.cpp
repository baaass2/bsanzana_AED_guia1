#include <iostream>
#include <string>
#include "Departamento.h"
using namespace std;


Departamento::Departamento(){
}

Departamento::Departamento(int clave, int extension, string ubicacion, int precio, bool disponibilidad){
    this->clave = clave;
    this->extension = extension;
    this->ubicacion = ubicacion;
    this->precio = precio;
    this->disponibilidad = disponibilidad;
}

int Departamento::get_clave(){
    return this->clave;
}

int Departamento::get_extension(){
    return this->extension;
}

string Departamento::get_ubicacion(){
    return this->ubicacion;
}

int Departamento::get_precio(){
    return this->precio;
}

void Departamento::set_precio(int precio){
    this->precio = precio;
}

bool Departamento::get_disponibilidad(){
    return this->disponibilidad;
}
void Departamento::set_disponibilidad(bool disponibilidad){
    this->disponibilidad = disponibilidad;
}