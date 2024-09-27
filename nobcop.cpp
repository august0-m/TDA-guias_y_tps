#include <iostream>
#include <vector>
using namespace std;

int T, N;
vector<vector<int>> p;

int max_subsecuencia_creciente(int i, vector<int>& caso, int ult, vector<vector<int>>& sec_cre) {
    if (i >= caso.size()) return 0;

    if (ult == -1 && sec_cre[i][caso.size()] != -1) return sec_cre[i][caso.size()];
    if (ult != -1 && sec_cre[i][ult] != -1) return sec_cre[i][ult];

    int ult_alto = (ult == -1) ? 0 : caso[ult];

    if (ult_alto >= caso[i]) return max_subsecuencia_creciente(i + 1, caso, ult, sec_cre);

    int segundo_index = (ult == -1) ? caso.size() : ult;

    sec_cre[i][segundo_index] = max(max_subsecuencia_creciente(i + 1, caso, ult, sec_cre),
                                    max_subsecuencia_creciente(i + 1, caso, i, sec_cre) + 1);
    return sec_cre[i][segundo_index];
}

int max_subsecuencia_decreciente(int i, vector<int>& caso, int ult, vector<vector<int>>& sec_dec) {
    if (i >= caso.size()) return 0;

    if (ult == -1 && sec_dec[i][caso.size()] != -1) return sec_dec[i][caso.size()];
    if (ult != -1 && sec_dec[i][ult] != -1) return sec_dec[i][ult];

    int ult_alto = (ult == -1) ? 1000000 : caso[ult];

    if (ult_alto <= caso[i]) return max_subsecuencia_decreciente(i + 1, caso, ult, sec_dec);

    int segundo_index = (ult == -1) ? caso.size() : ult;

    sec_dec[i][segundo_index] = max(max_subsecuencia_decreciente(i + 1, caso, ult, sec_dec),
                                    max_subsecuencia_decreciente(i + 1, caso, i, sec_dec) + 1);
    return sec_dec[i][segundo_index];
}

int main() {
    int contador = 0;
    while (true) {
        cin >> T;
        if (T == -1) break;
        p.push_back(vector<int>(T));
        for (int i = 0; i < T; i++) {
            cin >> p[contador][i];
        }
        contador++;
    }

    for (int j = 0; j < p.size(); j++) {
        int a = p[j].size();
        vector<vector<int>> sec_cre(a, vector<int>(a + 1, -1));
        vector<vector<int>> sec_dec(a, vector<int>(a + 1, -1));

        int result = p[j].size() - (max_subsecuencia_creciente(0, p[j], -1, sec_cre) +
                                    max_subsecuencia_decreciente(0, p[j], -1, sec_dec));
        cout << result << endl;
    }
    return 0;
}
