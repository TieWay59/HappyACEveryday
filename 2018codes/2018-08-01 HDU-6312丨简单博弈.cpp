/** http://acm.hdu.edu.cn/showproblem.php?pid=6312
  * 题意：给一个集合，每个回合去取一个数，和所有因子
  * 不能取的时候为负
  * 思路：首先观察到1是属于所有数的因子，取任何数都会一同带走1
  * 所以1是一个或有或无的数字
  * 然后这题暗示先手或后手
  * 有可能是必胜的，假设先手必胜，那就必胜，
  * 如果后手必胜，那先手取掉1，就变成了后手，必胜了
  * 因为取走1并不会影响整体的次数，而改变了先手后手
  */

#include<bits/stdc++.h>

using namespace std;
const int N = 2001;
int n;

int main() {
    while (~scanf("%d", &n)) {
        puts("Yes");
    }
    return 0;
}
/*
*/
