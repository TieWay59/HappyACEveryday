
/*
// O(N^2)
template<const int BCSize> //add Mod as parameter;
struct Binomial_Coefficient {
    int c[BCSize + 1][BCSize + 1];
    //Pascal's Triangle

    Binomial_Coefficient() {    //add Mod as parameter;
        c[0][0] = 1;
        for (int n = 1; n <= BCSize; ++n) {
            c[n][0] = c[n][n] = 1;
            for (int k = 1; k < n; ++k)
                c[n][k] = c[n - 1][k - 1] + c[n - 1][k];
            //c[n][k] = (c[n - 1][k - 1] + c[n - 1][k])%;
        }
    }

    int operator()(const int &n, const int &m) {
        if (n < m)return -1;//in case.
        return c[n][m];
    }
};

Binomial_Coefficient<5> C=Binomial_Coefficient<5>();

*/
//********in normal writing style***********

const int MAXN = 20;
int C[MAXN + 1][MAXN + 1];

inline void pascal(const int &maxn) {
    C[0][0] = 1;
    for (int n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
        //C[n][k] =( C[n - 1][k - 1] + C[n - 1][k])%;
    }
}

//int main() {
//
//    /*
//    cout << C(4, 3) << endl;
//    cout << C(4, 1) << endl;
//    cout << C(5, 2) << endl;
//    */
//
//    cout << C[4][3] << endl;
//    cout << C[4][1] << endl;
//    cout << C[5][2] << endl;
//
//    return 0;
//}
/*




 * */