#include <iostream>
#include <string>
using namespace std;

#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

class Departamento{
    private:
        int clave = 0;
        int extension = 0;
        string ubicacion = "\0";
		int precio = 0;
        bool disponibilidad = true;
    public:
        Departamento();
        Departamento(int clave, int extension, string ubicacion, int precio, bool disponibilidad);
      
        int get_clave();
        int get_extension();
        string get_ubicacion();
        int get_precio();
        bool get_disponibilidad();
        void set_precio(int precio);
        void set_disponibilidad(bool disponibilidad);
};
#endif