// Cedrick Patricio Treviño Ortiz
// A01198868
#ifndef SERIE_H
#define SERIE_H

#include <string>
#include <iostream>
#include "Episode.h"
#include "Film.h"

using namespace std;

class Serie : public Film {
private:
    int N_episodes;
    Episode episodes[100];

public:
    Serie();

    Serie(string _iD, string _title, int _duration, string _genre, int _rating, int N_episodes_);

    Serie(string _iD, string _title, int _duration, string _genre, int _rating);

    void setEpisode(int &index, Episode _episode);

    void setN_episodes(int N_episodes_);

    Episode getEpisode(int &index);

    int getN_episodes();

    double averageRating();

    void addEpisode(Episode _episode);

    string str() override;

};

#endif // SERIE_H
