#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T, N, C;
vector<vector<int>> p;


void funcionarda(vector<vector<int>> v){
            
}

//leo los inputs y los ordeno en vectores
int main (){

    cin >> T;
    p.resize(T);

    for (int i=0; i<T; i++){
    cin >> N >> C ;
     p[i].resize(N);
     for (int j=0;j<N;j++){
         cin >> p[i][j];
     }
    sort(p[i].begin(),p[i].end());
    }
    //for (int i = 0; i < T; i++) {
    //    cout << "Caso " << i + 1 << ": ";
    //    for (int j = 0; j < p[i].size(); j++) {
    //        cout << p[i][j] << " ";  // Imprime cada elemento del vector
    //    }
    //    cout << endl;  // Nueva línea después de cada caso
    //}
    return 0;
}