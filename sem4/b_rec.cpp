#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int c[5] = {1, 5 ,10, 25, 50};

ll count(int c[], int n_c, int value){
    int ans = 0;
    if(value == 0)
        return 1;
    if(value < 0)
        return 0;
    if(n_c < 0 && value > 0) 
        return 0;

    return count(c, n_c-1, value) + count(c, n_c, value-c[n_c - 1]);
}

int main(){
    int n;
    while(cin >> n){
        cout << count(c, 5, n) << endl;
    }
}