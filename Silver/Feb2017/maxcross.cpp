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

void setIO(string name = "maxcross") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();
    int n, k, b;
    cin >> n >> k >> b;
    vector<int> broken;
    for (int i = 0; i < n; ++i) {
        broken.pb(0);
    }
    for (int i = 0; i < b; ++i) {
        int signal; cin >> signal; signal--;
        broken[signal] = 1;
    }
    vector<int> ps;
    ps.pb(0);
    for (int i = 0; i < n; ++i) {
        if (broken[i] == 0) {
            ps.pb(ps[i] + 1);
        }
        else {
            ps.pb(ps[i]);
        }
    }
    int ans = n;
    for (int i = 1; i <= n - k + 1; ++i) {
        int j = i + k - 1;
        int fix = k - (ps[j] - ps[i - 1]);
        ans = min(ans, fix);
    }
    cout << ans << endl;
}
