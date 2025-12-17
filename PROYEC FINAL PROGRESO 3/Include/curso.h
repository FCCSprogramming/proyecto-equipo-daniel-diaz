#ifndef CURSO_H
#define CURSO_H

#include <string>
using namespace std;

class Curso {
private:
    int id;
    string nombre;
public:
	Curso() : id(0), nombre("") {}
	
    Curso(int id, const string& nombre) : id(id), nombre(nombre) {}
    int getId() const { return id; }
    string getNombre() const { return nombre; }
};
#endif