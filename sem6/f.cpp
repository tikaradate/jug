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

int bfs(vector<ii> v, int n, int m) {
    int c = 0;
    queue<ii> q;
    for(int i = 0; i < v.size(); ++i){
        q.push(v[i]);
        visited[v[i].first][v[i].second] = true;
        cout << v[i].first << ' ' << v[i].second << endl;
    }
    
    while (!q.empty()) {
        ii u = q.front(); q.pop();
        int x = u.first;
        int y = u.second;
        bool b = (f[x][y] == 0);
        for(int i = 0; i < 4 + 4*b; ++i){
            int ax = x + lin[i];
            int ay = y + col[i];
            if(ok(ax, ay, n, m)){
                if(i >= 4){
                    if (f[ax][ay] == 1){ 
                        cout << visited[ax][ay] << endl;
                        f[ax][ay] = 0;
                    }
                } else {
                    if(f[ax][ay] == 2) f[ax][ay] = 0;
                    f[ax][ay] = (f[ax][ay] - 1 <= 0? 0 : f[ax][ay] - 1);
                }
                if(!visited[ax][ay]){
                    if(f[ax][ay] == 0 ){
                        c++;
                        q.push(make_pair(ax, ay));
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
    cout << bfs(s, n, m) << endl;
}