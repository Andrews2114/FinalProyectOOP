// Cedrick Patricio Treviño Ortiz
// A01198868
#ifndef EPISODIO_H
#define EPISODIO_H
#include <string>
#include <iostream>

using namespace std;



class Episodio
{
   public:
        // Constructores
        Episodio();
        Episodio(string _titulo, int _temporada, int _calificacion);

        // La pone
        void setTitulo(string _titulo);
        void setTemporada(int _temporada);
        void setCalificacion(int _calificacion);

        // La retorna
        string getTitulo();
        int getTemporada();
        int getCalificacion();

        // Otro
        string str();


    protected:

    private:
        string titulo;
        int temporada, calificacion;
};

#endif // EPISODIO_H
