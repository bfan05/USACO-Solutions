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

void setIO(string name = "revegetate") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll n, m;
vector<vector<ll>> edges;
vector<ll> colors;
vector<vector<ll>> same;
vector<ll> codes;
ll ans = 0;
ll cnt = 0;
vector<bool> visited;
bool works = true;

void dfs(ll node, ll col) {
    codes[node] = cnt;
    visited[node] = true;
    colors[node] = col;
    for (ll edge : edges[node]) {
        if (visited[edge])
            if (colors[edge] == colors[node]) works = false;
        else
            dfs(edge, !col);
    }
    for (ll edge : same[node]) {
        if (visited[edge])
            if (colors[edge] != colors[node]) works = false;
        else
            dfs(edge, col);
    }
}

int main() {
    setIO();
    cin >> n >> m;
    colors.resize(n, -1);
    rsz(edges, n);
    rsz(codes, n);
    rsz(same, n);
    rep(i, 0, m) {
        char ch; cin >> ch;
        ll a, b; cin >> a >> b;
        --a; --b;
        if (ch == 'S') {
            same[a].push_back(b);
            same[b].push_back(a);
        }
        else {
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
    }
    visited.resize(n, false);
    rep(i, 0, n) {
        if (!visited[i]) {
            ++ans;
            dfs(i, 0);
        }
    }
    if (!works)
        cout << 0; return 0;
    string str = "1";
    rep(i, 0, ans)
        str += '0';
    cout << str;
}
