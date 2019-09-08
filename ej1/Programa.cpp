#include <iostream>
#include <string>
#include "Profesor.h"
using namespace std;

int calcularPromedio(Profesor profesores[], int N){
    
    int edadPromedio=0;
    int aux=0;
    
    for(int i=0; i<N; i++){
        aux = profesores[i].get_edad();
        edadPromedio = aux + edadPromedio;
    }
    return (edadPromedio/2);
}

int* ordenarArray_edades(Profesor profesores[], int N){
	int aux=0;
    int *edades;
    
    edades = new int[N];
    for (int i=0; i<N; i++){
        edades[i] = profesores[i].get_edad();
    }
	
	for (int i=0; i < N; i++){
		for (int j = 0; j< N-1; j++){
			if (edades[j] > edades[j+1] ){
			    aux = edades[j]; 
			    edades[j] = edades[j+1]; 
			    edades[j+1] = aux;
			}
		}
	}
    return edades;
}

void imprimirProfesor_joven_viejo(int* edades, Profesor profesores[], int N, int edadPromedio){

    int edadJoven = edades[0];
    int edadViejo = edades[N-1];
    

    for(int i=0; i<N; i++){
        
        if(profesores[i].get_edad() == edadPromedio){
            cout << "Profesor con edad igual al promedio: "<< profesores[i].get_nombre() << endl;            
        }
        else if(profesores[i].get_edad() == edadJoven){
            cout << "Profesor más Joven: "<< profesores[i].get_nombre() << endl;            
        }
        else if(profesores[i].get_edad() == edadViejo){
            cout << "Profesor más Viejo: "<< profesores[i].get_nombre() << endl;            
        }
    }
}

void calculoRelacion_edadPromedio(int edadPromedio, Profesor profesores[], int N){

    int cantidad_edadMayor_prom=0;
    int cantidad_edadMenor_prom=0;
    
    
    for(int i=0; i<N; i++){
        if(profesores[i].get_edad() > edadPromedio){
            cantidad_edadMayor_prom = cantidad_edadMayor_prom + 1;               
        }
        else if(profesores[i].get_edad() < edadPromedio){
            cantidad_edadMenor_prom = cantidad_edadMenor_prom + 1;             
        }
    }
    
    cout << "Cantidad de Profesores con edad mayor al promedio: " << cantidad_edadMayor_prom << endl;
    cout << "Cantidad de Profesores con edad menor al promedio: " << cantidad_edadMenor_prom << endl;


}


int main()  {

    int N = 0;
    int edad = 0;
    int edadPromedio=0;
    int *edades;
    string nombre = "";
    string sexo = "";

    cout << "¿Cuantos profesores ingresara?: "; cin >> N;

    Profesor *profesores = new Profesor[N];
    
    for(int i=0; i<N; i++){
        cout << "---------Profesor " << i+1 << "------------" << endl;
        cout << "Nombre de profesor: "; cin >> nombre;
        cout << "Sexo de profesor: "; cin >> sexo;
        cout << "Edad de profesor: "; cin >> edad;
        cout << "---------------------" << endl;
        Profesor p = Profesor(nombre, sexo, edad);
        profesores[i] = p;
    }

    edadPromedio = calcularPromedio(profesores, N);

    cout << "---------------DATOS------------------" << endl;
    cout <<"Edad promedio de grupo de Profesores: "<< edadPromedio << endl;

    edades = ordenarArray_edades(profesores, N);

    imprimirProfesor_joven_viejo(edades, profesores, N, edadPromedio);

    calculoRelacion_edadPromedio(edadPromedio, profesores, N);
    cout << "--------------------------------------" << endl;
}
