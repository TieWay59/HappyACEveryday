#include <stdio.h>

int n;
int ans, num;
int a[1005];
int b[1005];


int main() {

//    freopen("C:\\Users\\acm-33\\Desktop\\校赛签到题\\冒泡中位数\\data\\1.in", "r", stdin);

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

                b[k]++;
                num++;
            }
        }
    }

    for (int i = 1, cnt = 0; i <= 1000; ++i) {
        cnt += b[i];
        if (num % 2 == 1 && cnt > num / 2) {
            ans = i;
            break;
        }
        if (num % 2 == 0 && cnt >= num / 2) {
            ans = i;
            break;
        }
    }

    printf("%d\n", ans);
    return 0;
}
/*

 */