#include "persona.h"
#include <iostream>
using namespace std;

Persona::Persona() {  // constructor
    id = "";
    nombre = "";
}

Persona::Persona(const string& id, const string& nombre) {   // constructor con parametros
    this->id = id; 
    this->nombre = nombre;
}

// constructor copia
Persona::Persona(const Persona& other) {
    id = other.id;
    nombre = other.nombre;
}

string Persona::obtenerId() const {   // devuelve el id
    return id;
}

// devuelve el nombre
string Persona::obtenerNombre() const {
    return nombre;
}

void Persona::ponerId(const string& id) {  // cambia el id
    this->id = id;
}

void Persona::ponerNombre(const string& nombre) {   // cambia el nombre
    this->nombre = nombre;
}

float Persona::calcularDesempeno() const {
    return 0.0f;
}

// muestra informacion basica de la persona
void Persona::mostrarInfo() const {
    cout << "ID: " << id << " | Nombre: " << nombre;
}

