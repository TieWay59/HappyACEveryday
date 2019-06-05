#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 1000005;
const int INF = 0x3f3f3f3f;
int a[MAXN], c[MAXN], n;
long long ans;

/*
如果归并排序用到了二分的思想，
在排序过程中如果a[i]<=a[j]就不会产生逆序对，
如果a[i]>a[j]就会产生mid−i+1个逆序对，
因为做归排的时候l-mid和mid+1-r都是已经排好序的
所以如果a[i]>a[j]那么a[i+1]-a[mid]也就都大于a[j]，
*/
void MSort(int l, int r) {
    if (l == r)return;
    int m = (l + r) >> 1;
    MSort(l, m);
    MSort(m + 1, r);
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++],
                    ans += (m - i + 1);
    }
    while (i <= m)
        c[k++] = a[i++];
    while (j <= r)//r mistake for l
        c[k++] = a[j++];
    for (int i = l; i <= r; i++)
        a[i] = c[i];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    MSort(1, n);
    printf("%lld\n", ans);
    return 0;
}
/*
5
3 3 2 1 3

*/
