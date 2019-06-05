#include<stdio.h>
#include<unordered_map>

std::unordered_map<int, int> mp;
int T, Ti, n, k, q;

int change(int x) {
    int l = 1, r = 1;//has one there;
    if (mp[x - 1] == 2 || (x - 1 > k && mp[x - 1] == 0))l = 0;
    if (mp[x + 1] == 2 || (x + 1 > k && mp[x + 1] == 0))r = 0;
    return r + l - 1;//both are ones,return 1;
}

int main() {
    scanf("%d", &T);
    while (Ti++ < T) {
        scanf("%d%d%d", &n, &k, &q);
        printf("Case %d:\n", Ti);
        mp[0] = mp[n + 1] = 1;
        int ans = 1;
        for (int i = 1, x, y; i <= q; i++) {
            scanf("%d%d", &x, &y);
            ans += change(x);
            mp[x] = 2;//one on 'x' has been taken;
            ans -= change(y);
            mp[y] = 1;
            printf("%d\n", ans);
        }
        mp.clear();
    }
    return 0;
}
/*
*/
