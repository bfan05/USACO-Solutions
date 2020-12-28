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

void setIO(string name = "lightson") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    vector<int> rooms;
    for (int i = 0; i < n * n; ++i) {
        rooms.pb(0);
    }
    rooms[0] = 1;
    int count = 0;
    for (int i = 0; i < n * n; ++i) {
        vector<int> edge;
        if (i / n > 0) {
            edge.pb(i - n);
        }
        if ((i / n) < (n - 1)) {
            edge.pb(i + n);
        }
        if (i % n > 0) {
            edge.pb(i - 1);
        }
        if (i % n < n - 1) {
            edge.pb(i + 1);
        }
        edges.pb(edge);
    }
    vector<vector<int>> lights;
    for (int i = 0; i < n * n; ++i) {
        lights.pb({});
    }
    for (int i = 0; i < m; ++i) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        x--; y--; a--; b--;
        lights[x * n + y].pb(a * n + b);
    }
    bool foundNew = true;
    int c = -1;
    while (foundNew) {
        int nc = 0;
        queue<int> breadth;
        breadth.push(0);
        vector<bool> visited;
        for (int i = 0; i < n * n; ++i) {
            visited.pb(false);
        }
        while (!breadth.empty()) {
            ++nc;
            visited[breadth.front()] = true;
            for (int i = 0; i < lights[breadth.front()].size(); ++i) {
                rooms[lights[breadth.front()][i]] = 1;
            }
            for (int i = 0; i < edges[breadth.front()].size(); ++i) {
                if (rooms[edges[breadth.front()][i]] == 1 && !visited[edges[breadth.front()][i]]) {
                    breadth.push(edges[breadth.front()][i]);
                    visited[edges[breadth.front()][i]] = true;
                }
            }
            breadth.pop();
        }
        if (nc != c) {
            foundNew = true;
            c = nc;
        }
        else {
            foundNew = false;
        }
    }
    for (int i = 0; i < n * n; ++i) {
        if (rooms[i] == 1) {
            ++count;
        }
    }
    cout << count << endl;
}
