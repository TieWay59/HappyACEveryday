/*http://acm.hdu.edu.cn/showproblem.php?pid=6264
����һ��ˮ�⣬�������޸Ķ��ٴΣ�ʹ������Ĵ��������ִ�Ϊ���Ĵ�
Ҫôababab������Ҫôaaaaaa��������ʽ
һ��ʼ��������õİ취�������ˮ�ⲻ����ô����
������set����ĸ��Ȼ��n^2�ĸ��Ӷ�ö��������ĸ
�жϻ�����ٳ�Ϊ���ڰ���䡱�����ͣ��п���ö�ٵ�������ͬ����ĸ
��ô��˳�����ˡ���һɫ�����жϡ�

�ʼ�ҷ���Ҳ���˵����⣬��Ϊabababż����ʱ���ǲ����е�
�����ַ����㷨��©������ʱ�����ҳ�������������ĸ
�������Ϊ������һ�¡��ڰ���䡱�ı仯�����Ϳ�����
ʵ����ԶԶ������
����������ˮ�������ҲҪ��߰�������
*/
#include<bits/stdc++.h>

using namespace std;
const int N = 89444;
int T;
char str[155];
set<char> sav;
typedef set<char>::iterator sit;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        int l = strlen(str);
        for (int i = 0; i < l; i++)
            sav.insert(str[i]);

        int ans = 0x3f3f3f3f;
        for (sit it = sav.begin(); it != sav.end(); it++)
            for (sit jt = sav.begin(); jt != sav.end(); jt++) {
                char c[2] = {(*it), (*jt)};
                int res = 0;
                for (int tag = 0, i = 0; i < l; i++, tag ^= 1)
                    if (str[i] != c[tag])res++;
                ans = min(ans, res);
            }
        printf("%d\n", ans);
        sav.clear();
    }
    return 0;
}
/*
3
ncncn
aaaaba
aaaabb
*/
