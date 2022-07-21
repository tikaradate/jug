#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define MAX 11234
#define oo 0x3f3f3f3f3f3f3f3f

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, m, q; cin >> n >> m;
    map<string, int> si;
    map<int, string> is;
    vector<pair<string, string>> names(m);
    vector<vector<ll>> d (n, vector<ll>(n, oo));
    vector<vector<ll>> next (n, vector<ll>(n, 0));
    int id = 0;
    for(int i = 0; i < m; ++i){
        string u, v; cin >> u >> v;
        if(si.find(u) == si.end()){ si[u] = id; is[id++] = u;}
        if(si.find(v) == si.end()){ si[v] = id; is[id++] = v;}
        names[i] = make_pair(u, v);
        d[si[u]][si[v]] = 1;
        next[si[u]][si[v]] = si[v];
    }
    for (int u = 0; u < n; u++){
        d[u][u] = 0;
        next[u][u] = u;
    }
    for (int m = 0; m < n; m++)
    for (int u = 0; u < n; u++)
    for (int v = 0; v < n; v++)
        if(d[u][v] > d[u][m] + d[m][v]){
            d[u][v] = d[u][m] + d[m][v];
            next[u][v] = next[u][m];
        }

    double ans = 0, k = 0;
    vector<tuple<int, string, string>> paths;
    for (int u = 0; u < n; u++)
    for (int v = 0; v < n; v++){
        if(d[u][v] != oo && d[u][v] != 0){
            ans += d[u][v] ;
            paths.push_back(make_tuple(d[u][v], is[u], is[v]));
            ++k;
        }
    }
    sort(paths.begin(), paths.end());
    cout << ans/k << endl;
    string us = get<1>(paths[ceil(k/2) - 1]);
    string vs = get<2>(paths[ceil(k/2) - 1]);
    int u = si[us];
    int v = si[vs];
    cout << us << ' ';
    while(u != v){
        u = next[u][v];
        cout << is[u] << ' ';

    }
    cout << endl;
}