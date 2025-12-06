#include "../include/estudiante.h"
#include <iostream>
using namespace std;

Estudiante::Estudiante(int id, const string& nombre) : id(id), nombre(nombre), numNotas(0) {}

void Estudiante::agregarNota(int idCurso, float valor) {
    if (numNotas < 10) { 
        notas[numNotas] = {idCurso, valor};
        numNotas++;
    } else {
        cout << "Advertencia: Límite de 10 notas alcanzado para este estudiante." << endl;
    }
}
float Estudiante::calcularPromedio() const {
    if (numNotas == 0) {
        return 0.0f;
    }
    float suma = 0.0f;
    for (int i = 0; i < numNotas; ++i) { 
        suma += notas[i].valor;
    }
    
    float promedio_sin_formato = suma / numNotas;

    float temp = promedio_sin_formato * 100.0f;
    
    int temp_redondeado = static_cast<int>(temp + 0.5f);
    
    return static_cast<float>(temp_redondeado) / 100.0f;
}
void Estudiante::mostrarInfo() const {
    cout << "ID: " << id << " | Nombre: " << nombre;
    float promedio = calcularPromedio();
    
    cout << " | Promedio: " << promedio; 
    
    if (promedio >= 10.5f) {
        cout << " (Aprobado)" << endl;
    } else {
        cout << " (Reprobado)" << endl;
    }
}