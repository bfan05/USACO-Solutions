// store the edges in 2d vector of pairs. pair first is other vertex, pair second indicates S/D.
// for each connected component that satisfies bipartite conditions, ans *= 2. just dfs for each
// unvisited vertex. if we ever find bipartite doesn't hold, then the ans is 0.

#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

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

vector<vector<pair<ll, ll>>> edges;
vector<bool> visited;
vector<ll> colors;
ll n, m;
bool works = true;

void dfs(ll a, ll col) {
    visited[a] = true;
    colors[a] = col;
    for (pair<ll, ll> &edge : edges[a]) {
        if (!visited[edge.first]) {
            if (edge.second == 1) {
                dfs(edge.first, col);
            }
            else {
                dfs(edge.first, !col);
            }
        }
        else if (edge.second == 0 && colors[a] == colors[edge.first]) {
            works = false;
            return;
        }
        else if (edge.second == 1 && colors[a] != colors[edge.first]) {
            works = false;
            return;
        }
    }
}

int main()
{
    setIO();
    cin >> n >> m;
    rsz(edges, n);
    rsz(visited, n);
    rsz(colors, n);
    rep(i, 0, m) {
        char ch; cin >> ch;
        ll a, b; cin >> a >> b;
        --a; --b;
        if (ch == 'S') {
            edges[a].push_back({ b, 1 });
            edges[b].push_back({ a, 1 });
        }
        else {
            edges[a].push_back({ b, 0 });
            edges[b].push_back({ a, 0 });
        }
    }
    string ans = "1";
    rep(i, 0, n) {
        if (!visited[i]) {
            dfs(i, 0);
            ans += "0";
        }
        if (!works) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
