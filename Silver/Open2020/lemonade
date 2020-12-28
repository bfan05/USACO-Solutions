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

void setIO(string name = "lemonade") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();
    int n; cin >> n;
    vector<int> cows;
    for (int i = 0; i < n; ++i) {
        int cow; cin >> cow;
        cows.pb(cow);
    }
    sort(all(cows), greater<int>());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i <= cows[i]) {
            ++ans;
        }
    }
    cout << ans << endl;
}
