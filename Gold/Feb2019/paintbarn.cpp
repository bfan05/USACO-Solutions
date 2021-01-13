// incomplete

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int sz = 201;

using vi = vector<int>;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(ll i = a; i < b; ++i)
#define rsz(x, n) x.resize(n)

using pi = pair<int, int>;
#define f first
#define s second

void setIO(string name = "paintbarn") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll n, k;
ll ps[sz][sz];
ll paint[sz][sz];
ll numk[sz][sz];
ll numj[sz][sz];

int main()
{
    setIO();
    cin >> n >> k;
    rep(i, 0, n) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ++x1; ++y1;
        ps[x1][y1]++;
        ps[x1 + 1][y2 + 1]--;
        ps[x2 + 1][y1 + 1]--;
        rep(j, x1 + 1, x2 + 1) {
            ps[j][y1]++;
            ps[j + 1][y2 + 1]--;
        }
        rep(j, y1 + 1, y2 + 1) {
            ps[x1][j]++;
            ps[x2 + 1][j + 1]--;
        }
        ps[x2 + 1][y2 + 1]++;
    }
    ll ans = 0;
    rep(i, 1, sz) {
        rep(j, 1, sz) {
            paint[i][j] = paint[i - 1][j - 1] + ps[i][j];
            if (paint[i][j] == k) ++ans;
            numk[i][j] = numk[i - 1][j] + numk[i][j - 1] - numk[i - 1][j - 1] + (paint[i][j] == k);
            numj[i][j] = numj[i - 1][j] + numj[i][j - 1] - numj[i - 1][j - 1] + (paint[i][j] == k - 1);
        }
    }
}
