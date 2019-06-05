#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

const int MAXN = 3000;
const int INF = 0x3f3f3f3f;
typedef long long ll;
ll f[25];

int main() {
    for (int i = 1; i <= 20; i++)
        f[i] = f[i - 1] * (i - 1) + 1;
    int n;
    ll m;
    while (scanf("%d%lld", &n, &m) != EOF) {
        std::vector<int> x;//��̬����
        for (int i = 0; i <= n; i++)
            x.push_back(i);//����̬�������{0������n}
        while (m && n) {
            int t = (m - 1) / f[n] + 1;
            printf("%d ", x[t]);
            x.erase(x.begin() + t);//ɾ��t��λ��Ԫ�أ��±�˳��
            m -= (m - 1) / f[n] * f[n--] + 1;
        }
        puts("");
    }
    return 0;
}
/*
������Ҫö��һ��4�뷨������һЩ
1
1 2
1 2 3
1 2 3 4
1 2 4
1 2 4 3
1 3
1 3 2
1 3 2 4
1 3 4
1 3 4 2
1 4
1 4 2
1 4 2 3
1 4 3
1 4 3 2
ö�ٶ��˻ᷢ�֣�ͬһ�����ֿ�ͷ�����и����ǹ̶��ġ����ҹ������㣩
����������������ʵ������ġ�
���Կ��Բ���ȥ��m����һ�飬�Ϳ��Բ���ȷ��ÿһλ�����ˡ�
�е���˼��
*/
