#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){ 
    ll a, b, c;
    cin >> a >> b >> c;
    
    ll delta2 = b*b - (4*a*c);
    ll lo = 0, hi = delta2+1;
    while (lo < hi){
        ll mid = lo + (hi-lo)/2;
        if (mid < 1e9 && mid*mid < delta2)
            lo = mid+1;
        else
            hi = mid;
    }    

    cout << (lo*lo == delta2 ? 'Y' : 'N') << endl;
 
    return 0;
}