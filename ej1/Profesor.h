#include <iostream>
using namespace std;

#ifndef PROFESOR_H
#define PROFESOR_H

class Profesor {
    private:
        string nombre = "\0";
        string sexo = "\0";
		int edad = 0;
    public:
        Profesor();
        Profesor (string nombre, string sexo, int edad);
      
        string get_nombre();
        string get_sexo();
        int get_edad();
};
#endif