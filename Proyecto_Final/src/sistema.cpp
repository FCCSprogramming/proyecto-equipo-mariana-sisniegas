#include "sistema.h"
#include <iostream>
#include <fstream>
using namespace std;

// constructor
Sistema::Sistema() {
    capEst = 5;    // capacidad inicial de estudiantes
    cantEst = 0;         //no hay estudiantes
    estudiantes = make_unique<Estudiante[]>(capEst);

    capCursos = 5;   // capacidad inicial de cursos
    cantCursos = 0;   // no hay cursos
    cursos = make_unique<Curso[]>(capCursos);
}

//registra un nuevo estudiante
void Sistema::registrarEstudiante(const string& id, const string& nombre, const string& carrera, int ciclo) {
    if (cantEst == capEst) {
        capEst *= 2;
        auto nuevo = make_unique<Estudiante[]>(capEst);

        // copia los estudiantes antiguos
        for (int i = 0; i < cantEst; i++)
            nuevo[i] = estudiantes[i];

        estudiantes = move(nuevo);
    }

    estudiantes[cantEst++] = Estudiante(id, nombre, carrera, ciclo);
}

// registra un nuevo curso
void Sistema::registrarCurso(const string& id, const string& nombre, const string& profesor, int creditos) {
    // verifica si hay espacio
    if (cantCursos == capCursos) {
        capCursos *= 2;
        auto nuevo = make_unique<Curso[]>(capCursos);

        // copia los cursos anteriores
        for (int i = 0; i < cantCursos; i++)
            nuevo[i] = cursos[i];

        cursos = move(nuevo);
    }

    cursos[cantCursos++] = Curso(id, nombre, profesor, creditos);
}

//inscribe un estudiante en un curso
void Sistema::inscribirEstudianteEnCurso(const string& idEst, const string& idCurso) {
    // busca al estudiante
    for (int i = 0; i < cantEst; i++) {
        if (estudiantes[i].obtenerId() == idEst) {

            // busca el curso
            for (int j = 0; j < cantCursos; j++) {
                if (cursos[j].obtenerId() == idCurso) {

                    // se inscribe en ambos
                    cursos[j].inscribir(idEst);
                    estudiantes[i].inscribirCurso(idCurso);

                    cout << "Inscrito correctamente.\n";
                    return;
                }
            }
        }
    }

    cout << "Error: estudiante o curso no encontrado.\n";
}

//Registra las notas de un estudiante
void Sistema::registrarNotas(const string& idEst, const string& idCurso, float n1, float n2, float n3) {
    (void)idCurso; 
    for (int i = 0; i < cantEst; i++) {
        if (estudiantes[i].obtenerId() == idEst) {
            estudiantes[i].registrarNotas(n1, n2, n3);
            cout << "Notas registradas.\n";
            return;
        }
    }

    cout << "Error: estudiante no encontrado.\n";
}

void Sistema::generarReporte() {    // reporte de todos los estudiantes
    cout << "\n=== REPORTE DE ESTUDIANTES ===\n";
    for (int i = 0; i < cantEst; i++) {
        estudiantes[i].mostrarInfo();
        cout << "\n";
    }
}

// exporta los estudiantes aprobados a un archivo
void Sistema::exportarAprobados(const string& archivo) {
    ofstream out(archivo);

    for (int i = 0; i < cantEst; i++) {
        if (estudiantes[i].calcularDesempeno() >= 11)
            out << estudiantes[i].obtenerId() << " "
                << estudiantes[i].obtenerNombre() << "\n";
    }

    out.close();
    cout << "Archivo generado.\n";
}

//guarda los estudiantes en archivo binario
void Sistema::guardarEnBinario(const string& archivo) {
    ofstream out(archivo, ios::binary);

    // guarda primero la cantidad
    out.write((char*)&cantEst, sizeof(int));

    // guarda los datos de los estudiantes
    out.write((char*)estudiantes.get(),
              sizeof(Estudiante) * cantEst);

    out.close();
    cout << "Guardado en binario.\n";
}

// carga los estudiantes desde un archivo binario
void Sistema::cargarDesdeBinario(const string& archivo) {
    ifstream in(archivo, ios::binary);

    if (!in.is_open()) {
        cout << "Error: archivo no existe.\n";
        return;
    }

    // lee la cantidad de estudiantes
    in.read((char*)&cantEst, sizeof(int));

    estudiantes = make_unique<Estudiante[]>(cantEst);

    // lee los estudiantes
    in.read((char*)estudiantes.get(),
            sizeof(Estudiante) * cantEst);

    in.close();
    cout << "Cargado desde binario.\n";
}

// acceso directo a un estudiante desde el archivo
void Sistema::accesoDirecto(const string& archivo, int pos) {
    ifstream in(archivo, ios::binary);

    if (!in.is_open()) {
        cout << "Archivo no encontrado.\n";
        return;
    }

    Estudiante e;

    in.seekg(sizeof(int) + pos * sizeof(Estudiante), ios::beg);    // se mueve a la posicion indicada
    in.read((char*)&e, sizeof(Estudiante));

    e.mostrarInfo();
    in.close();
}

// lista todos los estudiantes
void Sistema::listarEstudiantes() {
    for (int i = 0; i < cantEst; i++) {
        estudiantes[i].mostrarInfo();
        cout << "\n";
    }
}

// lista todos los cursos
void Sistema::listarCursos() {
    for (int i = 0; i < cantCursos; i++) {
        cursos[i].mostrarInfo();
        cout << "\n";
    }
}

