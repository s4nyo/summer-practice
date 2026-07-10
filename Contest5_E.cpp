#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll M = 1e9 + 7;

ll inverse(ll x){
    ll ans = 1;
    ll p = M - 2;
    while (p){
        if (p & 1){
            ans = ans * x % M;
        }
        x = x * x % M;
        p /= 2;
    }
    return ans;
}
 
ll bpow(ll x, ll p){
    ll ans = 1;
    while (p){
        if (p & 1){
            ans = ans * x % M;
        }
        x = x * x % M;
        p /= 2;
    }
    return ans;
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t, b1, q, n;
    cin >> t;
    
    for (ll i = 0; i < t; ++i){
        cin >> b1 >> q >> n;
        
        if (n == 0 || b1 == 0) {
            cout << 0 << '\n';
            continue;
        }
 
        if (q == 1) {
            cout << (b1 % M) * (n % M) % M << '\n';
            continue;
        }
    
        ll S = (b1 % M) * ((bpow(q, n) - 1 + M) % M) % M;
        S = S * inverse((q - 1 + M) % M) % M;
        cout << S << "\n";
    }
    return 0;
}