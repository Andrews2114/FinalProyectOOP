// Cedrick Patricio Treviño Ortiz
// A01198868
#ifndef SERIE_H
#define SERIE_H
#include <string>
#include <iostream>
#include "Episodio.h"

using namespace std;

class Serie{
    public:
        // Metodos Constructores
        Serie();
        Serie(string _iD, string _titulo, int _duracion, string _genero, int _calificacion, int _cantEpisodios);

        // Metodos de modificación
        void setID(string _iD);
        void setTitulo(string _titulo);
        void setDuracion(int _duracion);
        void setGenero(string _genero);
        void setCalificacion(int _calificacion);
        void setCantidadEpisodios(int _cantEpisodios);

        // Metodos receptores
        string getId();
        string getTitulo();
        int getDuracion();
        string getGenero();
        int getCalificacion();
        int getCantidadEpisodios();

        Episodio getEpisodio(int &index);
        void setEpisodio(int &index, Episodio _episodio);
        void calculaCalificacionPromedio();
        void addEpisodio(Episodio _episodio);
        void inventario();
        void delEpisodio();

        // Otros Metodos
        string str();


    protected:

    private:
        string iD, titulo, genero;
        int duracion, calificacion, cantEpisodios;
        // Composición, arreglos de objetos
        Episodio episodios[5];
};

#endif // SERIE_H
