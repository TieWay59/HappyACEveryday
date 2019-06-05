#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>

typedef long long ll;
const int MAXN = 1000008;
const int INF = 0x3f3f3f3f;
std::multiset<int> sav;
std::multiset<int>::iterator it, jt;

int main() {
    int n, m, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
            scanf("%d", &x), sav.insert(x);
        if (sav.size() > 1) {
            it = sav.begin();
            jt = sav.end();
            jt--;
            printf("%d %d\n", *it, *jt);
            sav.erase(it);
            sav.erase(jt);
        }
    }
    return 0;
}
/*

*/
