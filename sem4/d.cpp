#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    for(int i = 1; i <= t; ++i){
        int ans = 0;
        string s; cin >> s;
        for(int j = 0; j < s.length();){
            if(s[j] == '_'){ 
                j+=3;
                ++ans;
            } else {
                ++j;
            }
        }
        cout << "Caso " << i << ": " << ans << endl; 
    }
}