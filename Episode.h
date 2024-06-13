// Cedrick Patricio Treviño Ortiz
// A01198868
#ifndef EPISODE_H
#define EPISODE_H

#include <string>
#include <iostream>

using namespace std;

class Episode {
private:
    string title;
    int season;
    double rating;

public:

    Episode();

    Episode(string _title, int _season, int _rating);

    string getTitle();

    int getSeason();

    double getRating();

    void setTitle(string _title);

    void setSeason(int _season);

    void setAverage(double _rating);

    string str();

    Episode operator+(Episode &ep) const;
};

#endif // EPISODE_H
