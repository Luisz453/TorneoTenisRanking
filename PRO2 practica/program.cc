/**
 * @mainpage Circuito de torneos de tenis
En esta práctica simularemos la géstion deportiva y el cálculo del ranking de un circuito de torneos de tenis 

*/

/** @file program.cc
    @brief Programa principal para la práctica.
*/

#ifndef NO_DIAGRAM
#include <iostream>
#endif

#include "Cjt_categorias.hh"
#include "Cjt_jugadores.hh"
#include "Cjt_torneos.hh"
using namespace std;

int main() {
    Cjt_categorias cat;
    Cjt_jugadores jug;
    Cjt_torneos tor;
    cat.leer();
    tor.leer();
    jug.leer();
    string operacion;
    cin >> operacion;
    while ( operacion != "fin") {
        cout << '#' << operacion;
        if (operacion == "nuevo_jugador" or operacion == "nj") {
            string nj;
            cin >> nj;
            cout << ' ' << nj << endl;
            if ( jug.existe(nj)) {
                cout << "error: ya existe un jugador con ese nombre" << endl;
            }
            else {
                jug.nuevo_jugador(nj);
                cout << jug.num_jugadores() << endl;
            }
        }
        else if (operacion == "nuevo_torneo" or operacion == "nt") {
            string nt;
            int c;
            cin >> nt;
            cin >> c;
            cout << ' ' << nt << ' ' << c << endl;
            if ( c < 1 or c > cat.num_categorias()) {
                cout << "error: la categoria no existe" << endl; 
            }
            else if (tor.existe(nt)) {
                cout << "error: ya existe un torneo con ese nombre" << endl;
            }
            else{
                tor.nuevo_torneo(nt,c);
                cout << tor.num_torneos() << endl;
            }
        }
        else if (operacion == "baja_jugador" or operacion == "bj") {
            string nj;
            cin >> nj;
            cout << ' ' << nj << endl;
            if ( not jug.existe(nj)) {
                cout << "error: el jugador no existe" << endl;
            }
            else {
                tor.lista_inscritos(nj);
                jug.eliminar_jugador(nj);
                cout << jug.num_jugadores() << endl;
            }
        }
        else if (operacion == "baja_torneo" or operacion == "bt") {
            string nt;
            cin >> nt;
            cout << ' ' << nt << endl;
            if ( tor.existe(nt)) {
                tor.eliminar_torneo(nt,jug);
                cout << tor.num_torneos() << endl; 
            }
            else {
                cout << "error: el torneo no existe" << endl;
            }
        }
        else if (operacion == "iniciar_torneo" or operacion == "it"){
            string nt;
            cin >> nt;
            cout << " " << nt << endl;
            tor.iniciar_torneo( nt, jug);
        }
        else if (operacion == "finalizar_torneo" or operacion == "ft"){
            string nt;
            cin >> nt;
            cout << ' ' << nt << endl;
            tor.finalizar_torneo(nt, jug, cat);
        }
        else if (operacion == "listar_ranking" or operacion == "lr"){
            cout << endl;
            jug.imprimir_ranking();
        }
        else if (operacion == "listar_jugadores" or operacion == "lj"){
            cout << endl;
            cout << jug.num_jugadores() << endl;
            jug.imprimir_lista_jugadores();
        }

        else if (operacion == "consultar_jugador" or operacion == "cj"){
            string nombre;
            cin >> nombre;
            cout <<  ' ' << nombre << endl;
            if ( jug.existe(nombre)){
                jug.estadisticas_jugador(nombre);
            }
            else{
                cout << "error: el jugador no existe" << endl;
            }
        }
        else if (operacion == "listar_torneos" or operacion == "lt"){
            cout << endl;
            tor.imprimir_lista_torneos(cat);
        }
        else if (operacion == "listar_categorias" or operacion == "lc"){
            cout << endl;
            cat.imprimir_categorias();
        }
        cin >> operacion;
    }

}
