#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Función para calcular la máxima subsecuencia creciente desde el índice 'i'
int lis(int i, const vector<int>& arr, vector<int>& M_creciente) {
    if (M_creciente[i] != -1) return M_creciente[i];

    int mejor = 1; // El número actual cuenta como subsecuencia de tamaño 1
    for (int j = i + 1; j < arr.size(); j++) {
        if (arr[j] > arr[i]) {
            mejor = max(mejor, 1 + lis(j, arr, M_creciente));
        }
    }
    M_creciente[i] = mejor;
    return mejor;
}

// Función para calcular la máxima subsecuencia decreciente desde el índice 'i'
int lds(int i, const vector<int>& arr, vector<int>& M_decreciente) {
    if (M_decreciente[i] != -1) return M_decreciente[i];

    int mejor = 1; // El número actual cuenta como subsecuencia de tamaño 1
    for (int j = i + 1; j < arr.size(); j++) {
        if (arr[j] < arr[i]) {
            mejor = max(mejor, 1 + lds(j, arr, M_decreciente));
        }
    }
    M_decreciente[i] = mejor;
    return mejor;
}

int main() {
    // Vector de arreglos de números
    vector<vector<int>> arreglos;
    int T;
    // Ejemplo: lee múltiples arreglos de números
    int contador= 0;
    while(true){
    cin >> T;
    if(T==-1)   break;
    arreglos.push_back(vector<int>(T));
    for (int i=0; i<T; i++){
        cin >> arreglos[contador][i];
    }
    contador++;
    }
    // Procesar cada arreglo
    for (int k = 0; k < arreglos.size(); k++) {
        vector<int>& arr = arreglos[k];  // El arreglo actual

        // Inicializar las estructuras de memoización
        vector<int> M_creciente(arr.size(), -1);
        vector<int> M_decreciente(arr.size(), -1);

        int max_lis = 0, max_lds = 0;
        for (int i = 0; i < arr.size(); i++) {
            max_lis = max(max_lis, lis(i, arr, M_creciente));
            max_lds = max(max_lds, lds(i, arr, M_decreciente));
        }

        // Imprimir los resultados para el arreglo actual
        cout << "Arreglo " << k+1 << ": " << endl;
        cout << "Máxima subsecuencia creciente: " << max_lis << endl;
        cout << "Máxima subsecuencia decreciente: " << max_lds << endl;
        cout << endl;
    }

    return 0;
}
