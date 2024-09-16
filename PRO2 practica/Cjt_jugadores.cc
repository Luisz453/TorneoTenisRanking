/** @file Cjt_jugadores.cc
    @brief Código de la clase Cjt_jugadores
*/
#include "Cjt_jugadores.hh"

Cjt_jugadores::Cjt_jugadores()
{

}

bool Cjt_jugadores::criterio(const info_ranking &i1, const info_ranking &i2 )
{
  if ( i1.puntos == i2.puntos){
    return i1.pos_anterior < i2.pos_anterior;
  }
  else{
    return i1.puntos > i2.puntos;
  }
}

void Cjt_jugadores::ordenar_ranking()
{
  
  sort(ranking.begin(),ranking.end(), criterio);
  actualizar_pos();
}

void Cjt_jugadores::actualizar_pos(){
  int num_jugadores = ranking.size();
  for ( int i = 0; i < num_jugadores; ++i){
    ranking[i].pos_anterior = i + 1;
    string name = ranking[i].nombre;
    map<string, Jugador>::iterator it = jugadores.find(name);
    (*it).second.modificar_pos(i+1);
  }
}

bool Cjt_jugadores::existe(const string &id) const
{
  map<string,Jugador>::const_iterator it = jugadores.find(id);
  return it != jugadores.end();
}

int Cjt_jugadores::num_jugadores() const
{
  return ranking.size();

}

string Cjt_jugadores::consultar_nombre_ranking(int pos) const
{
  return ranking[pos - 1].nombre;
}

void Cjt_jugadores::nuevo_jugador(const string &nj)
{
  Jugador new_player;
  int num_players = ranking.size() + 1;
  new_player.modificar_pos(num_players);
  info_ranking info;
  info.nombre = nj;
  info.puntos = 0;
  info.pos_anterior = num_players;

  ranking.push_back(info);
  jugadores.insert(make_pair(nj,new_player)); 
}

void Cjt_jugadores::eliminar_jugador(const string &nj)
{
  map<string,Jugador>::iterator it = jugadores.find(nj);
  int pos = (*it).second.consultar_pos();
  it = jugadores.erase(it);
  int num_jugadores = ranking.size();
  for ( int i = pos; i < num_jugadores; ++i){
    ranking[i-1] = ranking[i];
    ranking[i-1].pos_anterior = i;
    map<string,Jugador>::iterator it = jugadores.find(ranking[i-1].nombre);
    (*it).second.modificar_pos(i);
  }
  ranking.pop_back();
}

void Cjt_jugadores::restar_puntos(pair<string,int> m)
{
  map<string, Jugador>::iterator it = jugadores.find(m.first);
  if ( it != jugadores.end()){ //Tal vez el jugador al que buscamos ha sido dado de baja y esta en ins_anteriores
    int position = (*it).second.consultar_pos();
    ranking[position - 1].puntos -= m.second;
  }
}


void Cjt_jugadores::resultado_partido(const string &id, bool ganado, int sg, int sp, int jg, int jp)
{
  map<string, Jugador>::iterator it = jugadores.find(id);
  (*it).second.datos_partido(ganado, sg, sp, jg, jp);
}


void Cjt_jugadores::leer()
{
    int P;
    cin >> P;
    for ( int i = 1; i <= P; ++i){
        string nombre;
        Jugador player;
        player.modificar_pos(i);
        cin >> nombre;
        
        info_ranking info;
        info.nombre = nombre;
        info.puntos = 0;
        info.pos_anterior = i;

        ranking.push_back(info);
        jugadores.insert(make_pair(nombre,player)); 
      }

}

void Cjt_jugadores::imprimir_ranking() const
{
  int size = ranking.size();
  for( int i = 0; i < size; ++i ){
    cout << i+1 << ' ' << ranking[i].nombre 
         << ' ' << ranking[i].puntos << endl;
  }

}

void Cjt_jugadores::imprimir_lista_jugadores() const
{
  map<string, Jugador>::const_iterator it = jugadores.begin();
  while ( it != jugadores.end()){
    cout << (*it).first << ' ';
    int posicion = (*it).second.consultar_pos();
    cout << "Rk:" << posicion << " Ps:" << ranking[posicion-1].puntos;
    (*it).second.imprimir_stats();
    ++it;
  }   
}

void Cjt_jugadores::estadisticas_jugador(const string &id) const
{
  map<string, Jugador>::const_iterator it = jugadores.find(id);
  cout << (*it).first << ' ';
  int posicion = (*it).second.consultar_pos();
  cout << "Rk:" << posicion << " Ps:" << ranking[posicion-1].puntos;
  (*it).second.imprimir_stats();
}

void Cjt_jugadores::sumar_puntos_torneo(pair<string,int> j)
{
  map<string, Jugador>::iterator it = jugadores.find(j.first);
  (*it).second.torneo_disputado();
  int pos = (*it).second.consultar_pos();
  ranking[pos - 1].puntos += j.second;
}
