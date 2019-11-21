#include <bits/stdc++.h>
#include <tuple>

#define  debug(x)  cerr <<#x << " = "<<x<<endl
const int MAXN = 1e3 + 59;
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;


int kase, b;
int n, m;
int a[MAXN];
ll ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> kase;
    while (kase--) {
        cin >> n >> m;
        ans = 0;
        ll min1 = INF, min2 = INF;
        ll v1 = INF, v2 = INF;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            ans += a[i] + a[i];
            if (a[i] < min1) {
                swap(min1, min2);
                swap(v1, v2);
                min1 = a[i];
                v1 = i;
            } else if (a[i] < min2) {
                min2 = a[i];
                v2 = i;
            }
        }
        if (n == 2 || m < n) {
            cout << -1 << '\n';
            continue;
        }
        ans += (min1 + min2) * (m - n);
        cout << ans << '\n';

        for (int i = 1; i < n; i++) {
            cout << i << " " << i + 1 << '\n';
        }
        cout << n << " " << 1 << '\n';
        for (int i = n + 1; i <= m; i++) {
            cout << v1 << " " << v2 << '\n';
        }
    }
    return 0;
}

/*
 
 */
