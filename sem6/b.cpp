#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define N 11234
#define oo 0x3f3f3f3f

struct edge { int u, v, w; };
vector<edge> edges;
vector<int> d (N, oo);
int bellman_ford(int src, int dest, int n) {
    d[src] = 0;
    for (int i = 0; i < n - 1; i++)
    for (auto e : edges)
        if (d[e.u] != oo && d[e.v] > d[e.u] + e.w)
            d[e.v] = d[e.u] + e.w;
    // Verificação de ciclos negativos
    for (auto e : edges)
        if (d[e.u] != oo && d[e.v] > d[e.u] + e.w)
            return -oo;
    return d[dest];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int l[n+1];
    for(int i = 1; i <= n; ++i){
        cin >> l[i];
    }
    int m; cin >> m;
    for(int i = 0; i < m; ++i){
        int o, d; cin >> o >> d;
        edge aux = {.u = o, .v = d, .w = l[d] - l[o]};
        edges.push_back(aux);
    }
    int q; cin >> q;
    bellman_ford(1, 1, n);
    while(q--){
        int a; cin >> a;
        if(d[a] < 3 || d[a] == oo) cout << "Não, Edsger..." << endl;
        else cout << d[a] << endl;
    }
}