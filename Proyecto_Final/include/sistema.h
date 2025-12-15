#ifndef SISTEMA_H
#define SISTEMA_H

#include <memory>
#include <string>
#include "estudiante.h"
#include "curso.h"
using namespace std;

class Sistema {
private:
    unique_ptr<Estudiante[]> estudiantes;     // arreglo dinamico de estudiantes

    unique_ptr<Curso[]> cursos;      //Arreglo dinamico de cursos

    int cantEst;
    int capEst;
    int cantCursos;
    int capCursos;

public:
    Sistema();    // constructor

    ~Sistema() = default;    // destructor
 
    void registrarEstudiante(const string& id, const string& nombre, const string& carrera, int ciclo);  //Registrar estudiante

    // registra curso
    void registrarCurso(const string& id, const string& nombre, const string& profesor, int creditos);

    // inscribe un estudiante en un curso
    void inscribirEstudianteEnCurso(const string& idEst, const string& idCurso);

    // registra las notas
    void registrarNotas(const string& idEst, const string& idCurso, float n1, float n2, float n3);

    void generarReporte();   //Muestra el reporte

    // exportar aprobados a un archivo
    void exportarAprobados(const string& archivo);

    // guarda en un archivo binario
    void guardarEnBinario(const string& archivo);

    void cargarDesdeBinario(const string& archivo);    // carga desde un archivo binario

    // acceso directo  en el archivo binario
    void accesoDirecto(const string& archivo, int pos);

    void listarEstudiantes();    //Lista estudiantes
 
    void listarCursos();       // lista cursos
};

#endif


