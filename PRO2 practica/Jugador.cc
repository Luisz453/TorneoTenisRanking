/** @file Jugador.cc
    @brief Código de la clase Jugador
*/
#include "Jugador.hh"

Jugador::Jugador(){
    torneos = 0;
    pg = 0;
    pp = 0; 
    sg = 0; 
    sp = 0; 
    jg = 0; 
    jp = 0; 
}

int Jugador::consultar_pos() const{
    return pos_ranking;
}

void Jugador::modificar_pos(int i){
    pos_ranking = i;
}

void Jugador::datos_partido(bool ganado, int setg, int setp, int juegog, int juegop){
    if (ganado) ++pg;
    else ++pp;
    sg += setg;
    sp += setp;
    jg += juegog;
    jp += juegop;
}

void Jugador::torneo_disputado(){
    ++torneos;
}

void Jugador::imprimir_stats() const{
    cout << " Ts:" << torneos << " WM:" << pg << " LM:" << pp << " WS:" 
         << sg << " LS:" << sp << " WG:" << jg << " LG:" << jp << endl;

}
