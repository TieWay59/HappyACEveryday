/** http://codeforces.com/contest/1008/problem/D
  * ����һ���ݳ�ԭ�����Ĵ��룬���Ƿǳ�����
  * �ҵ��Ķ�������������ȫ��͸��ֻ��ǳҪ�ķ�����
  */

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int nump[maxn];

void init() {
    for (int i = 1; i < maxn; i++)
        for (int j = i; j < maxn; j += i)
            nump[j]++;
}

int cal(int a, int b, int c) {
    int res = nump[a] * nump[b] * nump[c];
    int ab = __gcd(a, b);
    int bc = __gcd(b, c);
    int ac = __gcd(a, c);
    int abc = __gcd(ab, bc);
    //��ʾ�����ߵ�������
    int A = nump[a];
    int B = nump[b];
    int C = nump[c];
    //��ʾ��������
    int AB = nump[ab];
    int AC = nump[ac];
    int BC = nump[bc];
    int ABC = nump[abc];

    res -= A * (BC - 1) * BC / 2;
    //����B�ߺ�C��ȡһ����������ΪС����߳���-1����������������ȡ�������ظ���/2��
    res -= B * (AC - 1) * AC / 2;
    res -= C * (AB - 1) * AB / 2;
    res -= AB * BC * AC;
    //��ȥ�����߶�ȡ���߹����ӵ����

    res += ABC * (BC * AC + BC * AB + AB * AC);
    //�������߹����Ӻ����߹����ӵ���ϣ����������Σ�

    res -= ABC * (ABC + 1) * (AB + BC + AC) / 2;
    //�ų�ȡ������������+һ��˫���ߵ��������+1�ǣ�ȡ��һ�������ߺ�����˫���ߵ����

    res += ABC * (ABC + 1) * (ABC + 2) / 6;
    //���ϣ�ȡ1��2��3�������ߵ����
    return res;
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    int a, b, c;
    while (T--) {
        scanf("%d%d%d", &a, &b, &c);
        printf("%d\n", cal(a, b, c));
    }
    return 0;
}
