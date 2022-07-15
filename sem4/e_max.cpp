#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define MAX 11234
#define inf 0x3f3f3f3f

int n, k, c;
int dp[MAX][MAX];

ll solve(int i, int p, ll d[], int end){
    if(p == 0) return dp[i][p] = 0;
    if(i >= end || (end - i < (p-1)*c+1)) return -inf;
    ll choose = 0, skip = 0;
    if(dp[i][p] == 0){
        skip = solve(i+1, p, d, end) + 0;
        choose = solve(i+c, p-1, d, end) + d[i]; 
        dp[i][p] = max(choose, skip);
    }
    return dp[i][p];
}

int main(){
    cin >> n >> k >> c;
    int v[n];
    ll s = 0;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
        s += v[i];
    }
    ll d[n-c+1] = {};
    // array de somas de tamanho c
    for(int i = 0; i < c; ++i){
        d[0] += v[i];
    }
    for(int i = 1; i < n-c+1; ++i){
        d[i] = d[i-1] - v[i-1] + v[i+c-1];
    }

    for(int i = 0; i < n-c+1; ++i){
        d[i] = -d[i] + 21234;
    }
    /***************************/
    ll ans = solve(0, k, d, n-c+1);
    ans = -ans + 21234*k;
    ans = (ans == 0? 0 : s - ans);
    cout << ans << endl;
}
