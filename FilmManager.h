// Cedrick Patricio Treviño Ortiz
// A01198868

#ifndef SERIES_H
#define SERIES_H

#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;

#include "Serie.h"
#include "Movie.h"
#include <vector>

class FilmManager {

private:
    Serie arrSeries[20];
    Movie arrMovies[20];
    Episode arrEpisodes[20];
    int N_movies;
    int N_series;
    int N_episodes;

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

    void filter(char option = ' ');

    void filter(const string& option1 = "l", double option2 = 0);

    void filterMovie(double a1);

    void rateVideo(char type='l', double rating=0);

    void inventory();
};

#endif // SERIES_H
