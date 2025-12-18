#include "curso.h"
#include <iostream>
using namespace std;

// constructor
Curso::Curso()
    : id(""), nombre(""), profesor(""),
      creditos(0), numEstudiantes(0) 
{
    // se inicia con strings vacíos
    for (int i = 0; i < MAX_ESTUD; i++)
        estudiantesInscritos[i] = "";
}

// constructor con parametros
Curso::Curso(const string& id, const string& nombre, const string& profesor, int creditos)
    : id(id), nombre(nombre), profesor(profesor),
      creditos(creditos), numEstudiantes(0)
{

    for (int i = 0; i < MAX_ESTUD; i++)
        estudiantesInscritos[i] = "";
}

// regresa ID del curso
string Curso::obtenerId() const {
    return id;
}

// regresa nombre del curso
string Curso::obtenerNombre() const {
    return nombre;
}

//inscribe a un estudiante en el curso usando ID
void Curso::inscribir(const string& idEstudiante) {

    // ver si el estudiante esta inscrito
    for (int i = 0; i < numEstudiantes; i++) {
        if (estudiantesInscritos[i] == idEstudiante)
            return;
    }

    //gregar estudiante
    if (numEstudiantes < MAX_ESTUD) {
        estudiantesInscritos[numEstudiantes++] = idEstudiante;
    }
}

// mostrar información del curso
void Curso::mostrarInfo() const {
    cout << "ID Curso: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Profesor: " << profesor << endl;
    cout << "Creditos: " << creditos << endl;

    // estudiantes inscritos
    cout << "Estudiantes inscritos: ";
    for (int i = 0; i < numEstudiantes; i++) {
        cout << estudiantesInscritos[i];
        if (i < numEstudiantes - 1) cout << ", ";
    }
    cout << endl;
}

