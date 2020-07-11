#include <stdio.h>
#include <algorithm>

using namespace std;
int n;
int ans, num;
int a[1005];
int b[1000005];

int main() {

//    freopen("C:\\Users\\acm-33\\Desktop\\校赛签到题\\冒泡中位数\\data\\10.in", "r", stdin);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 1, k; j < i; ++j) {
            if (a[j] > a[j + 1]) {
                k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
                b[++num] = k;
            }
        }
    }
    sort(b + 1, b + 1 + num);
    if (num % 2 == 1)printf("%d\n", b[num / 2 + 1]);
    else printf("%d\n", b[num / 2]);
    return 0;
}
/*

 */