#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define M 1000000007
#define MAXN 10001

ll factorial[MAXN];
void precalcfat(){
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % M;
    }
}

ll binpow(ll a, ll b) {
    a %= M;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
ll inverse(ll a){
    return(binpow(a, M-2) % M);
}

ll combination(int n, int k){
    return (factorial[n] * inverse((factorial[k] * factorial[n - k]) % M)) % M;
}

int main(){
    precalcfat();
    int n, c; cin >> n >> c;
    int col[n], num[n];
    for(int i = 0; i < n; ++i){
        cin >> num[i];
        col[i] = n; // number of free lines in the column
    }
    int x, y;
    while(cin >> x >> y){
        --col[y-1];
    }
    ll sum = 1;
    for(int i = 0; i < n; ++i){
        sum *= ((factorial[col[i]] * (combination(num[i], col[i]))));
        sum %= M;
    }
    cout << sum << endl;
}