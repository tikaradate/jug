#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int c[5] = {1, 5, 10, 25, 50};

int main(){
    int n;
    ll dp[30001] = {};
    dp[0] = 1;
    for(int j = 0; j < 5; ++j){
        for(int i = c[j]; i < 30001; ++i){
            dp[i] += dp[i-c[j]];
        }
    }
    while(cin >> n){
        cout << dp[n] << endl;
    }
}