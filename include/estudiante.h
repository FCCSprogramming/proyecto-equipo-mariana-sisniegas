#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <cstring>
#include "persona.h"
using namespace std;

class Estudiante : public Persona {
private:
    float nota1;
    float nota2;

public:
    Estudiante();
    Estudiante(int id, const string& nombre);
    Estudiante(const Estudiante& other);

    void ponerNotas(float n1, float n2);
    float calcularDesempeno() const override;
    void mostrarInfo() const override;
};

#endif
