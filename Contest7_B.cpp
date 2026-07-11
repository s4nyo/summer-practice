#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<pair<int, ll>>> g(n);
    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].push_back({v, w});
    }
 
    vector<ll> dist(n, inf);
    vector<ll> parent(n, -1);
 
    dist[0] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0});
 
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
 
        if (d != dist[u]) continue;
 
        for (auto [v, w] : g[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
 
    if (dist[n - 1] == inf) {
        cout << -1 << '\n';
    }
    else {
        vector<int> way;
        for (int v = n - 1; v != -1; v = parent[v]) {
            way.push_back(v + 1);
        }
        reverse(way.begin(), way.end());
        for (size_t i = 0; i < way.size(); ++i) {
            if (i) cout << ' ';
            cout << way[i];
        }
        cout << '\n';
    }
 
    return 0;
}