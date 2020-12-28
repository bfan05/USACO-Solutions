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

void setIO(string name = "haybales") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();
    int n, q; cin >> n >> q;
    vi bales;
    for (int i = 0; i < n; ++i) {
        int bale; cin >> bale;
        bales.pb(bale);
    }
    sort(all(bales));
    for (int i = 0; i < q; ++i) {
        int a, b; cin >> a >> b;
        auto it1 = lower_bound(all(bales), a);
        auto it2 = upper_bound(all(bales), b);
        cout << it2 - it1 << endl;
    }
}
