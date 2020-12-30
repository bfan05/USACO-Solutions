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

void setIO(string name = "perimeter") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vector<vector<ll>> grid;
vector<vector<bool>> visited;
ll area = 0;
ll perimeter = 0;
ll carea = 0, cperimeter = 0;
ll minx, maxx, miny, maxy;
ll n;

void dfs(ll i, ll j) {
    if (i < 1 || i > n || j < 1 || j > n || visited[i][j] || grid[i][j] == 0)
        return;
    visited[i][j] = true;
    carea++;
    if (!grid[i - 1][j]) ++cperimeter;
    if (!grid[i + 1][j]) ++cperimeter;
    if (!grid[i][j - 1]) ++cperimeter;
    if (!grid[i][j + 1]) ++cperimeter;
    int dir[] = { 0, 1, 0, -1, 0 };
    for (int k = 0; k < 4; k++) {
        int dx = i + dir[k];
        int dy = j + dir[k + 1];
        dfs(dx, dy);
    }
}

int main()
{
    setIO();
    cin >> n;
    rsz(grid, n + 2);
    rsz(visited, n + 2);
    rep(i, 0, n + 2) {
        grid[0].push_back(0);
        grid[n + 1].push_back(0);
        visited[0].push_back(false);
        visited[n + 1].push_back(false);
    }
    rep(i, 1, n + 1) {
        grid[i].push_back(0);
        visited[i].push_back(false);
        rep(j, 0, n) {
            char ch; cin >> ch;
            if (ch == '#') {
                grid[i].push_back(1);
                visited[i].push_back(false);
            }
            else {
                grid[i].push_back(0);
                visited[i].push_back(false);
            }
        }
        grid[i].push_back(0);
        visited[i].push_back(false);
    }
    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            if (!visited[i][j]) {
                carea = 0; cperimeter = 0;
                dfs(i, j);
                if (carea > area) {
                    area = carea;
                    perimeter = cperimeter;
                }
                else if (carea == area)
                    perimeter = min(perimeter, cperimeter);
            }
        }
    }
    cout << area << " " << perimeter << endl;
}
