/*
��map��¼��Ӧ��pair��ǰһ���ǰ���ͳ��ȼ��ɡ�
ע�⣡ͬһ��pair������ͬһ�������Ρ�
*/
#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
typedef pair<int, int> PII;
map<PII, PII> mp;

int main() {
    int T, n, m, ans = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &m);
            for (int a, b, pre, sum, j = 1; j <= m; j++) {
                scanf("%d%d", &a, &b);
                pre = mp[{a, b}].first;
                if (pre == i)continue;
                sum = mp[{a, b}].second;
                if (pre != i - 1) mp[{a, b}] = {i, 1};
                else mp[{a, b}] = {i, sum + 1};
                ans = max(ans, mp[{a, b}].second);
            }
        }
        printf("%d\n", ans);
        ans = 0;
        mp.clear();
    }
    return 0;
}
/*
2
8
2 1 1 2 2
2 1 1 1 4
2 1 1 2 2
2 2 2 1 4
0
0
1 1 1
1 1 1
*/
