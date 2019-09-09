#include <iostream>
#include <string>
using namespace std;

#ifndef PACIENTE_H
#define PACIENTE_H

class Paciente {
    private:
        string nombre = "\0";
        string sexo = "\0";
        string* domicilio;
        string telefono = "\0";
		int edad = 0;
        bool seguro = false;
    public:
        Paciente();
        Paciente(string nombre, string sexo, string telefono, int edad, bool seguro, string* domicilio);
      
        string get_nombre();
        string get_sexo();
        string get_telefono();
        string* get_domicilio();
        bool get_seguro();
        int get_edad();
};
#endif