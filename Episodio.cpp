// Cedrick Patricio Treviño Ortiz
// A01198868
#include "Episodio.h"

// Constructores
Episodio::Episodio(){
    titulo = "Paganini";
    temporada = 24;
    calificacion = 10000;

}

Episodio::Episodio(string _titulo, int _temporada, int _calificacion){
     titulo = _titulo;
     temporada = _temporada;
     calificacion = _calificacion;


}

// La pone
void Episodio::setTitulo(string _titulo){
    titulo = _titulo;

}

void Episodio::setTemporada(int _temporada){
    temporada = _temporada;

}

void Episodio::setCalificacion(int _calificacion){
    calificacion = _calificacion;

}

// La recibe
string Episodio::getTitulo(){
    return titulo;

}

int Episodio::getTemporada(){
    return temporada;

}

int Episodio::getCalificacion(){
    return calificacion;

}

// Otro
string Episodio::str(){
    return (titulo + ',' + to_string(temporada) + ',' + to_string(calificacion));

}
