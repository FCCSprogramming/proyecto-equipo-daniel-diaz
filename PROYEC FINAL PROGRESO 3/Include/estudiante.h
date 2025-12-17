#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>

using namespace std;

struct Nota {
    int idCurso;
    float valor;
};
class Estudiante {
protected:
    int id;
    string nombre;
    
    Nota notas[10]; 
    int numNotas;   
public:
    Estudiante() : id(0), nombre(""), numNotas(0) {}

    Estudiante(int id, const string& nombre);
    virtual ~Estudiante() {} 
    
    void agregarNota(int idCurso, float valor);
    float calcularPromedio() const;
    string getNombre() const { return nombre; }
    int getId() const { return id; }
    
    virtual void mostrarInfo() const; 
};
#endif