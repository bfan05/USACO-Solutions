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

int main()
{
    setIO();
    int n, t; cin >> n >> t;
    vector<int> infected;
    for (int i = 0; i < n; ++i) {
        char ch; cin >> ch;
        infected.push_back((int)ch - 48);
    }
    vector<pair<int, pair<int, int>>> shakes;
    for (int i = 0; i < t; ++i) {
        int time, x, y; cin >> time >> x >> y;
        --x; --y;
        shakes.push_back({ time, {x, y} });
    }
    sort(all(shakes));
    set<int> posCows;
    int m1 = t;
    int m2 = 0;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k <= t; ++k) {
            vi numShakes(n);
            vi ic(n);
            ic[i] = 1;
            for (int j = 0; j < t; ++j) {
                int x = shakes[j].second.first;
                int y = shakes[j].second.second;
                bool xtrue = false;
                bool ytrue = false;
                if (ic[x] == 1 && numShakes[x] < k) {
                    ytrue = true;
                    ++numShakes[x];
                }
                if (ic[y] == 1 && numShakes[y] < k) {
                    xtrue = true;
                    ++numShakes[y];
                }
                if (xtrue) 
                    ic[x] = 1;
                if (ytrue) 
                    ic[y] = 1;
            }
            if (ic == infected) {
                posCows.insert(i);
                m1 = min(m1, k);
                m2 = max(m2, k);
            }
        }
    }
    cout << posCows.size() << " ";
    if (m1 == t)
        cout << "Infinity" << " ";
    else
        cout << m1 << " ";
    if (m2 == t)
        cout << "Infinity";
    else
        cout << m2;
}
