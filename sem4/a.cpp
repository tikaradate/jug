#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    int t; cin >> t;
    while(t--){
        int p, h, f, d, c;
        cin >> p >> h >> f >> d >> c;
        p = p/2;
        int n_max, n_min, max_c, min_c;
        if(d > c){
            n_max = h;
            n_min = f;
            max_c = d;
            min_c = c;
        } else {
            n_max = f;
            n_min = h;
            max_c = c;
            min_c = d;
        }
        ll ans = 0;
        while(p > 0 && n_max > 0){
            ans += max_c;
            n_max--;
            p--;
        }
        while(p > 0 && n_min > 0){
            ans += min_c;
            n_min--;
            p--;
        }
        cout << ans << endl;
    }
}