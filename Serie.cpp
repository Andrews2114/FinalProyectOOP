// Cedrick Patricio Treviño Ortiz
// A01198868
#include "Serie.h"

// Metodos Constructores
Serie::Serie(){
    iD = "ABC";
    titulo = "9";
    duracion = 159;
    genero = "TERROR";
    calificacion = 10;
    cantEpisodios = 25;

}

Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, int _calificacion, int _cantEpisodios){
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
    cantEpisodios = _cantEpisodios;

}

// Metodos de accion
void Serie::setID(string _iD){
    iD = _iD;

}

void Serie::setTitulo(string _titulo){
    titulo = _titulo;

}

void Serie::setDuracion(int _duracion){
    duracion = _duracion;

}

void Serie::setGenero(string _genero){
    genero = _genero;

}

void Serie::setCalificacion(int _calificacion){
    calificacion = _calificacion;

}

void Serie::setCantidadEpisodios(int _cantEpisodios){
    cantEpisodios = _cantEpisodios;

}

// Metodos receptores
string Serie::getId(){
    return iD;

}

string Serie::getTitulo(){
    return titulo;

}

int Serie::getDuracion(){
    return duracion;

}

string Serie::getGenero(){
    return genero;

}

int Serie::getCalificacion(){
    return calificacion;

}

int Serie::getCantidadEpisodios(){
    return cantEpisodios;

}

Episodio Serie::getEpisodio(int &index){
    Episodio episodio;
    if(cantEpisodios >= index){
        return episodios[index];
    }
    else{
        index = -1;
        return episodio;
    }
}

void Serie::setEpisodio(int &index, Episodio _episodio){

    //Validar que exista el episodio
    //si no existe no se cambia nada
    if(index >= 0 && index < cantEpisodios){
        episodios[index] = _episodio;
    }
    else{
        // no existe el episodio que querías cambiar
        index = -1;
    }

}

void Serie::calculaCalificacionPromedio(){
    // sumar todas las calificaciones de los episodios
    // dividir entre la cantidad de episodios
    int acum = 0;

    for(int index = 0; index < cantEpisodios; index++){
        acum = acum + episodios[index].getCalificacion();
    }
    // evitar div entre 0
    if(cantEpisodios > 0){
        calificacion = acum / cantEpisodios;
    }
    else{
        calificacion = acum;
    }


}

void Serie::addEpisodio(Episodio _episodio){
    // validar primero que exista espacio en el arreglo
    if(cantEpisodios < 5){
        episodios[cantEpisodios++] = _episodio;
    }
}

void Serie::inventario(){

}

void Serie::delEpisodio(){
    if(cantEpisodios > 0){
        cantEpisodios--;
    }
}

string Serie::str(){
    string acum = "\n";
    //concatenar la informacion de todos los episodios

    for(int index=0; index < cantEpisodios; index++){
        acum = acum + episodios[index].str() + "\n";
    }

    return iD + ',' + titulo + ',' + to_string(duracion) + ',' + genero + ',' + to_string(calificacion) + ',' + to_string(cantEpisodios) + acum;

}
