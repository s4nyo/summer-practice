#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll l, r;
    cin >> l >> r;
    
    vector<ll> v(r + 1, 0);
    v[1] = 1;
    
    for (ll i = 1; i <= r; ++i) {
        for (ll j = 2 * i; j <= r; j += i) {
            v[j] += v[i];
            v[j] %= MOD;
        }
    }
    
    ll ans = 0;
    for (ll i = l; i <= r; ++i) {
        ans += v[i];
        ans %= MOD;
    }
    
    cout << ans;
}