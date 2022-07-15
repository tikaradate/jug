#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 10e5;
#define NEUTRAL 0
#define OP(X, Y) (X + Y)

int sign(int a){
    if(a < 0) return 1;
    if(a > 0) return 2;
    return 0;
}

int signsum(int a, int b){
    if(a == 0 || b == 0) return 0;
    return OP(a, b);
}

vector<int> t (4*N);
int op_inclusive(int l, int r, int ti=1, int tl=1, int tr=N) {
    if (l > r) { return 2; }
    if (l == tl && r == tr) { return t[ti]; }
    int tm = (tl + tr) / 2;
    return signsum(op_inclusive(l, min(r, tm), ti*2, tl, tm),
    op_inclusive(max(l, tm+1), r, ti*2+1, tm+1, tr));
}

void set_value(int i, int v, int ti=1, int tl=1, int tr=N) {
    if (tl == tr) { t[ti] = v; return; }
    int tm = (tl + tr) / 2;
    if (i <= tm)
        set_value(i, v, ti*2, tl, tm);
    else
        set_value(i, v, ti*2+1, tm+1, tr);
    t[ti] = signsum(t[ti*2], t[ti*2+1]);
}

void build(vector<int>& src, int ti=1, int tl=1, int tr=N) {
    if (tl == tr) {
        if (tl < src.size()) { t[ti] = src[tl]; }
        return;
    }
    int tm = (tl + tr) / 2;
    build(src, ti*2, tl, tm);
    build(src, ti*2+1, tm+1, tr);
    t[ti] = signsum(t[ti*2], t[ti*2+1]);
}

int main(){
    int n, k; cin >> n >> k;
    vector<int> v(n+1);
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
        v[i] = sign(v[i]);
    }
    build(v);
    for(int i = 0; i < k; ++i){
        char c; int l, y; 
        cin >> c >> l >> y;
        
        if(c == 'A'){
            set_value(l, sign(y));
        } else {
            ll prod = op_inclusive(l, y);
            if(prod == 0) cout << 0;
            else if(prod % 2 == 1) cout << "-";
            else cout << "+";
            
        }
    }
    cout << endl;
}