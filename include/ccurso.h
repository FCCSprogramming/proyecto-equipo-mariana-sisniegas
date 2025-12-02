#ifndef CURSO_H
#define CURSO_H

#include <iostream>
#include <string>
using namespace std;

class Curso {
private:
    int id;
    string nombre;
    int creditos;

    int* inscritos;
    int cantidadInscritos;
    int capacidadInscritos;

public:
    Curso();
    Curso(int id, const string &nombre, int creditos);
    Curso(const Curso& otro);
    ~Curso();

    int obtenerId() const;
    string obtenerNombre() const;
    int obtenerCreditos() const;

    void inscribir(int estudianteId);
    int obtenerCantidadInscritos() const;
    void mostrarInfo() const;
};

#endif
