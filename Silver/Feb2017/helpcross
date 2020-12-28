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

void setIO(string name = "helpcross") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();
    int c, n;
    cin >> c >> n;
    vi chickens;
    vector<pair<int, int>> cows;
    for (int i = 0; i < c; ++i) {
        int t; cin >> t;
        chickens.pb(t);
    }
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        cows.pb({ b,a });
    }
    sort(all(chickens));
    sort(all(cows));
    int ans = 0;
    int i1 = 0;
    int i2 = 0;
    for (int i = 0; i < n; ++i) {
        auto chicken = lower_bound(all(chickens), cows[i].second);
        if (chicken != chickens.end() && *chicken <= cows[i].first) {
            ++ans;
            chickens.erase(chicken);
        }
    }
    cout << ans << endl;
}
