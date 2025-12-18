#include "estudiante.h"
#include <iostream>
using namespace std;

// Constructor
Estudiante::Estudiante() {
    id = "";
    nombre = "";
    carrera = "";
    ciclo = 0;

    //no hay notas registradas
    notaParcial = 0;
    notaFinal = 0;
    notaPC = 0;
    
    numCursos = 0;

    //limpia el arreglo cursos
    for (int i = 0; i < MAX_CURSOS; i++)
        cursosInscritos[i] = "";
}

// Constructor con parametros
Estudiante::Estudiante(const string& id, const string& nombre,
                       const string& carrera, int ciclo)
    : id(id), nombre(nombre), carrera(carrera), ciclo(ciclo) {

    // notas se inicializan en cero
    notaParcial = 0;
    notaFinal = 0;
    notaPC = 0;

    // no hay cursos inscritos
    numCursos = 0;

    for (int i = 0; i < MAX_CURSOS; i++)
        cursosInscritos[i] = "";
}

// constructor copia
Estudiante::Estudiante(const Estudiante& other) {
    id = other.id;
    nombre = other.nombre;
    carrera = other.carrera;
    ciclo = other.ciclo;

    //copia las notas
    notaParcial = other.notaParcial;
    notaFinal = other.notaFinal;
    notaPC = other.notaPC;

    numCursos = other.numCursos;

    // copia los cursos inscritos
    for (int i = 0; i < numCursos; i++)
        cursosInscritos[i] = other.cursosInscritos[i];
}

string Estudiante::obtenerId() const {   // regresar ID del estudiante
    return id; 
}

string Estudiante::obtenerNombre() const {      // regresar nombre de estudiante
    return nombre; 
}

//registrar las notas del estudiante
void Estudiante::registrarNotas(float n1, float n2, float pc) {
    notaParcial = n1;
    notaFinal = n2;
    notaPC = pc;
}

float Estudiante::calcularDesempeno() const {   // Calcular promedio de estudiante
    return (notaParcial + notaFinal + notaPC) / 3.0f;
}
 
void Estudiante::inscribirCurso(const string& idCurso) {     // Inscribr al estudiante

    // curso no esta repetido
    for (int i = 0; i < numCursos; i++)
        if (cursosInscritos[i] == idCurso)
            return;

    // agrega el curso 
        cursosInscritos[numCursos++] = idCurso;
}

//mostrar informacion del estudiante
void Estudiante::mostrarInfo() const {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Carrera: " << carrera << endl;
    cout << "Ciclo: " << ciclo << endl;

    //lista de cursos
    cout << "Cursos inscritos: ";
    for (int i = 0; i < numCursos; i++) {
        cout << cursosInscritos[i];
        if (i < numCursos - 1) cout << ", ";
    }
    cout << endl;

    //notas
    cout << "Notas:\n";
    cout << "Parcial: " << notaParcial << endl;
    cout << "Final:   " << notaFinal << endl;
    cout << "PC:      " << notaPC << endl;

    // Promedio
    cout << "Promedio = " << calcularDesempeno() << endl;
}

