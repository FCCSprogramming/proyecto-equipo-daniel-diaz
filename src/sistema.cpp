#include "../include/sistema.h"
#include <iostream>
#include <fstream>
using namespace std;

const int CAPACIDAD_INICIAL = 5; 

Sistema::Sistema() : numEstudiantes(0), capacidadEstudiantes(CAPACIDAD_INICIAL),
                     numCursos(0), capacidadCursos(CAPACIDAD_INICIAL) {
    estudiantes = new Estudiante[CAPACIDAD_INICIAL];
    cursos = new Curso[CAPACIDAD_INICIAL];
}

Sistema::~Sistema() {
    delete[] estudiantes;
    delete[] cursos;
}

void Sistema::expandirArregloEstudiantes() {
    capacidadEstudiantes *= 2;
    Estudiante* nuevoArreglo = new Estudiante[capacidadEstudiantes];
    
    for (int i = 0; i < numEstudiantes; ++i) {
        nuevoArreglo[i] = estudiantes[i];
    }
    
    delete[] estudiantes;
    estudiantes = nuevoArreglo;
    cout << "Sistema: Arreglo de estudiantes expandido a " << capacidadEstudiantes << endl;
}

void Sistema::expandirArregloCursos() {
    capacidadCursos *= 2;
    Curso* nuevoArreglo = new Curso[capacidadCursos];
    
    for (int i = 0; i < numCursos; ++i) {
        nuevoArreglo[i] = cursos[i];
    }
    
    delete[] cursos;
    cursos = nuevoArreglo;
    cout << "Sistema: Arreglo de cursos expandido a " << capacidadCursos << endl;
}

void Sistema::registrarEstudiante(int id, const string& nombre) {
    for (int i = 0; i < numEstudiantes; ++i) {
        if (estudiantes[i].getId() == id) {
            cout << "Error: El ID de estudiante " << id << " ya existe." << endl;
            return;
        }
    }
    
    if (numEstudiantes >= capacidadEstudiantes) {
        expandirArregloEstudiantes();
    }
    
    estudiantes[numEstudiantes] = Estudiante(id, nombre);
    numEstudiantes++;
    cout << "Estudiante " << nombre << " registrado con éxito." << endl;
}

void Sistema::registrarCurso(int id, const string& nombre) {
    for (int i = 0; i < numCursos; ++i) {
        if (cursos[i].getId() == id) {
            cout << "Error: El ID de curso " << id << " ya existe." << endl;
            return;
        }
    }

    if (numCursos >= capacidadCursos) {
        expandirArregloCursos();
    }
    
    cursos[numCursos] = Curso(id, nombre);
    numCursos++;
    cout << "Curso " << nombre << " registrado con éxito." << endl;
}

void Sistema::registrarNotaParcial(int idEstudiante, int idCurso, float nota) {
    Estudiante* est_ptr = nullptr;
    
    for (int i = 0; i < numEstudiantes; ++i) {
        if (estudiantes[i].getId() == idEstudiante) {
            est_ptr = &estudiantes[i];
            break;
        }
    }
    
    if (est_ptr == nullptr) {
        cout << "Error: Estudiante con ID " << idEstudiante << " no encontrado." << endl;
        return;
    }
    
    bool curso_encontrado = false;
    for (int i = 0; i < numCursos; ++i) {
        if (cursos[i].getId() == idCurso) {
            curso_encontrado = true;
            break;
        }
    }
                          
    if (!curso_encontrado) {
        cout << "Error: Curso con ID " << idCurso << " no encontrado." << endl;
        return;
    }

    est_ptr->agregarNota(idCurso, nota);
    cout << "Nota de " << nota << " registrada para " << est_ptr->getNombre() 
         << " en el curso " << idCurso << "." << endl;
}

void Sistema::listarCursos() const {
    if (numCursos == 0) {
        cout << "No hay cursos registrados." << endl;
        return;
    }
    cout << "\n--- LISTA DE CURSOS ---" << endl;
    for (int i = 0; i < numCursos; ++i) {
        cout << "ID: " << cursos[i].getId() << ", Nombre: " << cursos[i].getNombre() << endl;
    }
}

void Sistema::calcularYMostrarPromedios() const {
    if (numEstudiantes == 0) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }
    cout << "\n--- PROMEDIOS DE ESTUDIANTES ---" << endl;
    for (int i = 0; i < numEstudiantes; ++i) {
        estudiantes[i].mostrarInfo(); 
    }
}

