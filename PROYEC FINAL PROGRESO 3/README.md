#PROYECTO FINAL - SISTEMA DE GESTIÓN ACADÉMICA (ENTREGA FINAL)

#1. Estructura y Herramientas
* **Sistema Operativo:** Windows 11 (64-bit)
* **Compilador:** MinGW-w64 (TDM-GCC 9.2.0)
* **Herramienta de Compilación:** Makefile (COMPATIBLE con `mingw32-make`).

#2. Características Implementadas
* Modularidad, Herencia/Polimorfismo, Manejo de Vectores.
* **Persistencia:** Guardado/Carga Binaria, Exportación de Texto, Acceso Aleatorio (`seekg`).

#3. Pruebas de Ejecución (Requisito 6.2)

#A. Ejecución del Programa
1.  Asegúrate de tener el código corregido en todas las carpetas.
2.  Abrir el Símbolo del Sistema (CMD) de Windows.
3.  Navegar a la carpeta raíz del proyecto.
4.  Ejecutar el comando de compilación y ejecución:
    ```bash
    mingw32-make run
    ```
#B. Secuencia de Pruebas Obligatorias

| Opción | Entrada a Teclear | Propósito / Resultado Esperado |
| :---: | :--- | :--- |
| **0** | `0` | Carga inicial (mostrará mensaje de archivo no encontrado). |
| **1** | ID: `1`, Nombre: `Pedro Lopez` | Registro exitoso (Estudiante Aprobado). |
| **1** | ID: `2`, Nombre: `Laura Gomez` | Registro exitoso (Estudiante Reprobado). |
| **2** | ID: `101`, Nombre: `Fundamentos de C++` | Registro exitoso. |
| **3** | Estudiante: `1` / Curso: `101` / Nota: `18.5` | Registro de Nota. |
| **3** | Estudiante: `2` / Curso: `101` / Nota: `10.0` | Registro de Nota. |
| **4** | `4` | **Captura 1:** Listado completo con promedios. |
| **7** | `7` | **Genera:** `data/aprobados.txt` (Solo debe aparecer Pedro). |
| **5** | `5` | **Genera:** `data/base_datos_cc112.bin` (Persistencia completa). |
| **8** | ID a buscar: `2` | **Captura 2:** Acceso directo al registro de Laura (ID 2). |
| **0** | `0` | Salir. |