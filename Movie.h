//
// Created by karak on 06/06/2024.
//

#ifndef MOVIE_H
#define MOVIE_H


#include <iostream>
#include <stdio.h>
#include <string>

#include "Film.h"

using namespace  std;

class Movie : public Film{
private:
    int oscars;
public:
    Movie();
    Movie(string _iD, string _title, int _duration, string _genre, int _rating, int _oscars);

    void setOscars(int _oscars);

    int getOscars();

    string str();

};



#endif //MOVIE_H