void Sistema::guardarDatosBinario() const {
    ofstream ofs(ARCHIVO_BINARIO, ios::binary | ios::out);
    if (!ofs) {
        cerr << "Error: No se pudo abrir el archivo binario para guardar." << endl;
        return;
    }

    ofs.write(reinterpret_cast<const char*>(&numEstudiantes), sizeof(int));
    for (int i = 0; i < numEstudiantes; ++i) {
        ofs.write(reinterpret_cast<const char*>(&estudiantes[i]), sizeof(Estudiante));
    }

    ofs.write(reinterpret_cast<const char*>(&numCursos), sizeof(int));
    for (int i = 0; i < numCursos; ++i) {
        ofs.write(reinterpret_cast<const char*>(&cursos[i]), sizeof(Curso));
    }

    ofs.close();
    cout << "Datos guardados exitosamente en: " << ARCHIVO_BINARIO << endl;
}

void Sistema::cargarDatosBinario() {
    ifstream ifs(ARCHIVO_BINARIO, ios::binary | ios::in);
    if (!ifs) {
        cout << "Advertencia: Archivo binario no encontrado. Iniciando con base de datos vacía." << endl;
        return;
    }
    
    delete[] estudiantes;
    delete[] cursos;

    ifs.read(reinterpret_cast<char*>(&numEstudiantes), sizeof(int));
    capacidadEstudiantes = numEstudiantes > 0 ? numEstudiantes : CAPACIDAD_INICIAL;
    estudiantes = new Estudiante[capacidadEstudiantes];

    for (int i = 0; i < numEstudiantes; ++i) {
        ifs.read(reinterpret_cast<char*>(&estudiantes[i]), sizeof(Estudiante));
    }

    ifs.read(reinterpret_cast<char*>(&numCursos), sizeof(int));
    capacidadCursos = numCursos > 0 ? numCursos : CAPACIDAD_INICIAL;
    cursos = new Curso[capacidadCursos];
    
    for (int i = 0; i < numCursos; ++i) {
        ifs.read(reinterpret_cast<char*>(&cursos[i]), sizeof(Curso));
    }

    ifs.close();
    cout << "Datos cargados exitosamente desde: " << ARCHIVO_BINARIO << endl;
}

void Sistema::exportarAprobadosATexto() const {
    ofstream ofs(ARCHIVO_TEXTO);
    if (!ofs) {
        cerr << "Error: No se pudo abrir el archivo de texto para exportar." << endl;
        return;
    }

    ofs << "--- ESTUDIANTES APROBADOS (PROMEDIO >= 10.5) ---" << endl;
    for (int i = 0; i < numEstudiantes; ++i) {
        if (estudiantes[i].calcularPromedio() >= 10.5f) {
            ofs << "ID: " << estudiantes[i].getId() << ", Nombre: " << estudiantes[i].getNombre() 
                << ", Promedio: " << estudiantes[i].calcularPromedio() << endl; 
        }
    }

    ofs.close();
    cout << "Estudiantes aprobados exportados exitosamente a: " << ARCHIVO_TEXTO << endl;
}

void Sistema::accederRegistroPorID(int idBuscado) const {
    ifstream ifs(ARCHIVO_BINARIO, ios::binary | ios::in);
    if (!ifs) {
        cerr << "Error: No se pudo abrir el archivo binario para acceso directo. Guarde los datos primero (Opción 5)." << endl;
        return;
    }

    int total_estudiantes_en_archivo;
    ifs.read(reinterpret_cast<char*>(&total_estudiantes_en_archivo), sizeof(int));
    
    long long registro_offset = sizeof(int) + (idBuscado - 1) * sizeof(Estudiante);

    ifs.seekg(registro_offset);

    Estudiante est(0, "");
    ifs.read(reinterpret_cast<char*>(&est), sizeof(Estudiante));

    if (!ifs || est.getId() != idBuscado || idBuscado > total_estudiantes_en_archivo || idBuscado <= 0) {
        cout << "Registro no encontrado para el ID " << idBuscado << "." << endl;
    } else {
        cout << "\n--- REGISTRO ENCONTRADO POR ACCESO DIRECTO ---" << endl;
        est.mostrarInfo();
        cout << "-----------------------------------------------" << endl;
    }

    ifs.close();
}