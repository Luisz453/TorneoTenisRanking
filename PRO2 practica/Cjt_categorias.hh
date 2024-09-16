/** @file Cjt_categorias.hh
    @brief Especificación de la clase Cjt_categorias
*/

#ifndef _CJT_CATEGORIAS_HH_
#define _CJT_CATEGORIAS_HH_

#ifndef NO_DIAGRAM

#include <vector>
#include <string>
#include<iostream>
using namespace std;
#endif

/** @class Cjt_categorias
    @brief Representa el conjunto de categorias. 

    Contiene todas las categorias del circuito, y los puntos que obtiene cada jugador dependiendo el nivel en el quede y la categoria en la que juegue
*/
 
class Cjt_categorias
 {
private:

  /** @brief Tabla de puntos con C (número de categorias) filas y K (número de niveles) columnas*/
  vector<vector<int>> tabla;

  /** @brief Nombres de todas las categorías*/
  vector<string> nc; 

public:

  //Constructoras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar el conjunto de categorias.
      \pre <em>Cierto</em>
      \post El resultado es un conjunto de categorias y el puntaje
  */  
   Cjt_categorias();

  //Consultoras

  /** @brief Indica el número de categorias que existen
      \pre <em>Cierto</em>
      \post El resultado indica el número de categorías
  */
  int num_categorias() const;

  //Lectura
  /** @brief Lee el número de categorías y sus respectivos nombres, el máximo de niveles  y la tabla de puntos 
      \pre Estan preparados el canal estándar de entrada un entero K >= 4 que indica el máximo de niveles,
       y otro entero C >= 1 que indica el número de categorías que leeremos
      \post El parámetro implícito contiene el conjunto de categorías leidas del canal
       estándar de entrada y la tabla de puntos
  */
  void leer();

  //Imprimir
  /** @brief Imprime los nombres de categorías y 
      \pre <em>Cierto</em>
      \post Se han escrito por el canal estandar de salida los nombres de los jugadores,
       su posición en el ranking, sus puntos y sus estadísticas
  */
  void imprimir_categorias() const;

  /** @brief Imprime la categoría id
      \pre id esta entre 1 y C
      \post Se imprime la categoría id del circuito
  */
  void categoria_nombre(int id) const;

  /** @brief Obtiene la puntuación de la tabla segun el nivel y la categoría
      \pre c >= 1, k >= 1
      \post Se obtiene una puntuación de la tabla segn el nivel y la categoría
  */
  int obtener_puntos(int c, int k) const;
  
 };
 #endif