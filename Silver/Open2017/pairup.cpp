#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define rep(i, a, b) for(ll i = a; i < b; ++i)

using pi = pair<int, int>;
#define f first
#define s second

void setIO(string name = "pairup") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

struct ptr {
    ll idx, spot, val;
};

int main() {
    setIO();
    ll n; cin >> n;
    vector<pair<ll, ll>> vl;
    rep(i, 0, n) {
        ll a, b; cin >> a >> b;
        vl.push_back({ b, a - 1 });
    }
    sort(all(vl));
    ptr i; i.idx = 0; i.spot = 0; i.val = vl[0].first;
    ptr j; j.idx = n - 1; j.spot = vl[n - 1].second; j.val = vl[n - 1].first;
    ll ans = i.val + j.val;
    while (i.idx < j.idx) {
        ans = max(ans, i.val + j.val);
        ++i.spot; --j.spot;
        if (i.spot == vl[i.idx].second) {
            ++i.idx;
            i.spot = 0;
            i.val = vl[i.idx].first;
        }
        if (j.spot < 0) {
            --j.idx;
            j.spot = vl[j.idx].second;
            j.val = vl[j.idx].first;
        }
    }
    if (i.idx == j.idx) {
        ans = max(ans, 2 * i.val);
    }
    cout << ans << endl;
}
