/*http://acm.hdu.edu.cn/showproblem.php?pid=6438
��Ŀ��ʵ���ѣ�����������Σ�������ô���ô����ˡ�
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        ll ans = 0, cnt = 0;
        priority_queue <pll, vector<pll>, greater<pll>> q;
        //���������һ����С��������ȶ��е�д������ס������ɣ�һ��д���ǴӴ�С
        scanf("%d", &n);
        for (int v, i = 1; i <= n; i++) {

            scanf("%d", &v);
            if (!q.empty() && q.top().first < v) {
                cnt++;
                pll t = q.top();
                q.pop();
                if (t.second == 1)cnt--;
                else cnt++;
                ans += v - t.first;
                q.push({v, 1});
                q.push({v, 2});
            } else {
                q.push({v, 3});
            }
        }
        printf("%lld %lld\n", ans, cnt);
    }
    return 0;
}
