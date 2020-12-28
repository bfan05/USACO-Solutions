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
    vector<pair<int, int>> cows;
    vector<pair<int,int>> infected;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int loc, num; cin >> loc >> num;
        cows.push_back({ loc, num });
        if (num)
            infected.push_back({ loc, num });
    }
    sort(all(cows));
    sort(all(infected));
    if (infected.size() < 2) {
        cout << infected.size() << endl;
        return 0;
    }
    int radius = 1e6;
    for (int i = 1; i < n; ++i) {
        if (cows[i].second != cows[i - 1].second)
            radius = min(radius, abs(cows[i].first - cows[i - 1].first) - 1);
    }
    vector<int> codes;
    int c = 0;
    for (int i = 0; i < infected.size(); ++i) {
        codes.push_back(-1);
    }
    for (int i = 0; i < infected.size(); ++i) {
        if (codes[i] == -1) {
            codes[i] = c;
            int k = i;
            while ((k + 1) < infected.size() && (infected[k + 1].first - infected[k].first) <= radius) {
                codes[k + 1] = c;
                ++k;
            }
            c++;
        }
    }
    cout << c;
}
