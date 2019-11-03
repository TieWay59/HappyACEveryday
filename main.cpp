#include <bits/stdc++.h>
#include <tuple>

#define  debug(x)  cerr <<#x << " = "<<x<<endl
const int MAXN = 2e5 + 59;
using namespace std;

typedef long long ll;

int n, k;
int a[MAXN];
int ans;
int minVal = 10005;

int tree[MAXN];

void add(int x, int val) {
    while (x <= n) {
        tree[x] += val;
        x += (x & -x);
    }
}

int ask(int x) {
    int ret = 0;
    while (x) {
        ret += tree[x];
        x -= (x & -x);
    }
    return ret;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);

//    cin >> kase;
//    while (kase--) {
//    }

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        add(i, a[i]);
        minVal = min(minVal, a[i]);
    }

    for (int i = k, delta; i <= n; i++) {
        delta = ask(i) - ask(i - k);
        if (delta >= 0) {
            delta++;
            for (int j = i, t; delta > 0 && j > i - k; j--) {
                t = min(delta, a[j] - minVal);
                delta -= t;
                a[j] -= t;
                ans += t;
                add(j, -t);
            }
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " \n"[i == n];
    }

    return 0;
}
/*

 */