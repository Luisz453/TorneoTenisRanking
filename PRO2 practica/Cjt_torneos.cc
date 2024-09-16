/** @file Cjt_torneos.cc
    @brief Código de la clase Cjt_torneos
*/
#include "Cjt_torneos.hh"

Cjt_torneos::Cjt_torneos()
{
}

  
void Cjt_torneos::nuevo_torneo(const string &id, int num_cat)
{
    Torneo new_tor;
    new_tor.anadir_categoria(num_cat);
    ct.insert(make_pair(id, new_tor));
}


void Cjt_torneos::eliminar_torneo(const string &id, Cjt_jugadores& jug)
{
    map<string,Torneo>::iterator it = ct.find(id);
    (*it).second.actualizar(jug);
    ct.erase(it);
}
  
bool Cjt_torneos::existe(const string &id) const
{
    map<string,Torneo>::const_iterator it = ct.find(id);
    return it != ct.end();
}
 
int Cjt_torneos::num_torneos() const
{
    return ct.size();
}

void Cjt_torneos::iniciar_torneo (const string &id, const Cjt_jugadores &jug)
{
    int num_jugadores;
    cin >> num_jugadores;
    map<string, Torneo>::iterator it = ct.find(id);
    (*it).second.inicializar_ins_actuales(jug, num_jugadores);
    (*it).second.crear_cuadro_emparejamientos(num_jugadores);
    (*it).second.imprime_cuadro_emparejamientos();
}

void Cjt_torneos::finalizar_torneo (const string &id, Cjt_jugadores& jug, const Cjt_categorias& cat)
{
    map<string, Torneo>::iterator it = ct.find(id);
    (*it).second.resultados_torneo(jug, cat);
    (*it).second.sumar_puntos(jug);
    (*it).second.actualizar(jug);
    (*it).second.imprimir_lista_puntos();
}
 
void Cjt_torneos::leer()
{
    int T;
    cin >> T;
    for ( int i = 0; i < T; ++i){
        string nombre;
        cin >> nombre;
        int c;
        cin >> c;
        Torneo tor;
        tor.anadir_categoria(c);
        ct.insert(make_pair(nombre,tor));
    }
}

void Cjt_torneos::imprimir_lista_torneos(const Cjt_categorias &cat)
{
    cout << ct.size() << endl;
    map<string,Torneo>::iterator it = ct.begin();
    while ( it != ct.end()){
        cout << (*it).first << ' ';
        cat.categoria_nombre((*it).second.consultar_categoria());
        ++it;
    }  
}

void Cjt_torneos::lista_inscritos(const string &nj)
{
    map<string,Torneo>::iterator it = ct.begin();
    while ( it != ct.end()){
        (*it).second.modificar_inscritos(nj);
        ++it;
    }
}