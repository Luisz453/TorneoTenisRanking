/** @file Cjt_torneos.hh
    @brief Especificación de la clase Cjt_torneos
*/

#ifndef _CJT_TORNEOS_HH_
#define _CJT_TORNEOS_HH_
#include "Torneo.hh"
#include "Cjt_categorias.hh"
#include "Cjt_jugadores.hh"

#ifndef NO_DIAGRAM
#include <map>
using namespace std;
#endif

/** @class Cjt_torneos
    @brief Representa el conjunto de torneos y sus operaciones. 

    Contiene todos los torneos del circuito que pueden disputar los tenistas, el número de torneos que puede haber es >= 0 
*/
 
class Cjt_torneos
 {
private:
  /** @brief Conjunto de todos los Torneos ordenados alfabéticament*/
  map<string,Torneo> ct;

public:
  //Constructoras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar el conjunto de torneos.
      \pre <em>Cierto</em>
      \post El resultado es un conjunto de torneos vacío
  */  
   Cjt_torneos();

  //Modificadoras
  /** @brief Añade un nuevo torneo al conjunto de torneos
      \pre El parámetro implícito no contiene ningún torneo id,
       y 1 <= num_cat <= C
      \post Se ha añadido el torneo con nombre id y categoría num_cat al parametre implícito
  */
  void nuevo_torneo(const string &id, int num_cat);

  /** @brief Elimina un torneo del conjunto de torneos
      \pre El parámetro implícito contiene un torneo id
      \post Se ha eliminado el torneo con nombre id y modificado los puntos del ranking de los jugadores
  */
  void eliminar_torneo(const string &id, Cjt_jugadores& jug);

  //Consultoras

  /** @brief Comprueba si existe un torneo con el id como nombre
      \pre <em>Cierto</em>
      \post El resultado indica si existe un torneo en el parametro implícito con el id como nombre
  */
  bool existe(const string &id) const;

  /** @brief Indica el número de torneos del circuito 
      \pre <em>Cierto</em>
      \post El resultado indica el número de torneos del parametro implícito 
  */
  int num_torneos() const;

  //Inicilización torneo

  /** @brief Inicializa el torneo id 
      \pre Torneo id perenece al conjunto de torneos y 8 <= num_jugadores <= 2^(K - 1)
      \post Se inicia el Torneo id respectivo con num_jugadores participantes 
  */
  void iniciar_torneo (const string &id, const Cjt_jugadores &jug);

  //Resultados torneo

  /** @brief Finaliza el torneo 
      \pre Torneo id existe
      \post Se obtienen los resultados del Torneo id, se actualiza el ranking de jugadores y sus estadísticas
  */
  void finalizar_torneo (const string &id, Cjt_jugadores& jug, const Cjt_categorias& cat);

 //Lectura
 /** @brief Lee el número de torneos, sus respectivos nombres y su categoría
     \pre Estan preparados el canal estándar de entrada un entero T >= 0que indica
       el número de torneos, T enteros ( entre 1 y el número de categorías ) que indican 
      la categoría a la que pertenece cada uno y T nombres para designar a cada uno  
     \post El parámetro implícito contiene el conjunto de torenos leidos del canal
       estándar de entrada 
  */ 
  void leer();

  //Imprimir
  /** @brief Imprime los nombres de los torneos y la categoría de cada torneo
      \pre <em>cierto</em>
      \post Se han escrito por el canal estandar de salida los nombres de los torneos y sus categorías
  */
  void imprimir_lista_torneos(const Cjt_categorias &cat);

  /** @brief Recorre la lista de inscritos de todos los torneos para actualizarlas cuando eliminamos un jugador
      \pre El jugador nj existe
      \post Se ha puesto a 0 los puntos del jugador nj de las lista de inscritos anteriores
  */
  void lista_inscritos(const string &nj);
 };
 #endif