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

void setIO(string name = "bcount") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();
    int n, q;
    cin >> n >> q;
    vector<vector<int>> ps = { {0}, {0}, {0} };
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            ps[0].pb(ps[0][ps[0].size() - 1] + 1);
            ps[1].pb(ps[1][ps[1].size() - 1]);
            ps[2].pb(ps[2][ps[2].size() - 1]);
        }
        else if (a == 2) {
            ps[1].pb(ps[1][ps[1].size() - 1] + 1);
            ps[0].pb(ps[0][ps[0].size() - 1]);
            ps[2].pb(ps[2][ps[2].size() - 1]);
        }
        else {
            ps[2].pb(ps[2][ps[2].size() - 1] + 1);
            ps[1].pb(ps[1][ps[1].size() - 1]);
            ps[0].pb(ps[0][ps[0].size() - 1]);
        }
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << ps[0][b] - ps[0][a - 1] << " " << ps[1][b] - ps[1][a - 1] << " " << ps[2][b] - ps[2][a - 1] << endl;
    }
}
