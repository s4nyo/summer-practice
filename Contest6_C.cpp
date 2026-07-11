#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n, m, s, f;
    cin >> n >> m >> s >> f;
    --s; --f;
 
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    vector<ll> pw(n, -1);
    vector<char> used(n, 0);
    used[s] = 1;
 
    auto dfs = [&](auto&& dfs, ll u)->void {
        for (ll v : g[u]) {
            if (!used[v]) {
                used[v] = 1;
                pw[v] = u;
                dfs(dfs, v);
            }
        }
    };
 
    dfs(dfs, s);
 
    if (!used[f]) {
        cout << -1 << '\n';
        return 0;
    }
 
    vector<ll> way;
    ll cur = f;
    while (cur != -1) {
        way.push_back(cur + 1);
        if (cur == s) break;
        cur = pw[cur];
    }
    reverse(way.begin(), way.end());
 
    for (size_t i = 0; i < way.size(); ++i) {
        if (i) cout << ' ';
        cout << way[i];
    }
    cout << '\n';
 
    return 0;
}