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

void setIO(string name = "berries") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vector<ll> berries;
ll n, k, num;

ll check(ll i) {
    vector<ll> copy = berries;
    ll idx = 0;
    vector<ll> ans;
    while (idx < num && ans.size() < k / 2) {
        if (copy[idx] >= i) {
            ans.push_back(i);
            copy[idx] -= i;
        }
        else
            ++idx;
    }
    if (ans.size() < k / 2) return -1;
    vector<ll> nans;
    idx = 0;
    while (idx < num) {
        if (copy[idx] <= i) {
            nans.push_back(copy[idx]);
            copy[idx] = 0;
            ++idx;
        }
        else {
            nans.push_back(i);
            copy[idx] -= i;
        }
    }
    if (nans.size() < k / 2) return -1;
    sort(all(nans), greater<ll>());
    ll tot = 0;
    rep(i, 0, k / 2)
        tot += nans[i];
    return tot;
}

int main()
{
    setIO();
    cin >> n >> k;
    num = min(n, k);
    rsz(berries, n);
    rep(i, 0, n)
        cin >> berries[i];
    sort(all(berries), greater<ll>());
    ll m = 0;
    rep(i, berries[num - 1], berries[0] + 1) {
        ll t = check(i);
        m = max(m, t);
    }
    cout << m << endl;
}
