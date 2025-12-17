#include "../include/sistema.h"
#include <iostream>
#include <string>
using namespace std;

void limpiarBuffer() {
    if (cin.fail()) {
        cin.clear(); 
    }
    char c;
    while ((c = cin.get()) != '\n' && c != EOF);
}
void mostrarMenu() {
    cout << "\n--- SISTEMA DE GESTION ACADEMICA ---" << endl;
    cout << "1. Registrar Estudiante" << endl;
    cout << "2. Registrar Curso" << endl;
    cout << "3. Registrar Nota Parcial" << endl;
    cout << "4. Listar Datos y Promedios" << endl;
    cout << "-------------------------------------" << endl;
    cout << "5. Guardar Base de Datos (Binario)" << endl;
    cout << "6. Cargar Base de Datos (Binario)" << endl;
    cout << "7. Exportar Aprobados (Texto)" << endl;
    cout << "8. Acceder Registro por ID (Acceso Directo)" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
}
int main() {
    Sistema sistema;
    int opcion;

    do {
        mostrarMenu();
        if (!(cin >> opcion)) {
            cout << "Entrada invalida. Intente de nuevo." << endl;
            cin.clear();
            limpiarBuffer();
            continue;
        }
        limpiarBuffer();

        switch (opcion) {
            case 1: {
                int id;
                string nombre;
                cout << "ID del Estudiante: "; cin >> id; limpiarBuffer();
                cout << "Nombre del Estudiante: "; getline(cin, nombre);
                sistema.registrarEstudiante(id, nombre);
                break;
            }
            case 2: {
                int id;
                string nombre;
                cout << "ID del Curso: "; cin >> id; limpiarBuffer();
                cout << "Nombre del Curso: "; getline(cin, nombre);
                sistema.registrarCurso(id, nombre);
                break;
            }
            case 3: {
                int idEst, idCurso;
                float nota;
                cout << "ID del Estudiante: "; cin >> idEst;
                cout << "ID del Curso: "; cin >> idCurso;
                cout << "Nota: "; cin >> nota; limpiarBuffer();
                sistema.registrarNotaParcial(idEst, idCurso, nota);
                break;
            }
            case 4:
                sistema.calcularYMostrarPromedios();
                sistema.listarCursos();
                break;
            
            case 5: sistema.guardarDatosBinario(); break;
            case 6: sistema.cargarDatosBinario(); break;
            case 7: sistema.exportarAprobadosATexto(); break;
            case 8: {
                int id;
                cout << "ID del Estudiante a buscar: "; cin >> id; limpiarBuffer();
                sistema.accederRegistroPorID(id);
                break;
            }
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    } while (opcion != 0);
    return 0;
}