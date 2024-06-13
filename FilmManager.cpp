#include "FilmManager.h"

FilmManager::FilmManager() {
    N_series = 0;
    N_movies = 0;
}
// Default constructor, initializes the attribute N_series
// with 0.

void FilmManager::setN_series(int N_series1) {
    if (N_series1 >= 0 && N_series1 < 100) {
        N_series = N_series1;
    }
}

/* Changes the value of the attribute N_series to the value
received in the input parameter.
Important - validate that it is equal to or greater than 0 and less than
100, otherwise it does not change it. */

int FilmManager::getN_series() {
    return N_series;
}

/* returns the value of the attribute N_series */

void FilmManager::setN_movies(int N_movies1) {
    if (N_movies1 >= 0 && N_movies1 < 100) {
        N_movies = N_movies1;
    }
}

int FilmManager::getN_movies() {
    return N_movies;
}

void FilmManager::addSerie(Serie _serie) {
    if (N_series < 100) {
        arrSeries[N_series++] = _serie;
    } else {
        cout << "No enough storage" << endl;
    }
}

/* Adds a new series to the array
If and only if there is available space!
If the series was added - increments the attribute
cantidadSeries by 1
If it could not be added due to lack of space, it displays
"No space" */

void FilmManager::addMovie(Movie _movie) {
    if (N_movies < 100) {
        arrMovies[N_movies++] = _movie;
    } else {
        cout << "No espacio" << endl;
    }

}

void FilmManager::AverageRatingSeries() {
    for (int index = 0; index < N_series; index++) {
        arrSeries[index].averageRating();
    }
}

/* for all the series that exist in the array
calls the method AverageRatingSeries( )
to update the rating of each Series in the
array. */

void FilmManager::AverageRatingMovies() {
    int acum = 0, value = 0;

    for (int index = 0; index < N_movies; index++) {
        value = arrMovies[index].getRating();
        acum = acum + value;
    }

    if (N_movies > 0) {
        int average = acum / N_movies;
    }
}

/* - reads the FilmManager.csv file
and adds them to the array, then
reads the episodes file and adds them to their
corresponding Series */

void FilmManager::ReadFileSeries() {
    string line, data;
    int index, column;
    Episode ep;
    Serie serie;
    ifstream lecture;
    lecture.open(R"(C:\\Users\\4ndre\\Downloads\\POO2024\\FinalProyectOOP\\Series23.csv)");
    index = 0;
    while (getline(lecture, line)) {
        std::stringstream row{line};
        column = 0;
        while (getline(row, data, ',')) {
            switch (column++) {
                case 0: // iD
                    serie.setID(data);
                    break;
                case 1: // Title
                    serie.setTitle(data);
                    break;
                case 2: // duration
                    serie.setDuration(stoi(data));
                    break;
                case 3: // genre
                    serie.setGenre(data);
                    break;
                case 4: // average rating
                    serie.setRating(stoi(data));
                    break;
                case 5: //N_episodes
                    serie.setN_episodes(stoi(data));
                    break;
            }
        }
        addSerie(serie);
    }
    lecture.close();
    index = 0;
    lecture.open(R"(C:\\Users\\4ndre\\Downloads\\POO2024\\FinalProyectOOP\\Episodios23.csv)");
    while (getline(lecture, line)) {
        std::stringstream row(line);
        column = 0;
        while (getline(row, data, ',')) {
            switch (column++) {
                case 0:
                    index = stoi(data) - 1;
                    break;
                case 1: // Title
                    ep.setTitle(data);
                    break;
                case 2: // Season
                    ep.setSeason(stoi(data)); // string to int
                    break;
                case 3: // rating
                    ep.setAverage(stod(data)); // string to double
                    break;
            }
            arrSeries[index].addEpisode(ep);
        }
    }
    lecture.close();
    for (int i=0; i< index+1; i++) {
        Serie dummy = arrSeries[i];
        cout << dummy.str() << endl;
        cout << "********* a series was added - Number of series =" << i+1 << endl;
    }
}

void FilmManager::ReadFileMovies() {
    string line, data;
    int index, column;
    Movie movie;
    ifstream lecture;
    lecture.open(R"(C:\\Users\\4ndre\\Downloads\\POO2024\\FinalProyectOOP\\Movies23.csv)");
    index = 0;
    while (getline(lecture, line)) {
        stringstream row{line};
        column = 0;
        while (getline(row, data, ',')) {
            switch (column++) {
                case 0: // iD
                    movie.setID(data);
                    break;
                case 1:
                    movie.setTitle(data);
                    break;
                case 2:
                    movie.setDuration(stoi(data));
                    break;
                case 3:
                    movie.setGenre(data);
                    break;
                case 4:
                    movie.setRating(stod(data));
                    break;
                case 5:
                    movie.setOscars(stoi(data));
                    break;
            }
        }
        cout << movie.str() << endl;
        addMovie(movie);
        cout << "********* a movie was added - Number of movies =" << N_movies << endl;
    }
    lecture.close();
}

void FilmManager::ReportSeries(int rating) {
    for (int index = 0; index < N_series; index++) {
        if (arrSeries[index].getRating() == rating) {
            cout << index + 1 << "," << arrSeries[index].str() << endl;
        }
    }
}

/* displays all the series from the
array that have the rating equal to the one received
as an input parameter.
Traverse all the array of series with a for loop
display the series information using the str( ) method */

void FilmManager::inventory() {
    int AverageAcumS, AverageAcumM;
    int averageS, averageM;

    AverageAcumS = 0;
    AverageAcumM = 0;

    for (int index = 0; index < N_series; index++) {
        cout << index + 1 << "," << arrSeries[index].str() << endl;
        AverageAcumS = arrSeries[index].getRating() + AverageAcumS;
    }
    if (N_series > 0) {
        averageS = (AverageAcumS / N_series);
        cout << "Average series = " << averageS << endl;
    } else {
        cout << "No Films\n";
    }

    for (int index = 0; index < N_movies; index++) {
        cout << index + 1 << "," << arrMovies[index].str() << endl;
        AverageAcumM = arrMovies[index].getRating() + AverageAcumM;
    }
    if (N_movies > 0) {
        averageM = (AverageAcumM / N_movies);
        cout << "Average movies = " << averageM << endl;
    } else {
        cout << "No Movies\n";
    }

}

/* displays all the series from the
array, also calculates and displays the average of all
the series. Traverses the entire array of series with a for loop
display the series information using the str( ) method
increment the rating with the rating of the series[index]
If the array has no series it should display "No Films\n" */