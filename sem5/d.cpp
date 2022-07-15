#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e5 + 15;

vector<int> bit (N, 0);
void add(int i, int delta) {
    for (; i < N; i += i & (-i))
       bit[i] += delta;
}
int get(int i) {
    int ans = 0;
    for (; i > 0; i -= i & (-i))
        ans += bit[i];
    return ans;
}


int main(){
    int n; cin >> n;
    for(int i = 1; i <=n; ++i){
        char c; cin >> c;
        add(i, c - '0'); 
    }
    int q; cin >> q;
    while(q--){
        int op; cin >> op;
        switch(op){
            case 1:{
                int a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2;
                int d; cin >> d;
                int op1 = (get(b1) - get(a1-1)) % 9;
                int op2 = (get(b2) - get(a2-1)) % 9;
                cout << ((op1 + op2) % 9 == d? "YES" : "NO") << endl;
                break;
            }
            case 2:{
                int a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2;
                int d; cin >> d;
                int op1 = (get(b1) - get(a1-1)) % 9;
                int op2 = (get(b2) - get(a2-1)) % 9;
                cout << ((op1 * op2) % 9 == d? "YES" : "NO") << endl;
                break;
            }
            case 3:{
                int p, d; cin >> p >> d;
                int old = get(p) - get(p-1);
                add(p, d - old);
                break;
            }
        }
    }
}