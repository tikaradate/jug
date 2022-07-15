#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define N 1e5+15

vector<ll> bit (N, 0);
void add(ll i, ll delta) {
    for (; i < N; i += i & (-i))
        bit[i] += delta;
}

ll get(ll i) {
    ll ans = 0;
    for (; i > 0; i -= i & (-i))
        ans += bit[i];
    return ans;
}

ll next_pos(ll v, ll  n) {
    ll pos = 0;
    ll i = 0;
 
    while (1 << (i + 1) <= n)
        i++;
 
    while (i >= 0) {
        ll next_index = pos + (1 << i);
        if (next_index <= n && bit[next_index] < v) {
            pos = next_index;
            v -= bit[pos];
        }
        i--;
    }
    return pos + 1;
}
int main(){
    ll n, q; cin >> n >> q;
    vector<ll> tape(n+1);
    for(ll i = 1; i <= n; ++i){
        cin >> tape[i];
        add(i, 1);
    }
    ll pos = 1, qt = n;
    while(q--){
        char c; cin >> c;
        if(c =='q'){
            cout << tape[next_pos(pos, n)] << endl;
        } else if (c == 'd'){
            add(next_pos(pos, n), -1);
        } else {
            ll d; cin >> d;
            pos = next_pos(pos + d, n);
        }
    }
}