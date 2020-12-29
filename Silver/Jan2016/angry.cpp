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

void setIO(string name = "angry") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll n, k;
vector<ll> pos;

bool check(ll r) {
    ll last = 0;
    ll cnt = 1;
    rep(i, 0, n) {
        if (pos[i] - pos[last] > 2 * r) {
            ++cnt;
            last = i;
        }
    }
    return cnt <= k;
}

int main() {
    setIO();
    cin >> n >> k;
    pos.resize(n);
    rep(i, 0, n) {
        cin >> pos[i];
    }
    sort(all(pos));
    ll l = 0, r = 1;
    while (!check(r)) r *= 2;
    while (r - l > 1) {
        ll mid = (r + l) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r;
}
