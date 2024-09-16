/** @file Torneo.hh
    @brief Especificación de la clase Torneo
*/

#ifndef _TORNEO_HH_
#define _TORNEO_HH_

#include "Cjt_categorias.hh"
#include "Cjt_jugadores.hh"


#ifndef NO_DIAGRAM
#include <vector>
#include <cmath>
#include "BinTree.hh"
using namespace std;
#endif


/** @class Torneo
    @brief Representa un torneo del circuito y la forma en la se realiza. 

    Un torneo pertenece a una categoría determinada, tiene un número determinado de participantes que se emparejarán según su posición en el ranking
*/
 
class Torneo
 {
private:
  /** @brief Identificador de la categoria a la que pertenece */
  int categoria;

  /** @brief Inscritos anteriores de la ultima edicíon disputada*/
  vector<pair<string,int>> ins_anterior;

  /** @brief Inscritos actuales de la edicíon que se esta disputando*/
  vector<pair<string,int>> ins_actuales;

  /** @brief Cuadro de emparejamientos */
  BinTree<int> emparejamientos;

  /** @brief Lee el cuadro de emparejamientos
      \pre  potencia = 1, padre >= 1, a vacío
      \post Lee el cuadro de emparejamientos al inicar el torneo
  */  
  static void leer_emparejamientos(BinTree<int> &a, int nj, int padre, int potencia);

  /** @brief Imprime el cuadro de emparejamientos
      \pre  <em>Cierto</em>
      \post Se ha escrito por el canal de salida el cuadro de emparejamientos
  */  
  void escriure_emparejamientos(const BinTree<int> &a) const;

  /** @brief Lee el cuadro de resultados y modifica el cuadro de emparejamientos
      \pre  <em>Cierto</em>
      \post Lee el cuadro de resultados y modifica el cuadro de emparejamientos según los resultados
  */  
  void cuadro_resultados(BinTree<int> &a, BinTree<string> &r, Cjt_jugadores &jug);

    /** @brief Imprime el cuadro de resultados y el de emparejmaientos final
      \pre  result y a no vacíos
      \post Se ha escrito a por el canal de salida estándard el cuadro de resultados y el de emparejmaientos final 
  */  
  void imprime_cuadro_resultados(const BinTree<string> &result, const BinTree<int> &a);

    /** @brief Obtiene los puntos de cada jugador en el torneo
      \pre  <em>Cierto</em>
      \post Se obtiene los puntos de cada jugador en el toreno según la ronda en la que hayan quedado
  */  
  void obtencion_puntos(const BinTree<int> &a, const Cjt_categorias &cat, int i);

public:
  //Constructoras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un torneo.
      \pre <em>Cierto</em>
      \post El resultado es un Torneo con un identificador que indica la categoría
  */  
   Torneo();

  //Consultora
  /** @brief Devuelve el id de la categoría
       \pre <em>Cierto</em>
       \post El resultado es un entero que identifica la categoría
  */  
  int consultar_categoria() const;

  /** @brief Resta los puntos de la edición anterior, ordena el ranking y actualiza la posición
       \pre <em>Cierto<em>
       \post El resultado es la resta de los puntos de los jugadores de la lista de inscritos de la edicíon anterior, el ranking y las posiciones actualizadas
  */  
  void actualizar(Cjt_jugadores& jug) const;

  //Modificadoras

  /** @brief Inscribe a los jugadores en el torneo
      \pre  8 <= nj <= 2^(K - 1) 
      \post Se hace la lista de inscritos actuales de la nueva edición del torneo
  */
  void inicializar_ins_actuales(const Cjt_jugadores &jug, int nj);

  /** @brief Confecciona el cuadro de emparejamientos 
      \pre  8 <= nj <= 2^(K - 1)
      \post Confecciona el cuadro de emparejamientos 
  */
  void crear_cuadro_emparejamientos(int nj);

  /** @brief Imprime el cuadro de emparejamientos 
      \pre  <em>Cierto</em>
      \post Imprime el cuadro de emparejamientos
  */
  void imprime_cuadro_emparejamientos();
  
  /** @brief Asigna una categoría a un torneo
      \pre  1 <= c <= C
      \post CATEGORIA = c
  */
  void anadir_categoria(int c);

  /** @brief Imprime la lista de inscritos actuales y los puntos conseguidos por jugador
      \pre ins_actuales no es vacío
      \post Se imprime los jugadores por orden y sus puntos conseguidos si no son 0
  */
  void imprimir_lista_puntos();

  /** @brief El resultado de un partido
      \pre r no es vacío, player_a y player_b son jugadores inscritos en el torneo
      \post Se obtienen las estadísticas a partir r y se modifica el árbol de emparejamientos segun ganador
  */
  void resultado(const string &r, const string &player_a, const string &player_b, Cjt_jugadores &jug, bool &ganador);

  /** @brief Lee los resultados del torneo
      \pre <em>Cierto</em>
      \post Se crea el cuadro de resultados, se obtienen los puntos y se imprime el cuadro de resultados i emparejamientos
  */
  void resultados_torneo(Cjt_jugadores &jug, const Cjt_categorias &cat);

  /** @brief Suma los puntos obtenidos en el torneo a todos los jugadores que han participado
      \pre <em>Cierto</em>
      \post Suma los puntos obtenidos en el torneo a todos los jugadores inscritos en la ultima edición
  */
  void sumar_puntos(Cjt_jugadores &jug);
  

  /** @brief Pone los puntos a 0 de la anterior edición disputada del jugador nj
      \pre <em>Cierto</em>
      \post Pone los puntos a 0 de la anterior edición disputada del jugador nj
  */
  void modificar_inscritos(const string &nj);

 };
 #endif