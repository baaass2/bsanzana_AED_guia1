#include <iostream>
#include <string>
#include "Departamento.h"
using namespace std;

void buscarDepto_precio(Departamento departamento[], int N, int precio_deseado){
    
    int noMatch = 0;

    cout << "--------------LISTA DE DEPARTAMENTOS------------------" << endl;
    for(int i=0; i<N; i++){
        if(departamento[i].get_precio() <= precio_deseado and departamento[i].get_disponibilidad() == true){
            cout << "Clave: " << departamento[i].get_clave() << endl;
            cout << "Extension: " << departamento[i].get_extension() << endl;
            cout << "Ubicacion: " << departamento[i].get_ubicacion() << endl;
            cout << "Precio: " << departamento[i].get_precio() << endl;
            cout << "--------------------------------------------------" << endl;
            noMatch = noMatch + 1;
        }
    }
    if(noMatch == 0){
        cout << "No se ha encontrado departamento con las especificaciones." << endl;
    }
}
void buscarDepto_ext(Departamento departamento[], int N, int ext_deseado){
        
    int noMatch = 0;
    
    cout << "--------------LISTA DE DEPARTAMENTOS------------------" << endl;
    for(int i=0; i<N; i++){
        if(departamento[i].get_extension() >= ext_deseado and departamento[i].get_disponibilidad() == true and departamento[i].get_ubicacion() == "excelente"){
            cout << "Clave: " << departamento[i].get_clave() << endl;
            cout << "Extension: " << departamento[i].get_extension() << endl;
            cout << "Precio: " << departamento[i].get_precio() << endl;
            cout << "--------------------------------------------------" << endl;
            noMatch = noMatch + 1;
        }
    }
    if(noMatch == 0){
        cout << "No se ha encontrado departamento con las especificaciones." << endl;
    }
}

void listarMontos(Departamento departamento[], int N){

    int monto_total= 0;
    
    for(int i=0; i<N; i++){
        if(departamento[i].get_disponibilidad() == false){
            monto_total = monto_total + departamento[i].get_precio();
        }
    }
    cout << "El monto total de los depto arrendados es: "<< monto_total << endl;

}

void buscarDepto_3variables(Departamento departamento[], int N, int precio_deseado, int ext_deseado, string ub_deseado){
    
    int clave_deseado = 0;
    int noMatch = 0;
    
    cout << "--------------LISTA DE DEPARTAMENTOS------------------" << endl;
    for(int i=0; i<N; i++){
        if(departamento[i].get_extension() >= ext_deseado and departamento[i].get_disponibilidad() == true and departamento[i].get_ubicacion() == ub_deseado and departamento[i].get_precio() <= precio_deseado){
            cout << "Clave: " << departamento[i].get_clave() << endl;
            cout << "Extension: " << departamento[i].get_extension() << endl;
            cout << "Precio: " << departamento[i].get_precio() << endl;
            cout << "--------------------------------------------------" << endl;
            noMatch = noMatch + 1;
        }
    }
    if(noMatch == 0){
        cout << "No se ha encontrado departamento con las especificaciones." << endl;
    }
    else if(noMatch >= 1){
        cout << "Ingrese Clave del departamento que desea: "; cin >> clave_deseado;
        for(int i=0; i<N; i++){
            if(departamento[i].get_clave() == clave_deseado){
                departamento[i].set_disponibilidad(false);
                cout << "Se ha vendido el departamento." << endl;    
            }
        }    
    }
}

void aumentarArriendo(Departamento departamento[], int N, int porcentaje_aumento){
    
    int valorAumento = 0;
    for(int i=0; i<N; i++){
        if(departamento[i].get_disponibilidad() == true){
            valorAumento = (departamento[i].get_precio() * porcentaje_aumento)/100;
            valorAumento = valorAumento + departamento[i].get_precio();
            departamento[i].set_precio(valorAumento);
            cout << "Se ha aumentado el valor al departamento: "<< departamento[i].get_clave() << endl;    
        }
    }
}



int main()  {

    int N = 0;
    int clave = 0;
    int extension = 0;
    int precio = 0;
    string ubicacion = "";
    bool disponibilidad = true;

    int opcion = 1;

    cout << "¿Cuantos departamentos ingresará?: "; cin >> N;
    
    Departamento *departamentos = new Departamento[N];
    
    for(int i=0; i<N; i++){
        cout << "---------Departamento " << i+1 << "------------" << endl;
        cout << "Clave del departamento: "; cin >> clave;
        cout << "Extensión del departamento(solo números): "; cin >> extension;
        cout << "Ubicación del departamento(excelente, buena, regular, mala): "; cin >> ubicacion;
        cout << "Precio del departamento: "; cin >> precio;
        cout << "El departamento se encuentra disponible" << endl;
 
        cout << "---------------------" << endl;
        Departamento d = Departamento(clave, extension, ubicacion, precio, disponibilidad);
        departamentos[i] = d;
    }
    cout << "--------------------------------------" << endl;

    while(opcion != 0){

        int precio_deseado = 0;
        int ext_deseado = 0;
        int porcentaje_aumento = 0;
        string ub_deseado= "";

        cout << "Para eligir la opcion escriba el numero. Además para cerrar el programa escriba 0." << endl;
        cout << "---------------MENU---------------" << endl;
        cout << "1) Listar departamentos disponibles dependiendo de un valor." << endl;
        cout << "2) Listar departamentos disponibles dependiendo de la extension y ubcación excelente." << endl;
        cout << "3) Listar el monto de los arriendos de todos los deptos arrendados" << endl;
        cout << "4) Buscar un departamento que se adecue a valores." << endl;
        cout << "5) Aumentar arriendo de los departamentos no alquilados." << endl;
        cout << "Ingrese opcion: "; cin >> opcion;
        
        if(opcion == 0){
            cout << "Adiós." << endl;
        }
        else if(opcion == 1){
            cout << "Ingrese precio del depto que busca: "; cin >> precio_deseado;
            buscarDepto_precio(departamentos, N, precio_deseado);   
        }
        else if(opcion == 2){
            cout << "Ingrese extensión del depto que busca: "; cin >> ext_deseado;
            buscarDepto_ext(departamentos, N, ext_deseado);
        }
        else if(opcion == 3){
            listarMontos(departamentos, N);  
        }
        else if(opcion == 4){
            cout << "Ingrese precio del depto que busca: "; cin >> precio_deseado;
            cout << "Ingrese extensión del depto que busca: "; cin >> ext_deseado;
            cout << "Ingrese ubicación del depto que busca: "; cin >> ub_deseado;
            buscarDepto_3variables(departamentos, N, precio_deseado, ext_deseado, ub_deseado);
            
        }
        else if(opcion == 5){
            cout << "Ingrese porcentaje a aumentar respecto del valor actual: "; cin >> porcentaje_aumento;
            aumentarArriendo(departamentos, N, porcentaje_aumento);
        }
        else{
            opcion = 1;
        }        
    }
    return 0;
    
}
