#include<bits/stdc++.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


int main() {
    srand((unsigned) time(NULL));
    int a[] = {1, 2, 3, 4, 5, 6};
    shuffle(a, a + 6, rand);
    for (int i = 1; i <= 6; ++i) {
        cout << a[i - 1] << " ";
    }
}