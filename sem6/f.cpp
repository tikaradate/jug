#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using ii = pair<int, int>;

#define MAX 1123

int lin[] = {-1,  0, 1, 0, -1,  1, -1, 1};
int col[] = { 0, -1, 0, 1, -1, -1,  1, 1};
int f[MAX][MAX];
bool visited[MAX][MAX];

bool ok(int x, int y, int n, int m){
    return!(x < 0 || y < 0 || x >= n || y >= m);
}

int bfs(vector<ii> v, int n, int m, int t) {
    int c = 0;
    queue<pair<ii, int>> q;
    for(int i = 0; i < v.size(); ++i){
        q.push(make_pair(v[i], 0));
        visited[v[i].first][v[i].second] = true;
    }
    
    while (!q.empty()) {
        pair<ii, int> u = q.front(); q.pop();
        if(u.second >= t) continue;
        int x = u.first.first;
        int y = u.first.second;
        bool b = (f[x][y] == 0);
        for(int i = 0; i < 4 + 4*b; ++i){
            int ax = x + lin[i];
            int ay = y + col[i];
            if(ok(ax, ay, n, m)){
                if(i >= 4){
                    if (f[ax][ay] == 1){ 
                        f[ax][ay] = 0;
                    }
                } else {
                    if(f[ax][ay] != 5){
                        if(f[ax][ay] == 2) f[ax][ay] = 0;
                        f[ax][ay] = (f[ax][ay] - 1 <= 0? 0 : f[ax][ay] - 1);
                    }
                }
                if(!visited[ax][ay]){
                    if(f[ax][ay] == 0 ){
                        c++;
                        q.push(make_pair(make_pair(ax, ay), u.second+1));
                        visited[ax][ay] = true;
                    }
                }
            }
        }
    }
    return c + v.size();
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m, t; cin >> n >> m >> t;
    
    vector<ii> s;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int aux; cin >> aux;
            f[i][j] = aux;
            if(aux == 0) s.push_back(make_pair(i, j));
        }
    }
    cout << bfs(s, n, m, t) << endl;
}