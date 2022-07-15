#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define inf 0x3f3f3f3f
#define MAX 2123

int n, i, m, p;
int c[MAX], v[MAX];
int dp[MAX][MAX], nxt[MAX][MAX];

ll solve(int y, int a){
    if(y == n + 1) return 0;
    if(dp[y][a] == inf){
        ll maintain = inf, next = inf;
    
        next = c[0] + p - v[a] + solve(y+1, 1);
        if(a < m) maintain = c[a] + solve(y+1, a+1);

        if(next <= maintain) nxt[y][a] = 1;
        else nxt[y][a] = a+1;

        dp[y][a] = min(maintain, next);
    }
    return dp[y][a];
}

int main(){
    cin >> n >> i >> m >> p;
    for(int i = 0; i < m; ++i) cin >> c[i];
    for(int i = 1; i <= m; ++i) cin >> v[i];

    memset(dp, 0x3f, sizeof(dp));

    cout << solve(1, i) << endl;

    // int a = i;
    bool found = false;
    for(int y = 1; y <= n; ++y ){
        if(nxt[y][i] == 1) {
            cout << y << " ";
            found = true;    
        }
        i = nxt[y][i];
    }
    if(!found) cout << "0";
    cout << endl;
}