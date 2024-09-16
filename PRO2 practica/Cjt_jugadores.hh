/** @file Cjt_jugadores.hh
    @brief Especificación de la clase Cjt_jugadores
*/

#ifndef _CJT_JUGADORES_HH_
#define _CJT_JUGADORES_HH_

#include "Jugador.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#endif


/** @class Cjt_jugadores
    @brief Representa el conjunto de jugadores y el ranking. 

    Contiene todos los jugadores dados de alta del circuito 
*/
 
class Cjt_jugadores
{
private:
  /** @brief Información del ranking: nombre, puntos, posicíon anterior*/
  struct info_ranking{
    string nombre;
    int puntos;
    int pos_anterior;
};

  /** @brief Ranking del circuito*/
  vector<info_ranking> ranking;

  /** @brief Conjunto de jugadores del circuito ordenados alfabéticamente*/
  map<string, Jugador> jugadores;

  /** @brief Criterio que se sigue al ordenar el ranking
      @pre i1 y i2 no son vacíos
      @post Se ordena el ranking siguiendo el criterio
  */
  static bool criterio(const info_ranking &i1, const info_ranking &i2 );

  /** @brief Actualiza la posicíon de todos los jugadores
      \pre <em>Cierto</em>
      \post El resultado es la posicíon de todos los jugadores actualizada
  */ 
  void actualizar_pos();
public:
  //Constructora

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un conjunto de jugadores
      \pre <em>Cierto</em>
      \post El resultado es un conjunto de jugadores vacío
  */  
  Cjt_jugadores();

  /** @brief Ordena el ranking
      \pre <em>Cierto</em>
      \post El ranking queda ordenado siguiendo un criterio específico
  */ 
  void ordenar_ranking();

  
  //Consultoras
  /** @brief Comprueba si existe un jugador con el id como nombre
      \pre <em>Cierto</em>
      \post El resultado indica si existe un jugador en el parametro implícito con el id como nombre
  */
  bool existe(const string &id) const;

  /** @brief Indica el número de jugadores del circuito 
      \pre <em>Cierto</em>
      \post El resultado indica el número de jugadores del parametro implícito 
  */
  int num_jugadores() const;

  /** @brief Consulta el nombre del jugador
      \pre pos <= 1 <= P
      \post El resultado es NOMBRE = id del jugador con posición pos en el ranking 
  */
  string consultar_nombre_ranking(int pos) const;

  //Modificadoras
  /** @brief Añade un nuevo jugador al conjunto de jugadores
      \pre El parámetro implícito no contiene ningún jugador nj
      \post Se ha añadido el jugador con nombre nj al parametre implícito
  */
  void nuevo_jugador(const string &nj);

  /** @brief Elimina un jugador del conjunto de jugadores
      \pre El parámetro implícito contiene un jugador nj del conjunto
      \post Se ha eliminado el jugador con nombre nj del parametre implícito
  */
  void eliminar_jugador(const string &nj);

  /** @brief Resta puntos a un jugador
      \pre El jugador (first) existe y los puntos (second) >= 0
      \post Se han restado puntos al jugador que pertenece al parametre implícito
  */
  void restar_puntos(pair<string,int>);

  /** @brief Obtiene los datos de partido para actualizar estadísticas del jugador id
      \pre sg >= 0  sp >= 0  jg >= 0  jp >= 0 y el jugador id existe
      \post Se pasan los datos del partido al jugador para actualizar sus estadísticas
  */
  void resultado_partido(const string &id, bool ganado, int sg, int sp, int jg, int jp);


  //Lectura
  /** @brief Lee el número de jugadores del circuito
      \pre Estan preparados el canal estándar de entrada un entero P >= 0 que indica el 
      número de jugadores, y P nombres sin repeticiones para cada jugador
      \post El parámetro implícito contiene el conjunto de jugadores leidos del canal
       estándar de entrada
  */
  void leer();

  //Imprimir
  /** @brief Imprime el la posición en el ranking, el nombre y los puntos de cada jugador
      \pre <em>Cierto</em>
      \post Se han escrito por el canal estandar de salida la posición en el ranking, los nombres de
      los jugadores y sus puntos
  */
  void imprimir_ranking() const;

  /** @brief Imprime los nombres de los jugadores, su posición en el ranking, sus puntos y sus estadísticas
      \pre <em>cierto</em>
      \post Se han escrito por el canal estandar de salida los nombres de los jugadores,
       su posición en el ranking, sus puntos y sus estadísticas
  */
  void imprimir_lista_jugadores() const;


  /** @brief Imprime las estadísticas del jugador
      \pre El jugador id existe
      \post Se han escrito por el canal estandar de salida el nombre del jugador,
       su posición en el ranking, sus puntos y sus estadísticas
  */
  void estadisticas_jugador(const string &id) const;


  /** @brief Suma los puntos al jugador del torneo que ha disputado
      \pre El jugador (first) existe y puntos (second) >= 0
      \post Se ha sumado los puntos al jugador 
  */
  void sumar_puntos_torneo(pair<string,int> j);
  
 };
 #endif