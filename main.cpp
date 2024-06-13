#include <iostream>
#include "Serie.h"
#include "FilmManager.h"

using namespace std;

int menu() {
    int opcion;
    cout
            << "Option 1: Read and display data\nOption 2: Display stored films\nOption 3: Display quantity of films\n0 to exit"
            << endl;
    cin >> opcion;
    return opcion;
}

int main() {
    FilmManager t;

    int index, opcion, temporada, duracion, calificacion, cantEpisodios;
    std::string id, titulo, genero;

    opcion = menu();

    while (opcion != 0) {

        switch (opcion) {

            case 1: // It reads the data and display the data reading
                t.ReadFileSeries();
                cout << "\n" << endl;
                t.ReadFileMovies();
                break;
            case 2: // It displays the inventory of movies and series with their respective values
                t.AverageRatingSeries();
                cout << "\n" << endl;
                t.AverageRatingMovies();
                cout << "\n" << endl;
                t.inventory();
                break;
            case 3: // It obtains the quantity of series and movies from the read data
                cout << "There are " << t.getN_series() << " Series" << endl;
                cout << "There are " << t.getN_movies() << " Movies" << endl;
                break;
            default:
                break;
        }
        opcion = menu();
    }
    return 0;
}
