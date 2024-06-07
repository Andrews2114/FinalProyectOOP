

#include "Series.h"

// 1.
Series::Series(){
    cantidadSeries = 0;

}
    //Constructor default, inicializa el atributo cantidadSeries
    //con 0.



// 2.
void Series::setCantidadSeries(int _cantidadSeries){

    if(_cantidadSeries >= 0 && _cantidadSeries < 100){
        cantidadSeries = _cantidadSeries;
    }

}
    /*Cambia el valor del atributo cantidadSeries al valor
    recibido en el parámetro de entrada.
    Importante - validar que sea igual o mayor a 0 y menor a
    100, de lo contrario no lo cambia. */



// 3.
int Series::getCantidadSeries( ){
    return cantidadSeries;

}
    /*retorna el valor del atributo cantidadSeries*/



// 4.
void Series::addSerie(Serie _serie){
    if(cantidadSeries < 100){
        arrSeries[cantidadSeries++] = _serie;
    }
    else{
        cout << "No espacio" << endl;
    }

}
    /*Añade una nueva serie al arreglo
    Si y solo si existe espacio disponible!
    Si si añadio la serie -  incrementa el atributo
    cantidadSeries en 1
    Si no se pudo añadir por falta de espacio muestra
    "No espacio"*/



// 5.
void Series::calculaCalificacionPromedioSeries(){

    for(int index = 0; index < cantidadSeries; index++){
        arrSeries[index].averageRating();
    }

}
    /*para todas las series que existan en el arreglo
    manda llamar al método calculaCalificacionPromedio( )
    para que actualice la calificacion de cada Serie del
    arreglo.*/



/* 6.
void Series::leerArchivo(){
    leerArchivo("C:\Users\karak\OneDrive\Escritorio\TC1033 ARCHIVOS");

}
    /*- lee el archivo de Series.csv
    y las da de alta en el arreglo, posteriormente
    lee el archivo de episodios y los añade a su Serie
    correspondiente */

void Series::leerArchivo()
{
    string linea, dato;
    int  index, columna;
    Episodio ep;
    Serie serie;
    ifstream lectura;
    lectura.open("C:\\Users\\karak\\OneDrive\\Escritorio\\Proyectos Clion\\FinalProyect\\Series23.csv", ios::in);
    index = 0;
    while ( getline(lectura, linea)) // lee una serie
    {
       // cout << linea << endl; //borrar
        std::stringstream renglon{linea};

        columna = 0;
        while (getline(renglon, dato, ',')) // separa los elementos,
        {
            switch (columna++)
            {
                case 0: // iD
                    serie.setID(dato);
                    break;
                case 1: // Titulo
                    serie.setTitle(dato);
                    break;
                case 2: // duracion
                    serie.setDuration(stoi(dato));
                    break;
                case 3: // genero
                    serie.setGenre(dato);
                    break;
                case 4: // calificación promedio
                    serie.setCalificacion(stoi(dato));
                    break;
                case 5: //cant episodios - inicializar con 0 episodios todas las series
                    serie.setN_episodes(0);
                    break;
            }
        }// fin while

        // para verificar si se guardo correctamente
       // cout << serie.str( ) << endl;  // borrar
        addSerie(serie);
        //cout << "*********  se añadio una serie - Cantidad de series ="  <<  cantidadSeries << endl;

    }
    lectura.close();

    // LEER LOS EPISODIOS DE LAS SERIES
    index = 0;
    lectura.open("C:\\Users\\karak\\OneDrive\\Escritorio\\Proyectos Clion\\FinalProyect\\Episodios23.csv", ios::in);
    while ( getline(lectura, linea))
    {
      //  cout << linea << endl; // se borra
        std::stringstream renglon(linea);
        columna = 0;
        while (getline(renglon, dato, ',')) // separar los elementos,
        {
            switch (columna++)
            {
                case 0:
                    index = stoi(dato) - 1;  // a qué serie pertenece?
                    break;
                case 1: // Titulo
                    ep.setTitle(dato);
                    break;
                case 2: // temporada
                    ep.setSeason(stoi(dato)); // string to int
                    break;
                case 3: // calificacion
                    ep.setAverage(stoi(dato)); // string to double
                    break;
            }
        } // al salir de aqui ya se separo toda la línea

        arrSeries[index].addEpisode(ep);
    }

    lectura.close();
}


// 7.
void Series::reporteSeries(int calificacion){

    for(int index = 0; index < cantidadSeries; index++){
        if(arrSeries[index].getCalificacion() == calificacion){
            cout << index + 1 << "," << arrSeries[index].str() << endl;
        }
    }

}
    /*despliega todas las series del
    arreglo que tengan la calificación igual a la recibida
    como parámetro de entrada.
    Recorrer todo el arreglo de series con un ciclo for
    desplegar la información de la serie usando el método str( )*/



// 8.
void Series::inventario(){
    int acumuladorPromedio;
    int promedio;

    acumuladorPromedio = 0;

    for(int index = 0; index < cantidadSeries; index++){
        cout << index + 1 << "," << arrSeries[index].str() << endl;
        acumuladorPromedio = arrSeries[index].getCalificacion() + acumuladorPromedio;
    }
    if(cantidadSeries > 0){
        promedio = (acumuladorPromedio / cantidadSeries);
        cout << "Promedio = " << promedio << endl;
    }
    else{
        cout << "No Series\n";
    }

}
    /*despliega todas las series del
    arreglo, además calcula y despliega el promedio de todas
    las series.
    recorrer todo el arreglo de series con un ciclo for
    desplegar la información de la serie usando el método str( )
    incrementar el acumuladorPromedio con la calificacion de la
    serie[index]
    Si el arreglo no tiene series deberá desplegar "No Series\n"*/

