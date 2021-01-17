// greedy. for each index, start at that index. then greedily add cows by putting the cow in the next available spot.
// calculate this for each index, then take the minimum.

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

void setIO(string name = "cbarn") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO();
    ll n; cin >> n;
    vector<ll> cnt(n);
    rep(i, 0, n) {
        cin >> cnt[i];
    }
    ll ans = 0;
    ll last = 0;
    rep(i, 0, n) {
        rep(j, 0, cnt[i]) {
            ll c = (last - i) % n;
            if (c < 0) c += n;
            ans += c * c;
            ++last;
        }
    }
    rep(i, 1, n) {
        ll curr = 0;
        last = i;
        rep(j, i, n + i) {
            ll t = j % n;
            rep(k, 0, cnt[t]) {
                ll c = (last - j) % n;
                if (c < 0) c += n;
                curr += c * c;
                ++last;
            }
        }
        ans = min(ans, curr);
    }
    cout << ans;
}
