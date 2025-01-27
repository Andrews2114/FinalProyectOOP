
#include <iostream>

#include "Serie.h"

#include "Series.h"

using namespace std;

void leerSerie(std::string &_id, std::string &_titulo, int &_duracion, std::string &_genero, int &_calificacion,
               int &_cantEpisodios) {
    //cout << "Ingresa el id:";
    cin >> _id;

    //cout << "Ingresa el titulo:";
    cin.ignore();
    getline(cin, _titulo);

    //cout << "Ingresa la duracion en minutos:";
    cin >> _duracion;

    // cout << "Ingresa el genero:";
    cin >> _genero;

    // cout << "Ingresa la calificaci�n:";
    cin >> _calificacion;

    //cout << "Ingresa la cantidad de episodios:";
    cin >> _cantEpisodios;
}

void leerEpisodio(std::string &_titulo, int &_temporada, int &_calificacion) {
    //cout << "Ingresa titulo del Episodio:";
    cin.ignore();
    getline(cin, _titulo);
    //cout << "Ingresa temporada:";
    cin >> _temporada;
    // cout << "Ingresa calificaci�n:";
    cin >> _calificacion;
}

int menu() { //: Funci�n que despliega el siguiente men� de opciones y lee y retorna el valor le�do
    int opcion;

    cin >> opcion;
    return opcion;
}

int main() {
    // 1� Declaraci�n de objetos de las clase creadas, llamar a los constructores con par�matros
    // Titulo temporada calificacion
    Episodio episodio1{"GRADUACION", 1, 100}; // calificacion, episodios
    Serie ser{"TEC", "ITESM", 1000, "APRENDIZAJE", 0, 0};
    Series yuhuTec;


    // 2� Declaraci�n de variables
    int index, opcion, temporada, duracion, calificacion, cantEpisodios;
    std::string id, titulo, genero;

    //* 3� Inicializar la vccc antes del ciclo
    opcion = menu();

    //* 4� Incluir la vccc dentro de la condicion del ciclo
    while (opcion != 0) {

        //* 5� Determinar que hacer en cada opcion
        switch (opcion) {
            case 1:
                leerSerie(id, titulo, duracion, genero, calificacion, cantEpisodios);
                ser = Serie(id, titulo, duracion, genero, calificacion, cantEpisodios);
                break;
            case 2:
                //  cout << "Ingresa el nuevo id:";
                cin >> id;
                ser.setID(id);
                break;
            case 3:
                //  cout << "Ingresa titulo:";
                cin.ignore();
                getline(cin, titulo);
                ser.setTitulo(titulo);
                break;
            case 4:
                //  cout << "Ingresa duracion en minutos:";
                cin >> duracion;
                ser.setDuracion(duracion);
                break;
            case 5:
                //   cout << "Ingresa genero:";
                cin >> genero;
                ser.setGenero(genero);
                break;
            case 6:
                //  cout << "Ingresa calificaci�n:";
                cin >> calificacion;
                ser.setCalificacion(calificacion);
                break;
            case 7:
                //   cout << "Ingresa cantidad de episodios:";
                cin >> cantEpisodios;
                ser.setCantidadEpisodios(cantEpisodios);
                break;
            case 8:
                // Desplegar la informaci�n de la serie
                cout << ser.str() << endl;
                break;
            case 10:
                leerEpisodio(titulo, temporada, calificacion);
                episodio1 = Episodio(titulo, temporada, calificacion);
                break;
            case 11: // Desplegar el objeto de la clase Episodio
                cout << episodio1.str() << endl;
                break;
            case 12: // setTitulo
                cin.ignore();
                getline(cin, titulo);
                episodio1.setTitulo(titulo);
                break;
            case 13: // setTemporada
                cin >> temporada;
                episodio1.setTemporada(temporada);
                break;
            case 14: // setCalificacion
                cin >> calificacion;
                episodio1.setCalificacion(calificacion);
                break;
            case 15: // getTitulo
                cout << episodio1.getTitulo() << endl;
                break;
            case 16: // getTemporada
                cout << episodio1.getTemporada() << endl;
                break;
            case 17: // getCalificacion
                cout << episodio1.getCalificacion() << endl;
                break;
            case 18: //
                ser.addEpisodio(Episodio{"Pozole Verde", 2, 100});// instancia anonima de la clase Episodio
                ser.addEpisodio(Episodio{"Mangu Dominicano", 3, 100});
                ser.addEpisodio(Episodio{"Machacado", 4, 100});
                cout << ser.str() << endl;

                break;
            case 19: //
                ser.delEpisodio();
                cout << ser.str() << endl;
                break;
            case 20: //
                // se pide el episodio 1
                cin >> index;
                episodio1 = ser.getEpisodio(index);
                if (index == -1) {
                    cout << "No existe el episodio\n";
                } else {
                    cout << episodio1.str() << endl;
                }
                break;
            case 21: //
                ser.calculaCalificacionPromedio();
                cout << ser.str() << endl;
                break;
            case 22: //
                yuhuTec.leerArchivo();
                break;
            case 23: //
                yuhuTec.calculaCalificacionPromedioSeries();
                yuhuTec.inventario();
                break;
            case 24: //
                cout << yuhuTec.getCantidadSeries() << endl;
                yuhuTec.addSerie(ser);
                cout << yuhuTec.getCantidadSeries() << endl;
                break;
            case 25: //
                cin >> calificacion;
                yuhuTec.reporteSeries(calificacion);
                break;
            default:
                break;
        }
        //* 6� Actualizar la vccc dentro del ciclo
        opcion = menu();

    }
    return 0;
}
