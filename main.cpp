#include <iostream>
#include "Serie.h"
#include "FilmManager.h"

using namespace std;

int menu() {
    int opcion;
    cout
            << "Option 1: Read and display data\n"
            << "Option 2: Display stored films\n"
            << "Option 3: Display quantity of films\n"
            << "Option 4: Show the videos with a specific rating or from a specific genre\n"
            << "Option 5: Show the episodes of a specific series with a specific rating\n"
            << "Option 6: Show the movies with a specific rating\n"
            << "Option 7: Rate a video\n"
            << "0 to exit"
            << endl;
    cin >> opcion;
    return opcion;
}

int main() {
    FilmManager t;

    int index, opcion, temporada, duracion, calificacion, cantEpisodios;
    std::string id, titulo, genero;

    opcion = menu();
    char a;
    string g1;
    char s1[100]={0};
    double a1;
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
            case 4: //Show the videos with a specific rating or from a specific genre
                cout << "Filter by rating or genre ?/ r ,g: ";
                cin >> a;
                t.filter(a);
                break;
            case 5: //Show the episodes of a specific series with a specific rating
                cout << "What Series?: \n";
                cin.getline(s1,100);
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                t.filter(s1, a1);
                break;
            case 6: //Show the movies with a specific rating
                cout << "What rating ?: ";
                cin >> a1;
                t.filterMovie(a1);
                break;
            case 7: //Rate a video
                cout << "What type of video and what rating ? M,S and rating: ";
                cin >> a;
                t.rateVideo(a, a1);
                break;
            default:
                break;
        }
        opcion = menu();
    }
    return 0;
}
