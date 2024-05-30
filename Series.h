// Cedrick Patricio Trevi�o Ortiz
// A01198868

#ifndef SERIES_H
#define SERIES_H
#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <sstream>

using namespace std;

#include "Serie.h"

class Series{
    public:
        // M�todo Constructor
        Series();

        // M�todo Modificador
        void setCantidadSeries(int _cantidadSeries);

        // M�todo de Acceso
        int getCantidadSeries();

        // Otros M�todos
        void addSerie(Serie _series);
        void calculaCalificacionPromedioSeries();
        void leerArchivo();
        void reporteSeries(int calificacion);
        void inventario();

    protected:

    private:
        Serie arrSeries[100];
        int cantidadSeries;
};

#endif // SERIES_H
