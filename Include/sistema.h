#ifndef SISTEMA_H
#define SISTEMA_H

#include "estudiante.h"
#include "curso.h"
#include <fstream>
#include <cstdlib> 
using namespace std;

class Sistema {
private:
    Estudiante* estudiantes;
    int numEstudiantes;
    int capacidadEstudiantes; 
    
    Curso* cursos;
    int numCursos;
    int capacidadCursos;
    
    const string ARCHIVO_BINARIO = "data/base_datos_cc112.bin";
    const string ARCHIVO_TEXTO = "data/aprobados.txt";
    
    void expandirArregloEstudiantes();
    void expandirArregloCursos();
public:
    Sistema(); 
    ~Sistema(); 
    void registrarEstudiante(int id, const string& nombre);
    void registrarCurso(int id, const string& nombre);
    void registrarNotaParcial(int idEstudiante, int idCurso, float nota);
    void listarCursos() const;
    void calcularYMostrarPromedios() const;

    void guardarDatosBinario() const;
    void cargarDatosBinario();
    void exportarAprobadosATexto() const;
    void accederRegistroPorID(int idBuscado) const;
};
#endif