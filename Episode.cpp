// Cedrick Patricio Treviño Ortiz
// A01198868
#include "Episode.h"

// Constructores
Episode::Episode() {
    title = "Paganini";
    season = 24;
    rating = 1;
}

Episode::Episode(string _title, int _season, int _rating) : title(_title),
                                                            season(_season),
                                                            rating(_rating) {}


void Episode::setTitle(string _title) {
    title = _title;
}

void Episode::setSeason(int _season) {
    season = _season;
}

void Episode::setAverage(double _rating) {
    rating = _rating;
}


string Episode::getTitle() {
    return title;

}

int Episode::getSeason() {
    return season;
}

double Episode::getRating() {
    return rating;
}

string Episode::str() {
    return "Title: " + title + ", Season: " + to_string(season) + ", Rating: " + to_string(rating);
}

Episode Episode::operator+(Episode &ep) const {
    Episode count;

    count.setAverage(rating + ep.getRating());

    return count;
}
