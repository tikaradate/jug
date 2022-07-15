#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    int c; cin >> c;
    ll ans = 0;
    while(c--){
        int x; cin >> x;
        if(x > 10){
            ans += x - 10;
        }
    }
    cout << ans << endl;
}