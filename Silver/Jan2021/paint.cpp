#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using ll = long long;

#define pb push_back
#define rep(i, a, b) for(ll i = a; i < b; ++i)
#define rsz(x, n) x.resize(n)

unordered_map<char, ll> mp;

int main() {
    rep(i, 0, 26) {
        mp[static_cast<char>(i + 65)] = i;
    }
    ll n, q; cin >> n >> q;
    vector<ll> vl(n + 2);
    rep(i, 1, n + 1) {
        char a; cin >> a;
        vl[i] = mp[a];
    }
    vl[0] = -1;
    vl[n + 1] = -1;
    vector<ll> ps1(n + 2);
    vector<ll> ps2(n + 2);
    unordered_set<ll> seen;
    unordered_map<ll, ll> last;
    rep(i, 0, n) {
        if (vl[i + 1] > vl[i]) {
            seen.insert(vl[i + 1]);
            ps1[i + 1] = ps1[i] + 1;
        }
        else if (vl[i + 1] < vl[i]) {
            if (!seen.count(vl[i + 1])) {
                seen.insert(vl[i + 1]);
                ps1[i + 1] = ps1[i] + 1;
            }
            else {
                ll idx = last[vl[i + 1]];
                bool works = true;
                rep(j, idx, i + 1) {
                    if (vl[j] < vl[i + 1]) works = false;
                }
                ps1[i + 1] = ps1[i];
                if (!works) ps1[i + 1]++;
            }
        }
        else {
            ps1[i + 1] = ps1[i];
        }
        last[vl[i + 1]] = i + 1;
    }
    seen.clear();
    rep(i, 0, n) {
        if (vl[n - i] > vl[n - i + 1]) {
            seen.insert(vl[n - i]);
            last[vl[n - i]] = n - i;
            ps2[n - i] = ps2[n - i + 1] + 1;
        }
        else if (vl[n - i] < vl[n - i + 1]) {
            if (!seen.count(vl[n - i])) {
                seen.insert(vl[n - i]);
                ps2[n - i] = ps2[n - i + 1] + 1;
            }
            else {
                ll idx = last[vl[n - i]];
                bool works = true;
                for (ll j = idx; j > n - i; --j) {
                    if (vl[j] < vl[n - i]) works = false;
                }
                ps2[n - i] = ps2[n - i + 1];
                if (!works) ps2[n - i]++;
            }
        }
        else {
            ps2[n - i] = ps2[n - i + 1];
        }
        last[vl[n - i]] = n - i;
    }
    rep(i, 0, q) {
        ll a, b; cin >> a >> b;
        cout << ps1[a - 1] + ps2[b + 1] << endl;
    }
}
