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

void setIO(string name = "cownomics") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

struct VectorHash {
    size_t operator()(const std::vector<char>& v) const {
        std::hash<char> hasher;
        size_t seed = 0;
        for (char i : v)
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

int main()
{
    setIO();
    ll n, m; cin >> n >> m;
    vector<string> spotty(n);
    vector<string> plain(n);
    rep(i, 0, n)
        cin >> spotty[i];
    rep(i, 0, n)
        cin >> plain[i];
    ll ans = 0;
    rep(i, 0, m) {
        rep(j, i + 1, m) {
            rep(k, j + 1, m) {
                unordered_set<vector<char>, VectorHash> vch;
                rep(l, 0, n)
                    vch.insert({ spotty[l][i], spotty[l][j], spotty[l][k] });
                rep(l, 0, n) {
                    if (vch.count({ plain[l][i], plain[l][j], plain[l][k] }))
                        goto next;
                }
                ++ans;
            next:;
            }
        }
    }
    cout << ans << endl;
}
