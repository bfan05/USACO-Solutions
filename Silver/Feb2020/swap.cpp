#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(ll i = a; i < b; ++i)
#define rsz(x, n) x.resize(n)

using pi = pair<int, int>;
#define f first
#define s second

void setIO(string name = "swap") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll n, m, k;
vector<ll> curr;
vector<ll> succ;
vector<bool> visited;
vector<vector<ll>> cycles;
ll cnt = 0;
vector<ll> codes;

void dfs(ll a) {
    visited[a] = true;
    cycles[cnt].push_back(a);
    codes[a] = cnt;
    if (!visited[succ[a]]) {
        dfs(succ[a]);
    }
}

int main() {
    setIO();
    cin >> n >> m >> k;
    rsz(curr, n);
    rsz(succ, n);
    rsz(visited, n);
    rsz(codes, n);
    rep(i, 0, n) {
        curr[i] = i;
    }
    rep(i, 0, m) {
        ll a, b; cin >> a >> b;
        --a; --b;
        rep(j, a, ((a + b) / 2) + 1) {
            ll c = curr[j];
            curr[j] = curr[b - (j - a)];
            curr[b - (j - a)] = c;
        }
    }
    rep(i, 0, n) {
        succ[curr[i]] = i;
    }
    rep(i, 0, n) {
        if (!visited[i]) {
            cycles.push_back({});
            dfs(i);
            ++cnt;
        }
    }
    vector<ll> ans(n);
    rep(i, 0, cycles.size()) {
        rep(j, 0, cycles[i].size()) {
            ans[cycles[i][(j + k) % cycles[i].size()]] = cycles[i][j];
        }
    }
    rep(i, 0, n) {
        cout << ans[i] + 1 << endl;
    }
}
