#include <bits/stdc++.h>
#include <tuple>

#define  debug(x)  cerr <<#x << " = "<<x<<endl
const int MAXN = 1e6 + 59;
using namespace std;
typedef long long ll;

const int dir[] = {-5, -2, -1, 1, 2, 5};
int kase, a, b;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> kase;
    while (kase--) {
        cin >> a >> b;
        int delta = abs(a - b);
        int ans = delta / 5
                  + (delta % 5) / 2
                  + (delta % 5) % 2;
        cout << ans << '\n';
    }
    return 0;
}

/*
 
 */
