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

void setIO(string name = "split") {
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
    vector<pair<ll, ll>> coords1(n), coords2(n);
    multiset<ll> xfirst, xsecond;
    multiset<ll> yfirst, ysecond;
    rep(i, 0, n) {
        cin >> coords1[i].first >> coords1[i].second;
        coords2[i].first = coords1[i].second;
        coords2[i].second = coords1[i].first;
        xsecond.insert(coords1[i].second);
        ysecond.insert(coords2[i].second);
    }
    sort(all(coords1));
    sort(all(coords2));
    ll one = (*xsecond.rbegin() - *xsecond.begin()) * (*ysecond.rbegin() - *ysecond.begin());
    ll ans = one;
    rep(i, 0, n - 1) {
        xsecond.erase(xsecond.find(coords1[i].second));
        xfirst.insert(coords1[i].second);
        ll firstA = (*xfirst.rbegin() - *xfirst.begin()) * (coords1[i].first - coords1[0].first);
        ll secondA = (*xsecond.rbegin() - *xsecond.begin()) * (coords1[n - 1].first - coords1[i + 1].first);
        ans = min(ans, firstA + secondA);
    }
    rep(i, 0, n - 1) {
        ysecond.erase(ysecond.find(coords2[i].second));
        yfirst.insert(coords2[i].second);
        ll firstA = (*yfirst.rbegin() - *yfirst.begin()) * (coords2[i].first - coords2[0].first);
        ll secondA = (*ysecond.rbegin() - *ysecond.begin()) * (coords2[n - 1].first - coords2[i + 1].first);
        ans = min(ans, firstA + secondA);
    }
    cout << one - ans << endl;
}
