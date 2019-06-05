#include <bits/stdc++.h>

typedef long long ll;
const int N = 1e7 + 5;
int que[N], a[N];//��ʹ����Ԫ�ض���ӣ�Ҳ���㹻�ġ�
int Front, Rear;
int T, n, m, k, p, q, r, mo;
ll ansA, ansB;

/*
���⣺����һ�����У����������ֵ�������ֵ�ĸ��´�����
���±�����������������
˼·���ǻ��������ֵ��ά��һ��˫��ĵ������У���ĩ�˵�����ƶ�
a[i]��ĩ�˴󣬾Ͱ�i���±�����β����֮�Ͷ�β���ӣ�ֱ���ӿջ��߶�β����a[i]
Ȼ��Ҫ�������Ƿ���i��i+m-1�������ڣ���������ˣ�˵���Ѿ����봰�ڣ���Ҫ����
��˼������������ʱ��˼·������ģ���ʵ��Ҳ��ʶ����Ҫά��һ��ջ���߶��еĽṹ
���ͣ��һ�µ㣬û�о����������룬����û������
���������Ժ󣬺���Ҳ�����ң��Ĵ�����⣬Ȼ���Լ�����С����һֱ����
������ϸ��һЩ��

*/
int main() {
    scanf("%d", &T);
    while (T--) {
        Front = Rear = 0;
        ansA = ansB = 0;
        scanf("%d %d %d %d %d %d %d",
              &n, &m, &k, &p, &q, &r, &mo);

        for (int i = 1; i <= k; i++)
            scanf("%d", &a[i]);

        for (int i = k + 1; i <= n; i++)
            a[i] = (p * 1ll * a[i - 1] + q * 1ll * i + 1ll * r) % mo;
        //����int���

        for (int i = n; i >= 1; i--) {

            while (Front < Rear && a[que[Rear]] <= a[i])Rear--;
            que[++Rear] = i;//���±���ӣ������ж��Ƿ����
            while (Front < Rear && que[Front + 1] > i + m - 1)Front++;

            if (i <= n - m + 1) {
                //printf("%d ",(Rear-Front));
                ansA += (i * 1ll) ^ (a[que[Front + 1]] * 1ll);
                ansB += (i * 1ll) ^ ((Rear - Front) * 1ll);
            }
        }
        printf("%lld %lld\n", ansA, ansB);
    }
    //�����������Ҳ�����ӣ������Լ�����ϸ�µ�ԭ�����������
    //**sigh**

    return 0;
}
/*
1
10 1 10 5 5 5 5
3 2 2 1 5 7 6 8 2 9

1
10 6 10 5 5 5 5
3 2 2 1 5 7 6 8 2 9

1
10 6 10 5 5 5 5
0 0 0 0 0 0 0 0 0 0
*/
