#include <iostream>
#include <string>
#include "Paciente.h"
using namespace std;


Paciente::Paciente(){
}

Paciente::Paciente(string nombre, string sexo, string telefono, int edad, bool seguro, string* domicilio){
    this->nombre = nombre;
    this->sexo = sexo;
    this->edad = edad;
    this->telefono = telefono;
    this->seguro = seguro;
    this->domicilio = domicilio;       
}

string Paciente::get_nombre(){
    return this->nombre;
}

string Paciente::get_sexo(){
    return this->sexo;
}

string* Paciente::get_domicilio(){
    return this->domicilio;
}

string Paciente::get_telefono(){
    return this->telefono;
}

bool Paciente::get_seguro(){
    return this->seguro;
}

int Paciente::get_edad(){
    return this->edad;
}