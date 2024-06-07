// Cedrick Patricio Treviño Ortiz
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
    // Método Constructor
    Series();

    // Método Modificador
    void setCantidadSeries(int _cantidadSeries);

    // Método de Acceso
    int getCantidadSeries();

    // Otros Métodos
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
