#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
 
    sort(a.begin(), a.end(), [](auto &p, auto &q) {
        if (p.first != q.first) return p.first > q.first;
        return p.second < q.second;
    });
 
    set<int> s;
    s.insert(-1);
    s.insert(n);
 
    ll summ = 0;
    for (auto [val, i] : a) {
        auto itR = s.upper_bound(i);
        int R = *itR;
        int L = *prev(itR);
        summ += 1LL * val * (i - L) * (R - i);
        s.insert(i);
    }
 
    cout << summ << '\n';
    return 0;
}