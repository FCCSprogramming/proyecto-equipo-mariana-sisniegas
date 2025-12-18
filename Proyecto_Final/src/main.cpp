#include <iostream>
#include <fstream>
#include "sistema.h"
using namespace std;

void mostrarMenu() {  //menu principal del sistema
    cout << "\n======= SISTEMA DE GESTION ACADEMICA =======\n";
    cout << "1. Registrar estudiante\n";
    cout << "2. Registrar curso\n";
    cout << "3. Inscribir estudiante a curso\n";
    cout << "4. Registrar notas de un estudiante\n";
    cout << "5. Generar reportes de estudiantes\n";
    cout << "6. Exportar estudiantes aprobados\n";
    cout << "7. Guardar base de datos\n";
    cout << "8. Cargar datos desde archivo binario\n";
    cout << "9. Acceso directo (random access)\n";
    cout << "10. Listar estudiantes\n";
    cout << "11. Listar cursos\n";
    cout << "0. Salir\n";
    cout << "Opcion: ";
}

int main() {

    Sistema sistema;

    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();     //limpia el buffer

        //registrar un nuevo estudiante
        if (opcion == 1) {
            string id, nombre, carrera;
            int ciclo;

            cout << "ID del estudiante: ";
            getline(cin, id);

            cout << "Nombre: ";
            getline(cin, nombre);

            cout << "Carrera: ";
            getline(cin, carrera);

            cout << "Ciclo: ";
            cin >> ciclo;
            cin.ignore();

            sistema.registrarEstudiante(id, nombre, carrera, ciclo);
        }

        //Registrar un curso
        else if (opcion == 2) {
            string idCurso, nombreCurso, profesor;
            int creditos;

            cout << "ID curso: ";
            getline(cin, idCurso);

            cout << "Nombre curso: ";
            getline(cin, nombreCurso);

            cout << "Profesor: ";
            getline(cin, profesor);

            cout << "Creditos: ";
            cin >> creditos;
            cin.ignore();

            sistema.registrarCurso(idCurso, nombreCurso, profesor, creditos);
        }

        //inscribir a un estudiante al curso
        else if (opcion == 3) {
            string idEst, idCurso;

            cout << "ID estudiante: ";
            getline(cin, idEst);

            cout << "ID curso: ";
            getline(cin, idCurso);

            sistema.inscribirEstudianteEnCurso(idEst, idCurso);
        }

        //registrar las notas de un estudiante en un curso
        else if (opcion == 4) {
            string idEst, idCurso;
            float n1, n2, n3;

            cout << "ID estudiante: ";
            getline(cin, idEst);

            cout << "ID curso: ";
            getline(cin, idCurso);

            cout << "Nota Examen Parcial: ";
            cin >> n1;

            cout << "Nota Examen Final: ";
            cin >> n2;

            cout << "Nota PC: ";
            cin >> n3;
            cin.ignore();

            sistema.registrarNotas(idEst, idCurso, n1, n2, n3);
        }

        //mostrar un reporte general del sistema
        else if (opcion == 5) {
            sistema.generarReporte();
        }

        //exportar estudiantes aprobados a un archivo de texto
        else if (opcion == 6) {
            sistema.exportarAprobados("aprobados.txt");
        }

        //guardar datos en un archivo binario
        else if (opcion == 7) {
            sistema.guardarEnBinario("base.bin");
        }

        //cargar datos desde un archivo binario
        else if (opcion == 8) {
            sistema.cargarDesdeBinario("base.bin");
        }

        //leer un registro usando acceso directo
        else if (opcion == 9) {
            int pos;
            cout << "Posicion a leer del archivo binario: ";
            cin >> pos;
            cin.ignore();

            sistema.accesoDirecto("base.bin", pos);
        }

        //lista de estudiantes registrados
        else if (opcion == 10) {
            sistema.listarEstudiantes();
        }

        //lista de cursos registrados
        else if (opcion == 11) {
            sistema.listarCursos();
        }

    } while (opcion != 0);

    cout << "Saliendo del sistema...\n";
    return 0;
}


