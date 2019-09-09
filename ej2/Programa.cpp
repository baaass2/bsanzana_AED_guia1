#include <iostream>
#include <string>
#include "Paciente.h"
using namespace std;

void enlistar(Paciente *pacientes, int N){
     cout << "--------------LISTA DE PACIENTES------------------" << endl;
     for (int i=0; i<N; i++){
        string* domicilio = pacientes[i].get_domicilio();
        cout << "Nombre: " << pacientes[i].get_nombre() << endl;
        cout << "Edad: " << pacientes[i].get_edad() << endl;
        cout << "Sexo: " << pacientes[i].get_sexo() << endl;
        cout << "Telefono: " << pacientes[i].get_telefono() << endl;
        cout << "Seguro: " << pacientes[i].get_seguro() << endl;
        cout << "Domicilio: " << domicilio[0] << ", " << domicilio[1] << ", " << domicilio[2] << "." << endl;
        cout << "--------------------------------------------------" << endl;
     }
}

void porcentajeEdad(Paciente *pacientes, int N){

    int num_ninos=0;
    int num_jovenes=0;
    int num_adultos=0;

    for(int i=0; i<N; i++){
        if(pacientes[i].get_edad() < 13){
            num_ninos = num_ninos + 1;
        }
        else if(pacientes[i].get_edad() > 13 and pacientes[i].get_edad() < 30 ){
            num_jovenes = num_jovenes + 1;
        }
        
        else if(pacientes[i].get_edad() > 30 ){
            num_adultos = num_adultos + 1;
        }
    }
    cout << " % Niños:  " << (num_ninos*100)/N << endl;
    cout << " % Jovenes:  " << (num_jovenes*100)/N << endl;
    cout << " % Adultos:  " << (num_adultos*100)/N << endl;
}

void porcentaje_hombres_mujeres(Paciente *pacientes, int N){

    int num_hombres = 0;
    int num_mujeres = 0;
    
    for(int i=0; i<N; i++){
        if(pacientes[i].get_sexo() == "masculino" ){
            num_hombres = num_hombres + 1;
        }
        else if(pacientes[i].get_sexo() == "femenino" ){
            num_mujeres = num_mujeres + 1;
        }
    }
    cout << " % Mujeres:  " << (num_mujeres*100)/N << endl;
    cout << " % Hombres:  " << (num_hombres*100)/N << endl;
}

void buscarPaciente(Paciente *pacientes, int N, string nombre_buscar){
    cout << "--------------DATOS DE PACIENTE------------------" << endl;
    for(int i=0; i<N; i++){
        if(pacientes[i].get_nombre() == nombre_buscar ){
            string* domicilio = pacientes[i].get_domicilio();
            cout << "Nombre: " << pacientes[i].get_nombre() << endl;
            cout << "Edad: " << pacientes[i].get_edad() << endl;
            cout << "Sexo: " << pacientes[i].get_sexo() << endl;
            cout << "Telefono: " << pacientes[i].get_telefono() << endl;
            cout << "Seguro: " << pacientes[i].get_seguro() << endl;
            cout << "Domicilio: " << domicilio[0] << ", " << domicilio[1] << ", " << domicilio[2] << "." << endl;
        }
    }
    cout << "-------------------------------------------------" << endl;
}

void porcentajeSeguro(Paciente *pacientes, int N){

    int num_seguro = 0;
    int num_noSeguro = 0;
    
    for(int i=0; i<N; i++){
        if(pacientes[i].get_seguro() == true ){
            num_seguro = num_seguro + 1;
        }
        else if(pacientes[i].get_seguro() == false ){
            num_noSeguro = num_noSeguro + 1;
        }
    }
    cout << " % Pacientes que tienen Seguro:  " << (num_seguro*100)/N << endl;
    cout << " % Pacientes que no tienen Seguro::  " << (num_noSeguro*100)/N << endl;
}

int main()  {

    int N = 0;
    int edad = 0;
    string nombre = "";
    string sexo = "";
    string telefono = "";
    string* domicilio;
    bool seguro = false;
    string aux_seguro = "";
    int opcion = 1;

    cout << "¿Cuantos pacientes ingresara?: "; cin >> N;
    
    domicilio = new string[3];
    Paciente *pacientes = new Paciente[N];
    
    for(int i=0; i<N; i++){
        cout << "---------Paciente " << i+1 << "------------" << endl;
        cout << "Nombre de paciente: "; cin >> nombre;
        cout << "Sexo de paciente(masculino/femenino): "; cin >> sexo;
        cout << "Edad de paciente: "; cin >> edad;
        cout << "Telefono de paciente: "; cin >> telefono;
        cout << "----------Domicilio-----------" << endl;
        cout << "Ingrese de calle: "; cin >> domicilio[0];
        cout << "Ingrese de numero: "; cin >> domicilio[1];
        cout << "Ingrese de cuidad: "; cin >> domicilio[2];
        cout <<"¿Paciente tiene seguro? escribir (V/F) : "; cin>>aux_seguro;
        if( aux_seguro == "V" ){
            seguro = true;
        }
        else if( aux_seguro == "F" ){
            seguro = false;
        }
        cout << "---------------------" << endl;
        Paciente p = Paciente(nombre, sexo, telefono, edad, seguro, domicilio);
        pacientes[i] = p;
    }
    cout << "--------------------------------------" << endl;

    while(opcion != 0){
        cout << "Para eligir la opcion escriba el numero. Además para cerrar el programa escriba 0." << endl;
        cout << "---------------MENU---------------" << endl;
        cout << "1) Listar los nombres de pacintes." << endl;
        cout << "2) Obtener el porcentaje de pacientes hospitalizados de las categorı́as conocidas." << endl;
        cout << "3) Obtener el porcentaje de hombres y de mujeres hospitalizadas." << endl;
        cout << "4) Dado el nombre del paciente, listar todos los datos relacionados con dicho paciente." << endl;
        cout << "5) Calcular el porcentaje de pacientes que poseen seguro médico." << endl;
        cout << "Ingrese opcion: "; cin >> opcion;
        
        if(opcion == 0){
            cout << "Adiós." << endl;
        }
        else if(opcion == 1){
            enlistar(pacientes, N);
        }
        else if(opcion == 2){
            porcentajeEdad(pacientes, N);
        }
        else if(opcion == 3){
            porcentaje_hombres_mujeres(pacientes, N);   
        }
        else if(opcion == 4){
            string nombre_buscar= "";
            cout << "Ingrese nombre de paciente a buscar: "; cin >> nombre_buscar;
            buscarPaciente(pacientes, N, nombre_buscar);
        }
        else if(opcion == 5){
            porcentajeSeguro(pacientes, N);
        }
        else{
            opcion = 1;
        }        
    }
    return 0;
    
}
