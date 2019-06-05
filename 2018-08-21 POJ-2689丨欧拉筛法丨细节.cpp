/*http://poj.org/problem?id=2689
���⣺һ��ʼ�Ҷ����ˣ����²��˺ܾá�
Ҫ���������������������С�������
˼·������Ƚ�С������Ԥ����С������ɸ��������ĺ�����Ȼ����ҡ�
��˼����ЩСϸ�ڻ�Ҫ��ע�⡣
*/

#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long ll;
const int N = 1 << 16 | 1;
const int M = 1e6 + 5;
bool vis[N];
int pri[6545], num;

void getprime()//ŷ��ɸ��������
{
    vis[1] = true;
    for (int i = 2; i < N; i++) {
        if (!vis[i])pri[++num] = i;
        for (int j = 1; j <= num && pri[j] * i < N; j++) {
            vis[pri[j] * i] = true;
            if (i % pri[j] == 0)break;
        }
    }
}

bool visp[M];
int stk[M], top;

void solve(int l, int r)//������ѡ��ɸȥ������ĺ�����Ȼ�����
{
    memset(visp, false, sizeof(visp));
    top = 0;
    for (int a, b, p, i = 1; i <= num && pri[i] <= r; i++) {
        p = pri[i];
        a = (l - 1) / p + 1, b = r / p;//����p���ܻᳬ��l����ֹһ��a���0��
        for (int j = a; j <= b; j++)
            if (j > 1)visp[j * p - l] = true;
        //ע��j==1��ʱ��1*p���һЩ����ɸȥ
    }
    for (int i = 0; i <= r - l; i++)
        if (!visp[i])
            stk[++top] = i + l;
}

int main() {
    getprime();
    int l, r, a, b, c, d;
    while (scanf("%d%d", &l, &r) != EOF) {
        if (l == 1)l = 2;
        solve(l, r);
        if (top < 2) {
            puts("There are no adjacent primes.");
            continue;
        }
        c = a = stk[1];
        d = b = stk[2];
        for (int i = 3; i <= top; i++)//ö��һ����������
        {
            if (stk[i] - stk[i - 1] < b - a)
                a = stk[i - 1], b = stk[i];
            if (stk[i] - stk[i - 1] > d - c)
                c = stk[i - 1], d = stk[i];
        }
        printf("%d,%d are closest, %d,%d are most distant.\n", a, b, c, d);
    }
    return 0;
}
/*
2145483646
2146483647
2147483600
*/
