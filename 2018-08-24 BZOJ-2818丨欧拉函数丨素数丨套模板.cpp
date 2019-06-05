/*
����Ӧ��Ī����˹�������ģ����������
https://www.cnblogs.com/1-1-1-1/p/5727032.html
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 10000005;
int phi[N];

void Init(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!phi[i])
            for (int j = i; j <= n; j += i) {
                if (!phi[j])phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
    }
}

bool vis[N];
int pri[664585], num;

void getprime(int n)//ŷ��ɸ��������
{
    vis[1] = true;
    for (int i = 2; i <= n; i++) {
        if (!vis[i])pri[++num] = i;
        for (int j = 1; j <= num && pri[j] * i <= n; j++) {
            vis[pri[j] * i] = true;
            if (i % pri[j] == 0)break;
        }
    }
}

ll sum[N], ans = 0;
int n;

int main() {
    scanf("%d", &n);
    Init(n);
    printf("%d\n",);
    getprime(n);
    sum[1] = 1;
    for (int i = 2; i <= n; i++)
        sum[i] = sum[i - 1] + phi[i] * 2ll;

    for (int i = 1; i <= num; i++)
        ans += sum[n / pri[i]];
    printf("%lld\n", ans);
    return 0;
}

