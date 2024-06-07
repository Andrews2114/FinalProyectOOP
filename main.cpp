//
//  main.cpp
//  Proyecto
//
// Cedrick Patricio Treviño Ortiz
// A01198868
// 7 de junio 2024


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Serie.h"
#include "Episode.h"
#include "Series.h"
using namespace std;


int menu(){
    int opcion;

    cin >> opcion;
    return opcion;
}

int main() {
    Series t;

    int  index, opcion, temporada, duracion, calificacion, cantEpisodios;
    std::string id,titulo,genero;

    opcion = menu();

    while (opcion != 0){

        switch (opcion) {

            case 1: // Sirve para leer los datos y mostrar la lectura de los datos
                t.ReadFileSeries();
            	cout <<"\n" << endl;
            	t.ReadFileMovies();
            break;
            case 2: // Sirve para desplegar el inventario de las pelicualas y series con sus respectivos valores
                t.AverageRatingSeries();
            	cout <<"\n" << endl;
            	t.AverageRatingMovies();
            	cout <<"\n" << endl;
            	t.inventory();
            break;
            case 3: // Sirve para obtener la cantidad de series y peliculas de los datos leidos
                cout << t.getN_series() << endl;
            	cout << t.getN_movies() << endl;

            break;
            default:
                break;
        }

        opcion = menu();

    }
    return 0;
}
