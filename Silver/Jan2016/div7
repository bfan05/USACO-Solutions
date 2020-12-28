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

void setIO(string name = "div7") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();
    ll n;
    vector<vector<ll>> idSums;
    for (int i = 0; i < 7; ++i) {
        idSums.pb({});
    }
    cin >> n;
    ll last = 0;
    for (int i = 0; i < n; ++i) {
        ll id;
        cin >> id;
        id %= 7;
        last += id;
        last %= 7;
        idSums[last].pb(i);
    }
    ll ans = 0;
    for (int i = 0; i < 7; ++i) {
        if (sz(idSums[i]) > 1) {
            if (idSums[i][idSums[i].size() - 1] - idSums[i][0] + 1 > ans) {
                ans = idSums[i][idSums[i].size() - 1] - idSums[i][0];
            }
        }
    }
    cout << ans << endl;
}
