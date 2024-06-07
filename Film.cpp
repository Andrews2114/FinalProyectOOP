//
// Created by karak on 05/06/2024.
//

#include "Film.h"
Film::Film() {

    iD = "0101";
    title = "Loleros";
    duration = 1000;
    genre = "Drama";
    rating = 90;

}
Film::Film(string _iD, string _title, int _duration, string _genre, int _rating) {

    iD = _iD;
    title = _title;
    duration = _duration;
    genre = _genre;
    rating = _rating;
}

void Film::setID(string _iD) {
    iD = _iD;
}
void Film::setTitle(string _title) {
    title = _title;
}
void Film::setDuration(int _duration) {
    duration = _duration;
}
void Film::setGenre(string _genre) {
    genre = _genre;
}
void Film::setRating(int _rating) {
    rating = _rating;
}

string Film::getID() {
    return iD;
}
string Film::getTitle() {
    return title;
}
int Film::getDuration() {
    return duration;
}
string Film::getGenre() {
    return genre;
}
int Film::getRating() {
    return rating;
}


