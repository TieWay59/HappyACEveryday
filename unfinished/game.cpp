/*
 * https://codeforces.com/contest/1221/problem/E
 *
 */
#include <bits/stdc++.h>

#define  _debug(x) cerr<<#x << " = " << x<<endl
using namespace std;

typedef long long ll;
const int MOD = -1;
const int INF = -1;
const int MAXN = 3e5 + 59;

int kase, Kase;
int n, a, b;
char s[MAXN];
int x[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> kase;
    while (kase--) {
        cin >> a >> b >> s;
        n = 0;

        int t = 0;
        int bb = 0;
        int ab = 0;
        int al = 0;
        int bl = 0;


        for (auto si:s) {
            if (!si)break;

            if (si == '.') {
                t++;
            } else if (t) {
                x[n++] = t;
                t = 0;
                if (t >= b + b)bb++;
                if (b <= t && t < a)ab++;
                if (t >= a)al++;
                if (t >= b)bl++;
            }
        }
        for (int i = 0; i < n; i++) {
            _debug(x[i]);
        }

        if (ab) {
            cout << "NO" << endl;
        } else if (bb >= 2) {
            cout << "NO" << endl;
        } else if (bb == 1) {
            string ans = "NO";

            for (int i = 0; i < n; ++i) {
                if (x[i] < a + b - 1 + b - 1)
                    ans = "NO";
            }

            if (ans == "NO") {
                cout << ans << endl;
            } else {
                cout << (al & 1 ? "YES" : "NO") << endl;
            }

        } else {
            cout << (al & 1 ? "YES" : "NO") << endl;
        }

    }

    return 0;
}
