#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define MAX 11234
#define inf 0x3f3f3f3f

int n, k, c;
int dp[MAX][MAX];

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

    for(int i = n-c+1; i >= 0; --i){
        for(int j = 1; j <= k; ++j){
            if(j == 0) dp[i][j] = 0;
            else if(i >= n-c+1 || (n-c+1 - i < (j-1)*c+1)) dp[i][j] = inf;
            else{
                ll choose = 0, skip = 0;
                skip = dp[i+1][j];
                choose = dp[i+c][j-1] + d[i];
                dp[i][j] = min(skip, choose);
            }
        }
    }
    cout << s - dp[0][k] << endl;
}
