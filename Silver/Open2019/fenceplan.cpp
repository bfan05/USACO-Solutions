#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "fenceplan") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int n, m;
vector<vector<int>> moos;
vector<pair<int, int>> coords;
vector<int> visited;
vector<vector<int>> components;
int c = -1;

void dfs(int vertex) {
    visited[vertex] = c;
    components[c].push_back(vertex);
    for (int neighbor : moos[vertex]) {
        if (visited[neighbor] == -1) {
            dfs(neighbor);
        }
    }
}

int main() {
    setIO();
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        coords.push_back({ x, y });
        moos.push_back({});
        visited.push_back(-1);
    }
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        a--; b--;
        moos[a].push_back(b); moos[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        if (visited[i] == -1) {
            ++c;
            components.push_back({});
            dfs(i);
        }
    }
    ll ans = 4e8;
    for (vi component : components) {
        int lx = 0, sx = 1e8; int sy = 1e8, ly = 0;
        for (int cow : component) {
            lx = max(lx, coords[cow].first);
            sx = min(sx, coords[cow].first);
            ly = max(ly, coords[cow].second);
            sy = min(sy, coords[cow].second);
        }
        ans = min(ans, (ll)2 * ((ll)lx - sx + ly - sy));
    }
    cout << ans;
}
