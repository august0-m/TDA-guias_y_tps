#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    while (true) {
        cin >> N;
        if (N == -1) break;

        vector<int> X(N);
        for (int i = 0; i < N; i++) {
            cin >> X[i];
        }

        // dp[i][j] = mínimo sin pintar considerando hasta el i-ésimo elemento
        // con un color blanco (j = 0) o negro (j = 1).
        vector<vector<int>> dp(N + 1, vector<int>(2, N));
        
        dp[0][0] = dp[0][1] = 0; // Sin elementos, sin sin pintar.

        for (int i = 1; i <= N; i++) {
            // Calcular el DP para el caso negro
            for (int j = 0; j < i; j++) {
                if (X[j] < X[i - 1]) {
                    dp[i][1] = min(dp[i][1], dp[j][0]);
                }
            }
            dp[i][1] += 1; // Pintar este elemento de negro
            
            // Calcular el DP para el caso blanco
            for (int j = 0; j < i; j++) {
                if (X[j] > X[i - 1]) {
                    dp[i][0] = min(dp[i][0], dp[j][1]);
                }
            }
            dp[i][0] += 1; // Pintar este elemento de blanco
        }

        // La respuesta es el mínimo entre los dos últimos colores.
        int minUnpainted = min(dp[N][0], dp[N][1]);
        cout << minUnpainted << endl;
    }
    return 0;
}
