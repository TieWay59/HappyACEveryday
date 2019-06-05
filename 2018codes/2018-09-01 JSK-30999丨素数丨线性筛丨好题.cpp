#include<bits/stdc++.h>

using namespace std;
const int N = 2e7 + 1;
int p[N], v[N], a[N];

int main() {
    for (int i = 2; i < N; i++) {//����ɸ
        if (!v[i])p[++*p] = i;//*p��p[0]��¼����������
        for (int j = 1; j <= *p && i * p[j] < N; j++) {
            v[i * p[j]] = p[j];//v��¼i*p[j]����С�����ӣ�==0˵����������
            if (i % p[j] == 0)break;
        }
    }
    a[1] = 1;
    for (int i = 2, vi; i < N; i++) {
        vi = *(v + i);//vi��i����С������
        if (!vi) {
            a[i] = 2;//�����С������0�����������ı�ǣ�������=0
        } else {
            if (i % (vi * vi * vi) == 0)a[i] = 0;//����ܱ�����������������=0
            else if (i % (vi * vi) == 0)a[i] = a[i / vi] >> 1;//���ǡ���ܱ�����������������=ֻ��һ��vi�ķ�����/2
            else a[i] = a[i / vi] << 1;//���ǡ�ñ�һ��������������=û��vi�ķ�����/2
        }
    }
    for (int i = 2; i < N; i++)a[i] += a[i - 1];//�ۼӵõ��𰸡�
    int T, n;
    for (scanf("%d%d", &T, &n); T--; scanf("%d", &n))
        printf("%d\n", a[n]);

    return 0;
}
