#include "curso.h"

Curso::Curso() {
    id = 0;
    nombre = "Sin nombre";
    creditos = 0;

    capacidadInscritos = 2;
    cantidadInscritos = 0;
    inscritos = new int[capacidadInscritos];
}

Curso::Curso(int id, const string &nombre, int creditos)
    : id(id), nombre(nombre), creditos(creditos) {
    capacidadInscritos = 2;
    cantidadInscritos = 0;
    inscritos = new int[capacidadInscritos];
}

Curso::Curso(const Curso &other) {
    id = other.id;
    nombre = other.nombre;
    creditos = other.creditos;

    capacidadInscritos = other.capacidadInscritos;
    cantidadInscritos = other.cantidadInscritos;

    inscritos = new int[capacidadInscritos];
    for (int i = 0; i < cantidadInscritos; i++) {
        inscritos[i] = other.inscritos[i];
    }
}

Curso::~Curso() {
    delete[] inscritos;
}

int Curso::obtenerId() const { return id; }
string Curso::obtenerNombre() const { return nombre; }
int Curso::obtenerCreditos() const { return creditos; }

void Curso::inscribir(int estudianteId) {
    if (cantidadInscritos == capacidadInscritos) {
        capacidadInscritos *= 2;
        int* nuevo = new int[capacidadInscritos];

        for (int i = 0; i < cantidadInscritos; i++)
            nuevo[i] = inscritos[i];

        delete[] inscritos;
        inscritos = nuevo;
    }
    inscritos[cantidadInscritos++] = estudianteId;
}

int Curso::obtenerCantidadInscritos() const {
    return cantidadInscritos;
}

void Curso::mostrarInfo() const {
    cout << "Curso ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Créditos: " << creditos << endl;
    cout << "Inscritos: ";

    for (int i = 0; i < cantidadInscritos; i++) {
        cout << inscritos[i] << " ";
    }
}
