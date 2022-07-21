#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define oo 0x3f3f3f3f3f3f3f3f

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m, c, k; cin >> n >> m >> c >> k;
    vector<vector<ll>> d (n, vector<ll>(n, oo));
    vector<vector<ll>> next (n, vector<ll>(n, 0));
    while (m--) { 
        int u, v, w; cin >> u >> v >> w;
        if(u < c){
            // both inside restricted path
            if(v < c){
                // not sequential
                if(u != v-1 && v != u-1) continue;
                // goes from smaller to bigger
                if(u < v) d[u][v] = w;
                else d[v][u] = w;
            }
            // goes from outside restriction to inside
            else d[v][u] = w;
        } else {
            // goes from outside restriction to inside
            if(v < c) d[u][v] = w;
            // no restriction
            else {
                d[u][v] = w; 
                d[v][u] = w;
            }
        }
    }

    for (int u = 0; u < n; u++){
        d[u][u] = 0;
    }
    for (int m = 0; m < n; m++)
    for (int u = 0; u < n; u++)
    for (int v = 0; v < n; v++)
        if(d[u][v] > d[u][m] + d[m][v]){
            d[u][v] = d[u][m] + d[m][v];
        }

    cout << d[k][c-1] << endl;
}