#ifndef SISTEMA_H
#define SISTEMA_H

#include "estudiante.h"
#include "curso.h"

class Sistema {
private:
    Estudiante* estudiantes; // arreglo dinámico
    int cantEstudiantes;
    int capacidadEstudiantes;

public:
    Sistema();
    ~Sistema();

    void agregarEstudiante(const Estudiante& e);
    void listarEstudiantes() const;
};

#endif

