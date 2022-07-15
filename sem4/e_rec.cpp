#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define MAX 
#define inf 0x3f3f3f3f3f3f3f3f 

int n, k, c;

ll solve(int i, int p, ll d[], int end){
    // cout << i << endl;
    if(i >= end && p >= 1) return inf;
    if(p == 0) return 0;
    ll choose = 0, skip = 0;
    choose = solve(i+c, p-1, d, end) + d[i]; 
    skip = solve(i+1, p, d, end);
    return min(choose, skip);
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
    // for(int i = 0; i < n-c+1; ++i){
    //     cout << d[i] << endl;
    // }
    ll ans = solve(0, k, d, n-c+1);
    ans = (ans == inf? 0 : s - ans);
    cout << ans << endl;
}
