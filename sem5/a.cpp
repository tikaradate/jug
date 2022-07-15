#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 10e5;

vector<int>t[4*N];

// void build(vector<int>& src, int ti=1, int tl=1, int tr=N) {
//     if (tl == tr) {
//             t[ti] = vector<int>(1, src[tl]);
//     } else { 
//         int tm = (tl + tr) / 2;
//         build(src, ti*2, tl, tm);
//         build(src, ti*2+1, tm+1, tr);
//         merge(t[ti*2].begin(), t[ti*2].end(), t[ti*2+1].begin(), t[ti*2+1].end(),
//               back_inserter(t[ti]));
//     }
// }

// int query(int l, int r, int x, int ti=1, int tl=1, int tr=N) {
//     if (l > r)
//         return INF;
//     if (l == tl && r == tr) {
//         vector<int>::iterator pos = lower_bound(t[ti].begin(), t[ti].end(), x);
//         if (pos != t[ti].end())
//             return *pos;
//         cout << "hm" << endl;
//         return INF;
//     }
//     int tm = (tl + tr) / 2;
//     return query(l, r, x, ti*2, tl, tm) + query(l, r, x, ti*2+1, tm+1, tr);
// }

void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = vector<int>(1, a[tl]);
    } else { 
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),
              back_inserter(t[v]));
    }
}
int query(int l, int r, int x, int v, int tl, int tr) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        vector<int>::iterator pos = upper_bound(t[v].begin(), t[v].end(), x);
        if (pos != t[v].end()){
            return t[v].end() - pos;
        }
        return 0;
    }
    int tm = (tl + tr) / 2;
    return query(l, min(r, tm), x, v*2, tl, tm) + query(max(l, tm+1), r, x, v*2+1, tm+1, tr);
}
int main(){
    int n, h; cin >> n >> h;
    vector<int> p(N);
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
    }
    build(p, 1, 0, n);
    ll ans = 0;
    for(int i = h+1; i <= n; ++i){
        ans += query(1, i, p[i], 1, 1, n);
    }
    cout << ans << endl;
}
