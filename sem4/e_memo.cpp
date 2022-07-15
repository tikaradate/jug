#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define MAX 11234
#define inf 0x3f3f3f3f

int n, k, c;
int dp[MAX][MAX];

ll solve(int i, int p, ll d[], int end){
    if(p == 0) return dp[i][p] = 0;
    if(i >= end || (end - i < (p-1)*c+1)) return inf;
    if(dp[i][p] == inf){
        ll choose = 0, skip = 0;
        skip = solve(i+1, p, d, end);
        choose = solve(i+c, p-1, d, end) + d[i];
        dp[i][p] = min(choose, skip);
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
    ll d[n] = {};
    for(int i = 0; i < c; ++i){
        d[0] += v[i];
    }
    for(int i = 1; i < n-c+1; ++i){
        d[i] = d[i-1] - v[i-1] + v[i+c-1];
    }
    memset(dp, 0x3f, sizeof(dp));
    ll ans = solve(0, k, d, n-c+1);
    ans = (ans == inf? 0 : s - ans);
    cout << ans << endl;
    // for(int i = n-c+1; i >= 0; --i){
    //     for(int j = 1; j <= k; ++j){
    //         cout << dp[i][j] << ' ';
            
    //     }
    //     cout << endl;
    // }
}
