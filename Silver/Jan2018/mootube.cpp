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

void setIO(string name = "mootube") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll n, q, k;
vector<vector<pair<ll, ll>>> arr;
vector<ll> ans;
vector<bool> visited;

int dfs(ll node) {
    visited[node] = true;
    int count = 0;
    for (pair<ll, ll> &neighbor : arr[node]) {
        if (!visited[neighbor.first]) {
            if (neighbor.second >= k) {
                ++count;
                count += dfs(neighbor.first);
            }
        }
    }
    return count;
}

int main() {
    setIO();
    cin >> n >> q;
    arr.resize(n);
    rep(i, 0, n - 1) {
        ll p, q, r; cin >> p >> q >> r;
        --p; --q;
        arr[p].push_back({ q, r });
        arr[q].push_back({ p, r });
    }
    rep(i, 0, q) {
        ll k1, v; cin >> k1 >> v;
        --v;
        k = k1;
        visited.clear();
        visited.resize(n, false);
        cout << dfs(v) << endl;
    }
}
