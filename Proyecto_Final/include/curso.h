#ifndef CURSO_H
#define CURSO_H

#include <iostream>
#include <string>
using namespace std;

const int MAX_ESTUD = 50;  // cantidad maxima de estudiantes que puede tener un curso

class Curso {
private:
    // datos del curso
    string id;
    string nombre;
    string profesor;
    int creditos;

    string estudiantesInscritos[MAX_ESTUD];  // id de los estudiantes inscritos
    int numEstudiantes; // numero de estudiantes inscritos

public:
    Curso();    // constructor

    Curso(const string& id, const string& nombre, const string& profesor, int creditos);   // constructor con parametros

    //acceso
    string obtenerId() const;
    string obtenerNombre() const;

    void inscribir(const string& idEstudiante);       //inscribir a un estudiante en el curso

    void mostrarInfo() const;            // mostrar la informacion
};

#endif

