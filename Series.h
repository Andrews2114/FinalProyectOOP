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

class Series{
public:
    Series();

    void setN_series(int _N_series);
    int getN_series();

    void setN_movies(int _N_movies);
    int getN_movies();

    void addSerie(Serie _series);
    void addMovie(Movie _movie);

    void AverageRatingSeries();
    void AverageRatingMovies();

    void ReadFileSeries();
    void ReadFileMovies();

    void ReportSeries(int rating);
    void inventory();

protected:

private:
    Serie arrSeries[100];
    Movie arrMovies[100];
    int N_movies;
    int N_series;
};

#endif // SERIES_H
