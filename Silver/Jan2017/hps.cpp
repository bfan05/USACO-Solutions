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

void setIO(string name = "hps") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();
    int n;
    cin >> n;
    vi hoofs;
    vi scissors;
    vi papers;
    hoofs.pb(0);
    scissors.pb(0);
    papers.pb(0);
    for (int i = 0; i < n; ++i) {
        char move;
        cin >> move;
        if (move == 'H') {
            hoofs.pb(hoofs[i] + 1);
            scissors.pb(scissors[i]);
            papers.pb(papers[i]);
        }
        else if (move == 'S') {
            hoofs.pb(hoofs[i]);
            scissors.pb(scissors[i] + 1);
            papers.pb(papers[i]);
        }
        else {
            hoofs.pb(hoofs[i]);
            scissors.pb(scissors[i]);
            papers.pb(papers[i] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int s1 = hoofs[i] + scissors[n] - scissors[i];
        int s2 = scissors[i] + hoofs[n] - hoofs[i];
        int s3 = hoofs[i] + papers[n] - papers[i];
        int s4 = papers[i] + hoofs[n] - hoofs[i];
        int s5 = scissors[i] + papers[n] - papers[i];
        int s6 = papers[i] + scissors[n] - scissors[i];
        int m1 = max(s1, s2);
        int m2 = max(s3, s4);
        int m3 = max(s5, s6);
        int m4 = max(m1, m2);
        int m5 = max(m4, m3);
        ans = max(ans, m5);
    }
    cout << ans << endl;
}
