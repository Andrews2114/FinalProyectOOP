// Cedrick Patricio Treviño Ortiz
// A01198868
#include "Serie.h"

Serie::Serie(){
    iD = "ABC";
    title = "9";
    duration = 159;
    genre = "TERROR";
    rating = 10;
    N_episodes = 25;

}

Serie::Serie(string _iD, string _title, int _duration, string _genre, int _rating, int _N_episodes){
    iD = _iD;
    title = _title;
    duration = _duration;
    genre = _genre;
    rating = _rating;
    N_episodes = _N_episodes;

}

void Serie::setN_episodes(int _N_episodes){
    N_episodes = _N_episodes;

}


int Serie::getN_episodes(){
    return N_episodes;

}

double Serie::averageRating() {
    double Total_average = 0;

    for(int i=0;i<N_episodes;i++) {
        Total_average += episodes[i].getRating();
    }

    if(N_episodes > 0) {
        return Total_average/N_episodes;
    }else {
        return 0;
    }
}
Episode Serie::getEpisode(int &index){
    Episode episode;
    if(N_episodes >= index){
        return episodes[index];
    }
    else{
        index = -1;
        return episode;
    }
}

void Serie::setEpisode(int &index, Episode _episode){

    //Validar que exista el episodio
    //si no existe no se cambia nada
    if(index >= 0 && index < N_episodes){
        episodes[index] = _episode;
    }
    else{
        // no existe el episodio que querías cambiar
        index = -1;
    }

}

void Serie::addEpisode(Episode _episode){
    // validar primero que exista espacio en el arreglo
    if(N_episodes < 5){
        episodes[N_episodes++] = _episode;
    }
}

string Serie::str(){
    string acum = "\n";
    //concatenar la informacion de todos los episodios

    for(int index=0; index < N_episodes; index++){
        acum = acum + episodes[index].str() + "\n";
    }

    return iD + ',' + title + ',' + to_string(duration) + ',' + genre + ',' + to_string(rating) + ',' + to_string(N_episodes) + acum;

}
