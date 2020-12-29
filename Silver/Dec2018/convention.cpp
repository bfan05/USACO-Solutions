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

void setIO(string name = "convention") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll n, m, c;
vector<ll> times;

bool check(ll k) {
    ll num = 0;
    ll cnt = 0;
    while (cnt < n) {
        ll a = times[cnt];
        ll last = cnt;
        ++cnt;
        while (cnt - last < c && cnt < n && times[cnt] - a <= k)
            ++cnt;
        ++num;
        if (num > m)
            return false;
    }
    return true;
}

int main() {
    setIO();
    cin >> n >> m >> c;
    if (m == n) {
        cout << 0 << endl;
        return 0;
    }
    times.resize(n);
    rep(i, 0, n)
        cin >> times[i];
    sort(all(times));
    ll l = -1, r = 1;
    while (!check(r)) r *= 2;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r;
}
