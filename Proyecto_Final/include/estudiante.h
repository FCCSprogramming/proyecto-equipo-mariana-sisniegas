#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
using namespace std;

// maximo de cursos que puede llevar un estudiante
const int MAX_CURSOS = 20;

class Estudiante {
private:
    // datos estudiante
    string id;
    string nombre;
    string carrera;
    int ciclo;

    // notas del estudiante
    float notaParcial;
    float notaFinal;
    float notaPC;

    // cursos inscritos
    string cursosInscritos[MAX_CURSOS];
    int numCursos;

public:
    Estudiante();  // constructor

    Estudiante(const string& id, const string& nombre, const string& carrera, int ciclo);     // constructor con parametros

    Estudiante(const Estudiante& other);   // constructor copia

    string obtenerId() const; //Regresar id

    string obtenerNombre() const;    //devuelve el nombre

    // registrar notas estudiante
    void registrarNotas(float parcial, float final, float pc);

    //calcula el promedio
    float calcularDesempeno() const;

    // inscribe al estudiante en un curso
    void inscribirCurso(const string& idCurso);

    //Mostrar informacion del estudiante
    void mostrarInfo() const;
};

#endif

