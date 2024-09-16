/** @file Jugador.hh
    @brief Especificación de la clase Jugador
*/

#ifndef _JUGADOR_HH_
#define _JUGADOR_HH_


#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
using namespace std;
#endif

/** @class Jugador
    @brief Representa un jugador del cicuito. 

    Jugador con sus estadísricas globales(torneos disputados, número de partidos ganados y perdidos, número de sets ganados y perdidos, número de juegos ganados y perdidos)
*/
 
class Jugador
 {
private:
  /** @brief Posicíon en el ranking */
  int pos_ranking;

  /** @brief Número de torneos disputados */
  int torneos;

  /** @brief Partidos ganados */
  int pg;

  /** @brief Partidos perdidos */
  int pp;

  /** @brief Sets ganados */
  int sg;

  /** @brief Sets perdidos */
  int sp;

  /** @brief Juegos ganados */
  int jg; 

  /** @brief Juegos perdidos */
  int jp; 
  //Esatadísticas
public:
  //Constructoras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un jugador.
      \pre <em>Cierto</em>
      \post El resultado es un jugador todas sus estadísticas inicializadas a 0
  */  
   Jugador();

  //Consultoras

  /** @brief Indica la posicíon en el ranking del jugador
      \pre <em>Cierto</em>
      \post El resultado es pos_ranking >= 1
  */ 
  int consultar_pos() const;


  //Modificadora

  /** @brief Modifica la posición en el ranking del jugador
      \pre i es una posición entre 1 y P(número de jugadores)
      \post El resultado es pos_ranking = i
  */  
  void modificar_pos(int i);

  /** @brief Actualiza las estadísticas segun los datos de un partido
      \pre setg >= 0  setp >= 0  juegog >= 0  juegop >= 0
      \post El parámetro implícito queda actualizado
  */  
  void datos_partido(bool ganado, int setg, int setp, int juegog, int juegop);

  /** @brief Actualiza los torneos disputados
      \pre  <em>Cierto</em>
      \post torneos += 1
  */  
  void torneo_disputado();

  //Imprimir
  /** @brief Imprime las estadísticas del jugador
      \pre <em>Cierto</em>
      \post Se han escrito por el canal estandar de salida los torneos disputados,número de partidos ganados 
      y perdidos, número de sets ganados y perdidos, número de juegos ganados y perdidos
  */
  void imprimir_stats() const;



 };
 #endif