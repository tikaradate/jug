#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    int n; cin >> n;
    vector<ll> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
    vector<ll> ps(n+1);
    ps[0] = 0;
    for(int i = 1; i <= n; ++i){
        ps[i] = s[i-1] + ps[i-1];
    }
    int m; cin >> m;
    for(int i = 0; i < m; ++i){
        int a; cin >> a;
        auto pos = lower_bound(ps.begin(), ps.end(), a);
        cout << pos-ps.begin() << endl;
    }
}