// Cedrick Patricio Treviño Ortiz
// A01198868
#ifndef EPISODE_H
#define EPISODE_H
#include <string>
#include <iostream>

using namespace std;

class Episode
{
public:
    Episode();
    Episode(string _title, int _season, int _rating);

    void setTitle(string _title);
    void setSeason(int _season);
    void setAverage(int _rating);

    string getTitle();
    int getSeason();
    int getRating();

    string str();
    Episode operator +(const Episode& ep) {
        Episode count;
        /*
        count.x = this->x + ep.x;
        count.y = this->x.getRate() + ep.x.getRate();

        return count;
        */
    }

private:
    string title;
    int season, rating;
};

#endif // EPISODE_H
