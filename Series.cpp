

#include "Series.h"

// 1.
Series::Series(){
    N_series = 0;
    N_movies = 0;
}
    //Constructor default, inicializa el atributo cantidadSeries
    //con 0.

void Series::setN_series(int _N_series){

    if(_N_series >= 0 && _N_series < 100){
        N_series = _N_series;
    }

}
    /*Cambia el valor del atributo cantidadSeries al valor
    recibido en el parámetro de entrada.
    Importante - validar que sea igual o mayor a 0 y menor a
    100, de lo contrario no lo cambia. */

// 3.
int Series::getN_series( ){
    return N_series;

}
    /*retorna el valor del atributo cantidadSeries*/

void Series::setN_movies(int _N_movies) {
    if(_N_movies >= 0 && _N_movies < 100){
        N_movies = _N_movies;
    }
}
int Series::getN_movies() {
    return N_movies;
}

// 4.
void Series::addSerie(Serie _serie){
    if(N_series < 100){
        arrSeries[N_series++] = _serie;
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

void Series::addMovie(Movie _movie){
    if(N_movies < 100){
        arrMovies[N_movies++] = _movie;
    }
    else{
        cout << "No espacio" << endl;
    }

}

// 5.
void Series::AverageRatingSeries(){
    for(int index = 0; index < N_series; index++){
        arrSeries[index].averageRating();
    }
}
    /*para todas las series que existan en el arreglo
    manda llamar al método calculaCalificacionPromedio( )
    para que actualice la calificacion de cada Serie del
    arreglo.*/

void Series::AverageRatingMovies(){
    int acum = 0, value = 0;

    for(int index = 0; index < N_movies; index++){
        value = arrMovies[index].getRating();
        acum = acum + value;
    }

    if(N_movies > 0) {
        int average;
        average = acum/N_movies;
    }
}

    /*- lee el archivo de Series.csv
    y las da de alta en el arreglo, posteriormente
    lee el archivo de episodios y los añade a su Serie
    correspondiente */

void Series::ReadFileSeries()
{
    string line, data;
    int  index, column;
    Episode ep;
    Serie serie;
    ifstream lecture;
    lecture.open("C:\\Users\\karak\\OneDrive\\Escritorio\\Proyectos Clion\\FinalProyect\\Series23.csv", ios::in);
    index = 0;
    while ( getline(lecture, line))
    {
        std::stringstream row{line};

        column = 0;
        while (getline(row, data, ','))
        {
            switch (column++)
            {
                case 0: // iD
                    serie.setID(data);
                    break;
                case 1: // Titulo
                    serie.setTitle(data);
                    break;
                case 2: // duracion
                    serie.setDuration(stoi(data));
                    break;
                case 3: // genero
                    serie.setGenre(data);
                    break;
                case 4: // calificación promedio
                    serie.setRating(stoi(data));
                    break;
                case 5: //cant episodios - inicializar con 0 episodios todas las series
                    serie.setN_episodes(0);
                    break;
            }
        }


        cout << serie.str( ) << endl;
        addSerie(serie);
        cout << "*********  se añadio una serie - Cantidad de series ="  <<  N_series << endl;

    }
    lecture.close();

    // LEER LOS EPISODIOS DE LAS SERIES
    index = 0;
    lecture.open("C:\\Users\\karak\\OneDrive\\Escritorio\\Proyectos Clion\\FinalProyect\\Episodios23.csv", ios::in);
    while ( getline(lecture, line))
    {
      //  cout << linea << endl; // se borra
        std::stringstream renglon(line);
        column = 0;
        while (getline(renglon, data, ',')) // separar los elementos,
        {
            switch (column++)
            {
                case 0:
                    index = stoi(data) - 1;  // a qué serie pertenece?
                    break;
                case 1: // Titulo
                    ep.setTitle(data);
                    break;
                case 2: // temporada
                    ep.setSeason(stoi(data)); // string to int
                    break;
                case 3: // calificacion
                    ep.setAverage(stoi(data)); // string to double
                    break;
            }
        } // al salir de aqui ya se separo toda la línea

        arrSeries[index].addEpisode(ep);
    }

    lecture.close();

}

void Series::ReadFileMovies() {
    string line, data;
    int  index, column;
    Movie movie;
    ifstream lecture;
    lecture.open("C:\\Users\\karak\\OneDrive\\Escritorio\\Proyectos Clion\\FinalProyect\\Movies23.csv", ios::in);
    index = 0;
    while ( getline(lecture, line))
    {
        std::stringstream row{line};

        column = 0;
        while (getline(row, data, ','))
        {
            switch (column++)
            {
                case 0: // iD
                    movie.setID(data);
                break;
                case 1: // Titulo
                    movie.setTitle(data);
                break;
                case 2: // duracion
                    movie.setDuration(stoi(data));
                break;
                case 3: // genero
                    movie.setGenre(data);
                break;
                case 4: // calificación promedio
                    movie.setRating(stoi(data));
                break;
                case 5: //cant episodios - inicializar con 0 episodios todas las series
                    movie.setOscars(stoi(data));
                break;
            }
        }


        cout << movie.str( ) << endl;
        addMovie(movie);
        cout << "*********  se añadio una pelicula - Cantidad de peliculas ="  <<  N_movies << endl;

    }
    lecture.close();
}

void Series::ReportSeries(int rating){

    for(int index = 0; index < N_series; index++){
        if(arrSeries[index].getRating() == rating){
            cout << index + 1 << "," << arrSeries[index].str() << endl;
        }
    }

}
    /*despliega todas las series del
    arreglo que tengan la calificación igual a la recibida
    como parámetro de entrada.
    Recorrer todo el arreglo de series con un ciclo for
    desplegar la información de la serie usando el método str( )*/


void Series::inventory(){
    int AverageAcumS, AverageAcumM;
    int averageS, averageM;

    AverageAcumS = 0;
    AverageAcumM = 0;

    for(int index = 0; index < N_series; index++){
        cout << index + 1 << "," << arrSeries[index].str() << endl;
        AverageAcumS = arrSeries[index].getRating() + AverageAcumS;
    }
    if(N_series > 0){
        averageS = (AverageAcumS / N_series);
        cout << "Average Series = " << averageS << endl;
    }
    else{
        cout << "No Series\n";
    }

    for(int index = 0;index < N_movies; index++) {
        cout << index + 1 << "," << arrMovies[index].str() << endl;
        AverageAcumM = arrMovies[index].getRating() + AverageAcumM;
    }
    if(N_movies > 0){
        averageM = (AverageAcumM / N_movies);
        cout << "Average movies = " << averageM << endl;
    }
    else{
        cout << "No Movies\n";
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

