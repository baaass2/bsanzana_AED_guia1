#include <iostream>
#include <string>
#include "Profesor.h"
using namespace std;


Profesor::Profesor(){
}

Profesor::Profesor(string nombre, string sexo, int edad){
    this->nombre = nombre;
    this->sexo = sexo;
    this->edad = edad;       
}

string Profesor::get_nombre(){
    return this->nombre;
}


string Profesor::get_sexo(){
    return this->sexo;
}

int Profesor::get_edad(){
    return this->edad;
}