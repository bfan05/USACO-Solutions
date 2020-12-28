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

void setIO(string name = "highcard") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();
    int n; cin >> n;
    vector<int> bessie;
    vector<int> elsie;
    set<int> nums;
    for (int i = 1; i <= 2 * n; ++i) {
        nums.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        int card; cin >> card;
        elsie.pb(card);
        nums.erase(card);
    }
    for (int i = 1; i <= 2 * n; ++i) {
        if (nums.count(i) == 1) {
            bessie.pb(i);
        }
    }
    sort(all(bessie)); sort(all(elsie));
    int bi = 0, ei = 0;
    int ans = 0;
    while (bi < n && ei < n) {
        if (bessie[bi] > elsie[ei]) {
            ++bi; ++ei;
            ++ans;
        }
        else {
            ++bi;
        }
    }
    cout << ans;
}
