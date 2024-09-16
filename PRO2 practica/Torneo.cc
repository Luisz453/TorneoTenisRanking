/** @file Torneo.cc
    @brief Código de la clase Torneo
*/
#include "Torneo.hh"

Torneo::Torneo(){
}

int Torneo::consultar_categoria() const {
  return categoria;
}


void Torneo::actualizar(Cjt_jugadores& jug) const
{
  int num = ins_anterior.size();
    for ( int i = 0; i < num ; ++i){
        jug.restar_puntos(ins_anterior[i]);
    }
    jug.ordenar_ranking();
}


void Torneo::inicializar_ins_actuales(const Cjt_jugadores &jug, int nj)
{
  vector<pair<string,int>> v;
  ins_actuales = v;
  for ( int i = 1; i <= nj; ++i){
    int num_ranking;
    cin >> num_ranking;
    string name;
    name = jug.consultar_nombre_ranking(num_ranking);
    ins_actuales.push_back(make_pair(name,-1));
  }
}

void Torneo::crear_cuadro_emparejamientos(int nj){
    leer_emparejamientos(emparejamientos,nj,1,1);
}



void Torneo::imprime_cuadro_emparejamientos() 
{
  escriure_emparejamientos(emparejamientos);
  cout << endl;
}

void Torneo::anadir_categoria(int c){
  categoria = c;
}

void Torneo::imprimir_lista_puntos()
{
  int num_ins = ins_actuales.size();
  for ( int i = 0; i < num_ins; ++i){
    if ( ins_actuales[i].second != 0){
    cout << i+1 << '.' << ins_actuales[i].first << ' ' << ins_actuales[i].second << endl;
    }
  }
  ins_anterior = ins_actuales; //Como finalizo torneo, también actualizo ins_anterior
}

void Torneo::resultado(const string &r, const string &player_a, const string &player_b, Cjt_jugadores &jug, bool &ganador)
{
  int longitud = r.length();
  int sga = 0, spa = 0;
  int sgb = 0,  spb = 0;
  int jga = 0, jpa = 0;
  int jgb = 0, jpb = 0;
  if(longitud == 3){
    if (r[0] == '1'){
      jug.resultado_partido(player_a, true, sga, spa, jga, jpa);
      jug.resultado_partido(player_b, false, sgb, spb, jgb, jpb);
      ganador = true;
    }
    else {
      jug.resultado_partido(player_a, false, sga, spa, jga, jpa);
      jug.resultado_partido(player_b, true, sgb, spb, jgb, jpb);
      ganador = false;
    }
  }
  else{
    int i = 0;
    while ( i < longitud) {
      int xa = int(r[i]-'0');
      int xb = int(r[i+2]-'0');
      if(xa > xb){
        ++sga;
        ++spb;
        jga += xa;
        jpa += xb;
        jgb += xb;
        jpb += xa;
      }
      else{
        ++spa;
        ++sgb;
        jga += xa;
        jpa += xb;
        jgb += xb;
        jpb += xa;
      }
      i += 4;
    }
    if ( sga > sgb ){
      jug.resultado_partido(player_a, true, sga, spa, jga, jpa); 
      jug.resultado_partido(player_b, false, sgb, spb, jgb, jpb);
      ganador = true;
    }
    else {
      jug.resultado_partido(player_a, false, sga, spa, jga, jpa);
      jug.resultado_partido(player_b, true, sgb, spb, jgb, jpb);
      ganador = false;
    }
  }
  
}

void Torneo::resultados_torneo(Cjt_jugadores &jug, const Cjt_categorias &cat)
{
  BinTree<string> resultados;
  cuadro_resultados(emparejamientos, resultados, jug);
  int i = 1;
  obtencion_puntos(emparejamientos, cat, i);
  imprime_cuadro_resultados(resultados,emparejamientos);
  cout << endl;
}

void Torneo::sumar_puntos(Cjt_jugadores &jug)
{
  int num_ins = ins_actuales.size();
  for (int i = 0; i < num_ins; ++i){
    jug.sumar_puntos_torneo(ins_actuales[i]);
  }
}


void Torneo::leer_emparejamientos(BinTree<int> &a, int nj, int padre, int potencia){
    potencia = potencia*2;
    int valor_der = potencia + 1 - padre;

    BinTree<int> e,d;
    if(valor_der <= nj){
        leer_emparejamientos(e, nj, padre, potencia);
        leer_emparejamientos(d, nj, valor_der, potencia);
                
    }
    a = BinTree<int>(padre,e,d);
}

void Torneo::escriure_emparejamientos(const BinTree<int> &a) const
{
    if(a.left().empty()){
      cout << a.value() << "." << ins_actuales[a.value()-1].first;
    }
    else{
      cout << '(';
      escriure_emparejamientos(a.left());
      cout << ' ';
      escriure_emparejamientos(a.right());
      cout << ')';
    }
}

void Torneo::cuadro_resultados(BinTree<int> &a, BinTree<string> &r, Cjt_jugadores &jug)
{
  string x;
  cin >> x;
  if(x != "0"){
    BinTree<string> e,d;
    BinTree<int> ae = a.left();
    BinTree<int> ad = a.right();
    cuadro_resultados( ae , e, jug);
    cuadro_resultados (ad , d, jug);
    r = BinTree<string>(x,e,d);
    bool ganador;
    resultado(x , ins_actuales[ae.value() - 1].first, ins_actuales[ad.value() - 1].first, jug, ganador);
    if (ganador){
      a = BinTree<int>(ae.value(),ae,ad); //ganador == true pasa el de la izquierda
      
    } 
    else {
      a = BinTree<int>(ad.value(),ae,ad);  //ganador == false pasa el de la derecha del cuadro
      
    } 
  }
}
void Torneo::imprime_cuadro_resultados(const BinTree<string> &result, const BinTree<int> &a) //Imprime cuadro de resultados
{
    if (not result.empty()){
        cout << '(' ;
        cout << a.left().value() << '.' << ins_actuales[a.left().value() - 1].first
             << " vs " << a.right().value() << '.' <<  ins_actuales[a.right().value() - 1].first
             << ' ' << result.value() ;
        imprime_cuadro_resultados(result.left(), a.left());
        imprime_cuadro_resultados(result.right(),a.right());
        cout << ')';
    }

}

void Torneo::obtencion_puntos(const BinTree<int> &a, const Cjt_categorias &cat, int i)
{
  if ( not a.empty()){
    if ( ins_actuales[a.value() - 1].second == -1 ){
      ins_actuales[a.value() - 1].second = cat.obtener_puntos(categoria, i);
    }
    ++i;
    obtencion_puntos(a.left(), cat, i);
    obtencion_puntos(a.right(), cat, i);
  }
}


void Torneo::modificar_inscritos(const string &nj)
{
  bool encontrado = false;
  int num_ins_ant = ins_anterior.size();
  int i = 0;
  while(not encontrado and i < num_ins_ant){
    if(ins_anterior[i].first == nj){
      ins_anterior[i].second = 0;
      encontrado = true;
    }
    ++i;
  }
}
