#include <bits/stdc++.h>

#define  debug(x)  cerr <<#x << " = "<<x<<endl

const int MAXN = 1e5 + 59;
const int MOD = 1e9 + 7;
using namespace std;
typedef long long ll;

int a[MAXN];


int n, m, kase;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

//    cin >> kase;
//    while (kase--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[0] = -80000;
    int ans = 0, i, j;
    for (i = 1, j = 0; i <= n; ++i) {
        if (a[i] - a[i - 1] > m) {
            ans = max(ans, i - j);
            j = i;
        }
    }
    ans = max(ans, i - j);
    cout << ans << endl;
//    }
}
/*
9 2
 3 14 15 92 653 5897 5897 5898 5900

 9 0
 3 14 15 92 653 5897 5897 5898 5900

 9 8848
 3 14 15 92 653 5897 5897 5898 5900
 */