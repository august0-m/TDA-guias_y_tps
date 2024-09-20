#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T; N, C;
vector<int> p;

int main (){

    cin T >> N >> C;

    p.resize(N, 0);
    for (int i=0; i<N; i++) cin >> p[i];
    sort(p.begin(),p.end());
    return 0;
}