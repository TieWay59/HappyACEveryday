/*https://www.nowcoder.com/acm/contest/180/B
��һ������ֻҪ����ȫ�������Ϳ�����

�ڶ�������Ҫ��ϸ���ˡ�
������ĸ������˼· ((1-pi)+pi*x)�۳�
ÿ��ֻ��Ҫ���㵽k���ɣ�����k�ķ�Χ��С�����ա�
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const double eps = 1e-6;
const int N = 1e5 + 5;

int n, k;
double p[2][N];
double ans1, ans2[205];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &p[1][i]);
        //printf("%f\n",p[1][i]);//

        p[0][i] = 1.0 - p[1][i];
        ans1 += p[1][i];
    }
/*
    for(int i=1;i<=k;i++)
        ans2[i]=0.0;*/

    ans2[0] = 1.0;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--)
            ans2[j] = ans2[j] * p[0][i] + ans2[j - 1] * p[1][i];
        ans2[0] = ans2[0] * p[0][i];
        /*
        for(int j=0;j<=min(i,k);j++)
            printf("%.4f ",ans2[j]);puts("");*/
    }
    printf("%.4lf\n%.4lf\n", ans1, ans2[k]);
    return 0;
}
