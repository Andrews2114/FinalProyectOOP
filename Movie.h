//
// Created by karak on 06/06/2024.
//

#ifndef MOVIE_H
#define MOVIE_H


#include "Film.h"

using namespace std;

class Movie : public Film {
private:
    int oscars;
public:
    Movie();

    Movie(string _iD, string _title, int _duration, string _genre, int _rating, int _oscars);

    int getOscars();

    void setOscars(int _oscars);

    string str() override;

};


#endif //MOVIE_H
