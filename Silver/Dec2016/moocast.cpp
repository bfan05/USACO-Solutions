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

void setIO(string name = "moocast") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int n;
vector<vector<int>> wt;
vector<vector<int>> pairs;
vector<bool> visited;

void dfs(int vertex) {
    visited[vertex] = true;
    for (int neighbor : pairs[vertex]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    setIO();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, r; cin >> x >> y >> r;
        wt.push_back({});
        wt[i].push_back(x); wt[i].push_back(y); wt[i].push_back(r);
        pairs.push_back({});
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int distance = (wt[i][0] - wt[j][0]) * (wt[i][0] - wt[j][0]) + (wt[i][1] - wt[j][1]) * (wt[i][1] - wt[j][1]);
            if (distance <= wt[i][2] * wt[i][2])
                pairs[i].push_back(j);
            if (distance <= wt[j][2] * wt[j][2])
                pairs[j].push_back(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        queue<int> bfs;
        bfs.push(i);
        vector<bool> visited;
        for (int i = 0; i < n; ++i) {
            visited.pb(false);
        }
        int count = 0;
        while (!bfs.empty()) {
            ++count;
            visited[bfs.front()] = true;
            for (int neighbor : pairs[bfs.front()]) {
                if (!visited[neighbor]) {
                    bfs.push(neighbor);
                    visited[neighbor] = true;
                }
            }
            bfs.pop();
        }
        ans = max(ans, count);
    }
    cout << ans << endl;
}
