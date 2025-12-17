# Sistema de Gestión Académica - Proyecto Final CC112

Soy Daniel Díaz y este es mi proyecto final para el curso de Fundamentos de Programación. He hecho un sistema en C++ para toda la lógica de una escuela : alumnos, cursos, inscripciones y lo más importante, el manejo de actas de notas y archivos.

## 1. Descripción del proyecto
El objetivo de este sistema es permitir que un usuario (administrador) pueda registrar alumnos y cursos de buena manera. No solo se queda en la RAM, sino que implementé  que los datos se guarden en archivos binarios y se puedan recuperar después. 

El programa permite:
* Registrar alumnos y cursos usando herencia.
* Manejar inscripciones y notas parciales.
* Generar reportes automáticos de alumnos aprobados.
* Guardar y cargar la base de datos completa.

## 2. Diseño de clases (POO)

* **Persona (Clase Base):** Es una clase abstracta que define los datos mínimos. Tiene el método virtual puro `mostrarInfo()`, lo que obliga a las clases hijas a implementarlo.
* **Estudiante (Clase Derivada):** Hereda de Persona. Aquí manejo el código del alumno y sus notas. Sobrescribí `calcularDesempeño()` para que saque el promedio real según las notas ingresadas.
* **Curso:** Clase independiente que contiene la info de las materias.
* **Sistema:** Esta es la clase "cerebro". Aquí es donde ocurre toda la gestión de los vectores de estudiantes y cursos, y donde se conectan todas las piezas.

## 3. Persistencia y Archivos
El sistema maneja tres niveles de archivos:
1. **Texto (.txt):** Para exportar a los alumnos aprobados (los que tienen promedio satisfactorio).
2. **Binario (.dat):** Donde guardo toda la "base de datos" de golpe para no perder nada al cerrar el programa.
3. **Acceso Aleatorio:** Usé `seekg` y `seekp` para poder buscar un estudiante por su ID directamente en el archivo sin tener que leer todo el documento desde el inicio. Esto fue de lo más complicado de programar pero ya funciona bien.

## 4.Guía de Compilación y Ejecución
He configurado un **Makefile** para automatizar el proceso. Para compilar y ejecutar el proyecto, sigue estos pasos:

1. **Compilar:** Escribe `make` en la terminal. Esto creará los directorios necesarios y el ejecutable.
2. **Ejecutar:** Escribe `./SistemaAcademica` para iniciar el programa.
3. **Limpiar:** Si deseas borrar los archivos objeto y los generados por el sistema, usa `make clean`.

## 5. Ejemplo de ejecución
Así es como se ve el menú cuando el sistema arranca:

--- SISTEMA DE GESTION ACADEMICA (UNI) ---
1. Registrar Estudiante
2. Registrar Curso
3. Inscribir Alumno
4. Reporte de Aprobados (TXT)
5. Guardar todo (Binario)
6. Salir
> Seleccione una opcion: 1

[SISTEMA] Registrando a: Daniel Diaz...
[SISTEMA] Alumno guardado con exito.