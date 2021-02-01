#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using ll = long long;

#define pb push_back
#define rep(i, a, b) for(ll i = a; i < b; ++i)
#define rsz(x, n) x.resize(n)

using pi = pair<int, int>;

ll n, k;
vector<ll> curr;
vector<ll> succ;
vector<pair<ll, ll>> swaps;
vector<bool> visited;
vector<ll> cycles;
vector<ll> ans;
map<ll, ll> code;
vector<unordered_set<ll>> vs;

void dfs(ll a) {
    visited[a] = true;
    if (!visited[succ[a]]) dfs(succ[a]);
    else cycles.push_back(succ[a]);
}

int main() {
    cin >> n >> k;
    rsz(curr, n);
    rsz(succ, n);
    rsz(visited, n);
    rsz(ans, n);
    rsz(swaps, k);
    rep(i, 0, n) {
        curr[i] = i;
    }
    rep(i, 0, k) {
        ll a, b; cin >> a >> b;
        --a; --b;
        swaps[i].first = a;
        swaps[i].second = b;
        ll c = curr[a];
        curr[a] = curr[b];
        curr[b] = c;
    }
    rep(i, 0, n) {
        succ[curr[i]] = i;
    }
    rep(i, 0, n) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    rep(i, 0, cycles.size()) {
        ll t = cycles[i];
        code[t] = i;
        ll c = succ[t];
        while (c != t) {
            code[c] = i;
            c = succ[c];
        }
    }
    rsz(vs, cycles.size());
    rep(i, 0, n) {
        curr[i] = i;
        vs[code[i]].insert(i);
    }
    rep(i, 0, k) {
        ll a = swaps[i].first;
        ll b = swaps[i].second;
        vs[code[curr[a]]].insert(b);
        vs[code[curr[b]]].insert(a);
        ll c = curr[a];
        curr[a] = curr[b];
        curr[b] = c;
    }
    rep(i, 0, n) {
        cout << vs[code[i]].size() << endl;
    }
}
