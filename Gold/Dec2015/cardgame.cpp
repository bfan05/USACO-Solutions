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

void setIO(string name = "cardgame") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();
    int n; cin >> n;
    vector<int> bessieA;
    vector<int> bessieB;
    vector<int> elsieA;
    vector<int> elsieB;
    set<int> nums;
    for (int i = 1; i <= 2 * n; ++i) {
        nums.insert(i);
    }
    for (int i = 0; i < n / 2; ++i) {
        int card; cin >> card;
        elsieA.pb(card);
        nums.erase(card);
    }
    for (int i = 0; i < n / 2; ++i) {
        int card; cin >> card;
        elsieB.pb(card);
        nums.erase(card);
    }
    vi bess;
    for (int i = 1; i <= 2 * n; ++i) {
        if (nums.count(i) == 1) {
            bess.pb(i);
        }
    }
    for (int i = 0; i < n / 2; ++i) {
        bessieB.pb(bess[i]);
    }
    for (int i = n / 2; i < n; ++i) {
        bessieA.pb(bess[i]);
    }
    sort(all(elsieA)); 
    sort(all(elsieB), greater<int>());
    sort(all(bessieB), greater<int>());
    int biA = 0, eiA = 0;
    int ans = 0;
    while (biA < n / 2 && eiA < n / 2) {
        if (bessieA[biA] > elsieA[eiA]) {
            ++biA; ++eiA;
            ++ans;
        }
        else {
            ++biA;
        }
    }
    int biB = 0, eiB = 0;
    while (biB < n / 2 && eiB < n / 2) {
        if (bessieB[biB] < elsieB[eiB]) {
            ++biB; ++eiB;
            ++ans;
        }
        else {
            ++biB;
        }
    }
    cout << ans << endl;
}
