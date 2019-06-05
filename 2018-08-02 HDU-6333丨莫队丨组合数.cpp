/** http://acm.hdu.edu.cn/showproblem.php?pid=6333
  * ���⣺��C(n,0)+C(n,1)+C(n,2)+ +C(n,m)�ĺ�
  * ˼·��Ҫ�������sigma ��Ϊ���� S(n,m)=S(n,m-1)+C(n,m)
  * S(n,m)=2*S(n-1,m)-C(n-1,m) Ȼ��ע������һ���������ѯ�ʣ�
  * ���Կ���Ī���㷨���Կ�������1��100000�Ľ׳��ǿ��Դ��µ�
  * ������C�ĸ��Ӷ���O��1����Ȼ�����S���Ƶ���ϵ���Ϳ���Ī����
  * ��˼���������˺ܾ�û��ͻ�ƿڣ���
  */

#include <bits/stdc++.h>

using namespace std;

const int N = 200000;
const int MOD = 1000000007;
struct query {
    int n, k, i;
} Q[N];
int T;
vector <query> lst[N];
int cnt, mx, chunk;
int fac[N], inv[N], res[N], in_chunk[N];

int powi(int a, int b)//����������Ԫ����ΪMOD������
{
    int c;
    for (c = 1; b; b >>= 1, a = 1ll * a * a % MOD)
        if (b & 1)c = 1ll * c * a % MOD;
    return c;
}

int C(int a, int b) {
    return 1ll * fac[a] * inv[b] % MOD * inv[a - b] % MOD;
    //����Ԫ��֪ʶ֪������������ڳ��Գ�������Ԫ��
}

bool comp(query _x, query _y) {
    return _x.n < _y.n;
}

int main() {
    mx = 100000;
    fac[0] = 1;
    for (int i = 1; i <= mx; i++)
        fac[i] = 1ll * fac[i - 1] * i % MOD;

    inv[mx] = powi(fac[mx], MOD - 2);
    for (int i = mx - 1; ~i; i--)
        inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;//��׳˵���Ԫ����Ȼ����ԭ�����������ǶԵġ�

    chunk = sqrt(mx);
    cnt = 1;

    for (int i = 1; i <= mx; i += chunk, ++cnt)
        for (int j = i; j < i + chunk && j <= mx; ++j)
            in_chunk[j] = cnt;//tag the in_chunk
    cnt--;

    scanf("%d", &T);
    for (int i = 1, tn, tm; i <= T; i++) {
        scanf("%d%d", &tn, &tm);
        Q[i] = {tn, tm, i};//my style
        lst[in_chunk[tm]].push_back(Q[i]);
    }

    for (int i = 1; i <= cnt; i++)
        if (lst[i].size()) {
            sort(lst[i].begin(), lst[i].end(), comp);
            int val = 0, in = lst[i][0].n, ik = -1;

            for (int j = 0; j < lst[i].size(); j++) {
                while (in < lst[i][j].n)//�ƶ�n
                    val = (0ll + val + val - C(in++, ik) + MOD) % MOD;//�ױ�int +0ll����*1ll
                while (ik < lst[i][j].k)//�ƶ�k
                    val = (val + C(in, ++ik)) % MOD;
                while (ik > lst[i][j].k)//�ƶ�k
                    val = (val - C(in, ik--) + MOD) % MOD;
                res[lst[i][j].i] = val;//��¼��
            }
        }

    for (int i = 1; i <= T; i++)
        printf("%d\n", res[i]);
    return 0;
}
