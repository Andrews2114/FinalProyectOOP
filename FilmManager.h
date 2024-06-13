// Cedrick Patricio Treviño Ortiz
// A01198868

#ifndef SERIES_H
#define SERIES_H

#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <sstream>

using namespace std;

#include "Serie.h"
#include "Movie.h"

class FilmManager {

private:
    Serie arrSeries[100];
    Movie arrMovies[100];
    int N_movies;
    int N_series;

public:

    FilmManager();

    int getN_series();

    int getN_movies();

    void setN_series(int N_series1);

    void setN_movies(int N_movies1);

    void addSerie(Serie _series);

    void addMovie(Movie _movie);

    void AverageRatingSeries();

    void AverageRatingMovies();

    void ReadFileSeries();

    void ReadFileMovies();

    void ReportSeries(int rating);

    void inventory();
};

#endif // SERIES_H
