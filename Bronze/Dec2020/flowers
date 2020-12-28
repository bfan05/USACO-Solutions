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

int main() {
    setIO();
    vector<int> ps;
    ps.pb(0);
    int n; cin >> n;
    vector<int> flowers;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        ps.pb(ps[i] + a);
        flowers.push_back(a);
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if ((ps[j] - ps[i]) % (j - i) == 0) {
                int avg = (ps[j] - ps[i]) / (j - i);
                for (int k = i; k < j; ++k) {
                    if (flowers[k] == avg) {
                        ++ans;
                        goto next;
                    }
                }
            }
        next:;
        }
    }
    cout << ans << endl;
}
