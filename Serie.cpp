// Cedrick Patricio Treviño Ortiz
// A01198868
#include "Serie.h"

Serie::Serie() {
    iD = "ABC";
    title = "9";
    duration = 159;
    genre = "TERROR";
    rating = 10;
    N_episodes = 25;
}

Serie::Serie(string _iD, string _title, int _duration, string _genre, int _rating, int N_episodes_) : Film(_iD, _title,
                                                                                                           _duration,
                                                                                                           _genre,
                                                                                                           _rating),
                                                                                                      N_episodes(
                                                                                                              N_episodes_) {}

void Serie::setN_episodes(int N_episodes_) {
    N_episodes = N_episodes_;
}

int Serie::getN_episodes() {
    return N_episodes;
}

double Serie::averageRating() {
    double Total_average = 0;

    for (int i = 0; i < N_episodes; i++) {
        Total_average += episodes[i].getRating();
    }

    if (N_episodes > 0) {
        return Total_average / N_episodes;
    } else {
        return 0;
    }
}

Episode Serie::getEpisode(int &index) {
    Episode episode;
    if (N_episodes >= index) {
        return episodes[index];
    } else {
        index = -1;
        return episode;
    }
}

void Serie::setEpisode(int &index, Episode _episode) {
    // Validate that the episode exists
    // if it does not exist, nothing is changed
    if (index >= 0 && index < N_episodes) {
        episodes[index] = _episode;
    } else {
        // the episode you wanted to change does not exist
        index = -1;
    }
}

void Serie::addEpisode(Episode _episode) {
    /// Validate that the space in the array exists
    if (N_episodes < 10) {
        episodes[N_episodes++] = _episode;
    }
}

string Serie::str() {
    string acum = "\n";
    // concatenate the information of all episodes
    for (int index = 0; index < N_episodes; index++) {
        acum = acum + episodes[index].str() + "\n";
    }
    return Film::str() + ", Episodes: " + to_string(N_episodes) + acum;
}
