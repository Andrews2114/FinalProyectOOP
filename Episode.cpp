// Cedrick Patricio Treviño Ortiz
// A01198868
#include "Episode.h"

// Constructores
Episode::Episode(){
    title = "Paganini";
    season = 24;
    rating = 10000;

}

Episode::Episode(string _title, int _season, int _rating){
    title = _title;
    season = _season;
    rating = _rating;


}

// La pone
void Episode::setTitle(string _title){
    title = _title;

}

void Episode::setSeason(int _season){
    season = _season;

}

void Episode::setAverage(int _rating){
    rating = _rating;

}

// La recibe
string Episode::getTitle(){
    return title;

}

int Episode::getSeason(){
    return season;

}

int Episode::getRating(){
    return rating;

}

// Otro
string Episode::str(){
    return (title + ',' + to_string(season) + ',' + to_string(rating));

}
