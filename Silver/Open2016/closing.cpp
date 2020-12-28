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

void setIO(string name = "closing") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
int n, m;
vector<vector<int>> iroads;
vector<bool> ivisited;
vector<bool> iclosed;
vector<vector<int>> roads;
vector<bool> visited;
vector<bool> closed;

void dfs(int vertex) {
    visited[vertex] = true;
    for (int neighbor : roads[vertex]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

bool checkConnected() {
    int count = 0;
    for (int i = 0; i < roads.size(); ++i) {
        if (!visited[i]) {
            ++count;
            if (count == 2) {
                return false;
            }
            dfs(i);
        }
    }
    return true;
}

int main() {
    setIO();
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        iroads.push_back({});
        ivisited.push_back(false);
        iclosed.push_back(false);
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        iroads[a].push_back(b);
        iroads[b].push_back(a);
    }
    vector<int> order;
    for (int i = 0; i < n; ++i) {
        int b; cin >> b;
        order.push_back(b - 1);
    }

    if (checkConnected())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    for (int i = 0; i < n - 1; ++i) {
        int cl = order[i];
        iclosed[cl] = true;
        roads.clear(); visited.clear();
        for (int j = 0; j < n; ++j) {
            if (iclosed[j]) {
                roads.push_back({});
                visited.push_back(true);
            }
            else {
                vector<int> nroad;
                for (int road : iroads[j]) {
                    if (!iclosed[road])
                        nroad.push_back(road);
                }
                roads.push_back(nroad);
                visited.push_back(false);
            }
        }
        if (checkConnected())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
