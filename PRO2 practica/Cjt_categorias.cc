/** @file Cjt_categorias.cc
    @brief Código de la clase Cjt_categorias
*/

#include "Cjt_categorias.hh"

Cjt_categorias::Cjt_categorias()
{
}

int Cjt_categorias::num_categorias() const
{
    return nc.size();

}

void Cjt_categorias::leer()
{
    int C;
    int K;
    cin >> C >> K;
    tabla = vector<vector<int>>(C,vector<int>(K));
    for ( int i = 0; i < C; ++i){
        string name;
        cin >> name;
        nc.push_back(name);
    }
    int num_filas = tabla.size();
    int num_cols = tabla[0].size();
    for(int fila = 0; fila < num_filas; ++fila){
        for ( int col = 0; col < num_cols; ++col){
            cin >> tabla[fila][col];
        }
    }
}


void Cjt_categorias::imprimir_categorias() const
{
    int num_filas = tabla.size();
    int num_cols = tabla[0].size();
    cout << num_filas << ' ' << num_cols << endl;
    for ( int i = 0; i < num_filas; ++i){
        cout << nc[i] << ' ';
        for ( int j = 0; j < num_cols; ++j){
            cout << tabla[i][j];
            if ( j != num_cols - 1 )  cout << ' ';
        }
        cout << endl;
    }   
}

void Cjt_categorias::categoria_nombre(int id) const
{
    cout << nc[id-1] << endl;
}

int Cjt_categorias::obtener_puntos(int c, int k) const
{
    return tabla[c - 1][k - 1];
}