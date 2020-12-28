#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define rep(i, a, b) for(ll i = a; i < b; ++i)

using pi = pair<int, int>;
#define f first
#define s second

void setIO(string name = "diamond") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();
    ll n, k; cin >> n >> k;
    vector<ll> d(n);
    rep(i, 0, n) {
        cin >> d[i];
    }
    ll ans = 0;
    sort(all(d));
    vector<ll> dist(n);
    rep(i, 0, n) {
        auto it = prev(upper_bound(all(d), d[i] + k), 1);
        ll t = (next(it, 1) - d.begin()) - i;
        dist[i] = t;
    }
    rep(i, 0, n) {
        rep(j, i + dist[i], n) {
            ans = max(ans, dist[i] + dist[j]);
        }
    }
    cout << ans;
}
