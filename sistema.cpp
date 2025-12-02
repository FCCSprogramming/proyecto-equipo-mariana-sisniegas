#include "sistema.h"
#include <iostream>
using namespace std;

Sistema::Sistema() {
    capacidadEstudiantes = 2;
    cantEstudiantes = 0;
    estudiantes = new Estudiante[capacidadEstudiantes];
}

Sistema::~Sistema() {
    delete[] estudiantes;
}

void Sistema::agregarEstudiante(const Estudiante& e) {
    if (cantEstudiantes == capacidadEstudiantes) {
        
        capacidadEstudiantes *= 2;
        Estudiante* nuevo = new Estudiante[capacidadEstudiantes];

        for (int i = 0; i < cantEstudiantes; i++) {
            nuevo[i] = estudiantes[i];
        }

        delete[] estudiantes;
        estudiantes = nuevo;
    }

    estudiantes[cantEstudiantes++] = e;
}

void Sistema::listarEstudiantes() const {
    for (int i = 0; i < cantEstudiantes; i++) {
        estudiantes[i].mostrarInfo();
    }
}
