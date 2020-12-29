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

void setIO(string name = "moocast") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll n;
vector<pair<ll, ll>> locs;
vector<vector<ll>> vl;
ll dist;
vector<bool> visited;

void dfs(ll node) {
    visited[node] = true;
    for (ll neighbor : vl[node]) {
        if (!visited[neighbor])
            dfs(neighbor);
    }
}

bool check(ll x) {
    dist = x;
    vl.clear();
    vl.resize(n);
    rep(i, 0, n) {
        rep(j, 0, n) {
            ll xdist = locs[i].first - locs[j].first;
            ll ydist = locs[i].second - locs[j].second;
            if (xdist * xdist + ydist * ydist <= x)
                vl[i].push_back(j);
        }
    }
    rep(i, 0, n) {
        visited.clear();
        visited.resize(n, false);
        dfs(i);
        rep(j, 0, n) {
            if (!visited[j])
                return false;
        }
    }
    return true;
}

int main() {
    setIO();
    cin >> n;
    locs.resize(n);
    rep(i, 0, n) {
        ll x, y; cin >> x >> y;
        locs[i] = { x, y };
    }
    sort(all(locs));
    ll l = 0, r = 1;
    while (!check(r)) r *= 2;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
}
