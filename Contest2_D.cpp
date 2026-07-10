#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
	ll n, m;
	cin >> n >> m;
	multimap<ll, ll> mp;
	vector<ll> ans;
	
	 for (int i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        mp.insert({x, i});
    }
	
	bool flag = true;
	ll cur = m;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (cur > it -> first){
            cur += it -> first;
            ans.push_back(it -> second);
        }
        else {
            cout << "NO";
            flag = false;
            
        }
    }
    
    if (flag){
        cout << "YES\n";
        for (int i = 0; i < ans.size(); ++i){
            cout << ans[i] << " ";
        }
    }
	
}