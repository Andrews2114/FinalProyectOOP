
#include "FilmManager.h"

//Created by Andres A01198777
// Function to split a string by a delimiter
string *split(const string &s, char delimiter) {
    auto *tokens = new string[10];
    string token;
    istringstream tokenStream(s);
    int i = 0;
    while (getline(tokenStream, token, delimiter)) {
        tokens[i++] = token;
    }
    return tokens;
}

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
    ifstream seriesFile(R"(C:\\Users\\4ndre\\Downloads\\POO2024\\FinalProyectOOP\\Series23.csv)");
    string line;
    int seriesCount = 0;
    while (getline(seriesFile, line)) {
        string *tokens = split(line, ',');
        Serie s(tokens[0], tokens[1], stoi(tokens[2]), tokens[3], stod(tokens[4]));
        arrSeries[seriesCount++] = s;
        addSerie(s);
        delete[] tokens;
    }
    // Read episodes file
    ifstream episodesFile(R"(C:\\Users\\4ndre\\Downloads\\POO2024\\FinalProyectOOP\\Episodios23.csv)");
    while (getline(episodesFile, line)) {
        string *tokens = split(line, ',');
        Episode e(tokens[1], stoi(tokens[2]), stod(tokens[3]));
        // Add episode to the corresponding series
        for (int i = 0; i < seriesCount; ++i) {
            if (arrSeries[i].getID() == tokens[0]) {
                arrSeries[i].addEpisode(e);
                break;
            }
        }
        delete[] tokens;
    }
    for (int i = 0; i < seriesCount; ++i) {
        cout << arrSeries[i].str() << endl;
        cout << "********* a series was added - Number of series =" << i + 1 << endl;
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

void FilmManager::filter(char option) {
    double rate;
    string genre;
    bool found;
    if (option != ' ') {
        if (option == 'r') {
            cout << "What's the rating? : " << endl;
            cin >> rate;
            for (int index = 0; index < N_series; index++) {
                if (arrSeries[index].getRating() == rate) {
                    cout << arrSeries[index].str() << endl;
                    found = true;
                }
            }
            for (int index = 0; index < N_movies; index++) {
                if (arrMovies[index].getRating() == rate) {
                    cout << arrMovies[index].str() << endl;
                    found = true;
                }
            }
            if (not(found)) { cout << "None found\n"; }
        } else if (option == 'g') {
            cout << "What's the genre? : " << endl;
            cin >> genre;
            for (int index = 0; index < N_series; index++) {
                if (arrSeries[index].getGenre() == genre) {
                    cout << arrSeries[index].str() << endl;
                    found = true;
                }
            }
            for (int index = 0; index < N_movies; index++) {
                if (arrMovies[index].getGenre() == genre) {
                    cout << arrMovies[index].str() << endl;
                    found = true;
                }
            }
            if (not(found)) { cout << "None found\n"; }
        } else { cout << "Invalid Option" << endl; }
    } else {
        cout << "Invalid Option" << endl;
    }
}

void FilmManager::filter(const string &option1, double option2) {
    option2 = 1;
    cout << "What rating?: \n";
    cin >> option2;
    string str;
    if (option1 != "l" && option2 > 0) {
        for (int index = 0; index < N_series; index++) {
            if (arrSeries[index].getTitle() == option1) {
                if (arrSeries[index].getRating() == option2) {
                    cout << arrSeries[index].str() << endl;
                }
                { cout << "None found\n"; }
            }
        }
    } else {
        cout << "Invalid Option" << endl;
    }
}

void FilmManager::filterMovie(double a1) {
    bool found = false;
    if (a1 > 0) {
        for (int index = 0; index < N_movies; index++) {
            if (arrMovies[index].getRating() == a1) {
                if (arrMovies[index].getRating() == a1) {
                    cout << arrMovies[index].str() << endl;
                    found = true;
                }
            }
        }
        if (not(found)) { cout << "None found\n"; }
    } else {
        cout << "Invalid Option" << endl;
    }
}

void FilmManager::rateVideo(char type, double rating) {
    bool found = false;
    string title;
    cout << "What's the title? : " << endl;
    cin >> title;
    cout << "Whats the rating ?" << endl;
    cin >> rating;
    if (type != 'l') {
        if (type == 'S') {
            for (int index = 0; index < N_series; index++) {
                if (arrSeries[index].getTitle() == title) {
                    arrSeries[index].setRating(rating);
                    cout << arrSeries[index].str() << endl;
                    found = true;
                    break;
                }
            }
        } else if (type == 'M') {
            for (int index = 0; index < N_movies; index++) {
                if (arrMovies[index].getTitle() == title) {
                    arrMovies[index].setRating(rating);
                    cout << arrMovies[index].str() << endl;
                    found = true;
                    break;
                }
            }
        } else { cout << "Invalid Option" << endl; }
        if (not(found)) { cout << "None found\n"; }
    } else {
        cout << "Invalid Option" << endl;
    }
}

/* displays all the series from the
array, also calculates and displays the average of all
the series. Traverses the entire array of series with a for loop
display the series information using the str( ) method
increment the rating with the rating of the series[index]
If the array has no series it should display "No Films\n" */