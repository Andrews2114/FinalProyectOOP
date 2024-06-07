//
// Created by karak on 05/06/2024.
//

#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Film {
protected:
    string iD, title,genre;
    int duration, rating;

public:
    Film();
    Film(string _iD, string _title, int _duration, string _genre, int _rating);

    void setID(string _iD);
    void setTitle(string _title);
    void setDuration(int _duration);
    void setGenre(string _genre);
    void setRating(int _rating);

    string getID();
    string getTitle();
    int getDuration();
    string getGenre();
    int getRating();

    string virtual str() = 0;

};



#endif //FILM_H
