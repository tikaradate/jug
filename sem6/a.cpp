#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define MAX 112345

vector<vector<int>> g(MAX);
bool visited[MAX];

int dfs(int u) {
    visited[u] = true;
    int c = 1;
    for (int v : g[u]) if (!visited[v])
        c += dfs(v);
    return c;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ll ans = 0;
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            ++ans;
            dfs(i);
        }
    }

    cout << ans << endl; 
}