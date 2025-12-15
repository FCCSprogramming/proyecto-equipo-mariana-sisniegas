#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:

    string id;
    string nombre;
    
public:
    // constructor
    Persona();

    Persona(const string& id, const string& nombre);   //Constructor con parametros

    Persona(const Persona& other);    // constructor copia

    //acceso
    string obtenerId() const;
    string obtenerNombre() const; 
    
    //modificar
    void ponerId(const string& id);
    void ponerNombre(const string& nombre);

    // calcular desempeño
    virtual float calcularDesempeno() const;

    virtual void mostrarInfo() const;
};

#endif
