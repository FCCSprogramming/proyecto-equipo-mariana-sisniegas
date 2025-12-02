#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <cstring>
using namespace std;

class Persona {
protected:
    string nombre;
    int id;
public:
    Persona();
    Persona(int id, const string &nombre);
    Persona(const Persona &other);
    virtual ~Persona();

    int obtenerId() const;
    string obtenerNombre() const;
    void agregarNombre(const string&);

    virtual void mostrarInfo() const = 0;
    virtual float calcularDesempeno() const;
};

#endif
