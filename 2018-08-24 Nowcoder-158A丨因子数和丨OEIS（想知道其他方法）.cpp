/*https://www.nowcoder.com/acm/contest/158/A
OEIS����һ���ǳ���ƫ�����������������Ҫ��ѧ����
��л�ζ�ѧ��QAQ
������������ôд�ģ���
*/
#include<bits/stdc++.h>

using namespace std;
const int N = 80005;
typedef long long ll;
int stk1[N], top1;
int stk2[N], top2;

///��ݴ����ǣ���\sum{k=1...n} n/k(���������OEIS)
int main() {
    int n, q;
    double ans;
    scanf("%d", &q);
    while (q--) {
        top1 = top2 = 0;
        scanf("%d", &n);
        int lim = round(sqrt(n));
        for (int i = 1; i <= lim; i++) {
            if (!top1 || n / i != stk2[top2]) {
                stk1[++top1] = i;
                stk2[++top2] = n / i;
            }
        }
        while (top2 && stk1[top1] >= stk2[top2])top2--;
        while (top2)stk1[++top1] = stk2[top2--];

        ll ans = 0, cnt = n;
        for (int i = 2; i <= top1; i++) {
            ans += (cnt - n / stk1[i]) * stk1[i - 1];
            cnt = n / stk1[i];
        }
        ans += n;
        printf("%lld\n", ans);
    }
    return 0;
}

/*
10
1 2 3 4 5 6 7 8 9 10
*/
