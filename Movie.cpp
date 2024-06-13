//
// Created by karak on 06/06/2024.
//

#include "Movie.h"

Movie::Movie() {
    iD = "1902";
    title = "Gta6";
    duration = 15;
    genre = "Action";
    rating = 100;
    oscars = 4;
}

Movie::Movie(string _iD, string _title, int _duration, string _genre, int _rating, int _oscars) : Film(_iD, _title,
                                                                                                       _duration,
                                                                                                       _genre,
                                                                                                       _rating),
                                                                                                  oscars(_oscars) {}

void Movie::setOscars(int _oscars) {
    oscars = _oscars;
}

int Movie::getOscars() {
    return oscars;
}

string Movie::str() {
    return Film::str() + ", Oscars: " + to_string(oscars);
}

