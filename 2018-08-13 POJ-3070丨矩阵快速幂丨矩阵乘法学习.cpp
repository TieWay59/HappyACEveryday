#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const long long mo = 10000;

struct Matrix {
    int r, c;
    ll a[5][5];//�޸ĵ�
    void clear()//��վ���
    {
        r = c = 0;
        memset(a, 0, sizeof a);
    }

    Matrix operator*(const Matrix t) {//r==t.c;
        int s = min(c, t.r);//Ӧ�Բ���ȵ����
        Matrix ret;
        ret.clear();
        ret.r = ret.c = r;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                for (int k = 1; k <= s; k++)
                    ret.a[i][j] = (ret.a[i][j] + a[i][k] * t.a[k][j] % mo) % mo;
        return ret;
    }

    void eye(int x) {
        clear();
        r = c = x;
        for (int i = 1; i <= x; i++)
            a[i][i] = 1;
    }
};

Matrix fpow(Matrix a, ll b) {
    Matrix ans;
    ans.clear();
    ans.r = 2, ans.c = 1;
    ans.a[1][1] = 1;
    ans.a[2][1] = 0;
    while (b) {
        if (b & 1)ans = a * ans;//�˷���˳����������
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int main() {
    ll n;
    Matrix st;
    st.clear();
    st.r = 2, st.c = 2;
    st.a[1][1] = 1, st.a[1][2] = 1;
    st.a[2][1] = 1, st.a[2][2] = 0;

    while (scanf("%lld", &n) != EOF && n != -1) {
        Matrix ans = fpow(st, n);
        printf("%lld\n", ans.a[2][1]);
    }
    return 0;
}
