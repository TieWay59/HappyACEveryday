#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
const int INF = 0x7FFFFFFF;
typedef long long ll;
const int MAXN = 105;
double dp[MAXN];
int ps[MAXN];
int l, n, c, t;
double vr, vt1, vt2;

int main() {
    //freopen("in.txt","r",stdin);
    while (scanf("%d", &l) != EOF) {
        scanf("%d%d%d", &n, &c, &t);
        scanf("%lf%lf%lf", &vr, &vt1, &vt2);
        for (int i = 1; i <= n; i++)
            scanf("%d", ps + i), dp[i] = 1e9 + 7;
        ps[0] = 0;
        ps[n + 1] = l;
        dp[0] = 0;
        dp[n + 1] = INF;//初始化做的不太好
        for (int i = 1; i <= n + 1; i++) {
            double ti;
            for (int j = 0, x; j < i; j++) {
                x = ps[i] - ps[j];
                if (x <= c) {
                    ti = x / vt1;
                } else {
                    ti = c / vt1 + (x - c) / vt2;
                }
                if (j)ti += t;
                dp[i] = min(dp[i], dp[j] + ti);
            }
        }
        if (dp[n + 1] > l / vr) {
            puts("Good job,rabbit!");
        } else {
            puts("What a pity rabbit!");
        }
    }
    return 0;
}
/*
*/
