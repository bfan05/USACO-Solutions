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

void setIO(string name = "homework") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();
    ll n;
    cin >> n;
    vector<ll> scores;
    for (ll i = 0; i < n; ++i) {
        ll score;
        cin >> score;
        scores.pb(score);
    }
    vector<ll> ps;
    vector<ll> smallest;
    ps.pb(scores[n - 1]);
    smallest.pb(scores[n - 1]);
    for (ll i = 0; i < n - 2; ++i) {
        ps.pb(ps[i] + scores[n - i - 2]);
        smallest.pb(min(smallest[i], scores[n - i - 2]));
    }
    ll bestNum = 0;
    ll numTimes = 1;
    for (ll i = 1; i < ps.size(); ++i) {
        if ((ps[i] - smallest[i]) * numTimes > bestNum* i) {
            bestNum = ps[i] - smallest[i];
            numTimes = i;
        }
    }
    for (ll i = ps.size() - 1; i > 0; --i) {
        if ((ps[i] - smallest[i]) * numTimes == bestNum * i) {
            cout << n - i - 1 << endl;
        }
    }
}
