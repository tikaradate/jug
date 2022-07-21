#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define MAX 11234
#define oo 0x3f3f3f3f3f3f3f3f

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // floyd warshal?? guarda a menor distância entre cidades ao ler
    int n, m; cin >> n >> m;
    vector<vector<ll>> d (n, vector<ll>(n, oo));
    while (m--) { 
        int u, v, w; cin >> u >> v >> w;
        if(w < d[u][v]){ d[u][v] = w; d[v][u] = w;}
    }
    for (int u = 0; u < n; u++)
        d[u][u] = 0;
    for (int m = 0; m < n; m++)
    for (int u = 0; u < n; u++)
    for (int v = 0; v < n; v++)
        d[u][v] = min(d[u][v], d[u][m] + d[m][v]);
    
    ll ans = oo;
    for (int u = 0; u < n; u++){
        ll local_ans = 0;
        for (int v = 0; v < n; v++){
            if(d[u][v] != oo && d[u][v] != 0)
                local_ans = max(local_ans, d[u][v]);
        }
        ans = min(ans, local_ans);
    }
    cout << ans << endl;
}