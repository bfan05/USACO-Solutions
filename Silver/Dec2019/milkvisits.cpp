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

void setIO(string name = "milkvisits") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll n, m;
ll cnt = 0;
vector<vector<ll>> edges;
vector<char> codes;
vector<int> comp;
vector<bool> visited;

void dfs(ll node) {
    visited[node] = true;
    comp[node] = cnt;
    for (ll edge : edges[node]) {
        if (!visited[edge] && codes[edge] == codes[node])
            dfs(edge);
    }
}

int main()
{
    setIO();
    cin >> n >> m;
    rsz(codes, n);
    rsz(edges, n);
    rsz(visited, n);
    rsz(comp, n);
    rep(i, 0, n) cin >> codes[i];
    rep(i, 0, n - 1) {
        ll a, b; cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }
    rep(i, 0, n) {
        if (!visited[i]) {
            ++cnt;
            dfs(i);
        }
    }
    rep(i, 0, m) {
        ll a, b; cin >> a >> b;
        --a; --b;
        char ch; cin >> ch;
        if (comp[a] == comp[b] && codes[a] == ch) cout << 1;
        else if (comp[a] != comp[b]) cout << 1;
        else cout << 0;
    }
}
