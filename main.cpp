/**
  *    █████╗  ██████╗       ██████╗ ██╗     ███████╗
  *   ██╔══██╗██╔════╝       ██╔══██╗██║     ╚══███╔╝
  *   ███████║██║            ██████╔╝██║       ███╔╝ 
  *   ██╔══██║██║            ██╔═══╝ ██║      ███╔╝  
  *   ██║  ██║╚██████╗▄█╗    ██║     ███████╗███████╗
  *   ╚═╝  ╚═╝ ╚═════╝╚═╝    ╚═╝     ╚══════╝╚══════╝
  *
  *  @Author: TieWay59
  *  @Created: 2019/11/27 17:40
  *  @Link: wdnmd
  *  @Tags: 
  *
  *******************************************************/


#include <bits/stdc++.h>

#ifdef DEBUG
//#define debug(x)  cerr <<#x << " = "<<x<<endl;
#include "libs59/debugers.h"

#else
#define endl '\n'
#define debug(...)  59
#endif

#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
typedef long long ll;
const int MAXN = 2e5 + 59;
const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll llINF = 0x3F3F3F3F3F3F3F3F;
using namespace std;

string to_String(int x) {
    stringstream ss;
    ss << x;
    return string(ss.str());
}

int main() {
    string fileName;
    ifstream cdin, cdout;
    for (int SysCase = 1; SysCase <= 3; SysCase++) {
//        fileName = to_String(SysCase) + ".in";
//        cdin = ifstream(fileName);
//        fileName = to_String(SysCase) + ".out";
//        cdout = ifstream(fileName);

        int Kase;
        string str;
        cdin >> Kase;
        for (int kase = 1; kase <= Kase; kase++) {
            int ans = 0;
            int jury_ans = 0;
            int n;
            cdin >> n;
            cdin >> str;
            cdout >> jury_ans;
            for (const auto &si:str) {
                if (si == '_')ans++;
            }
            if (jury_ans != ans) {
                debug(str);
                debug(ans);
                debug(jury_ans);
                cout << "Wrong Answer on test #" << SysCase << endl;
                cout << "at case #" << kase << endl;
                /*
                 * sahsalshla
                 * sahishoaisioa
                 *
                 *
                 */
                exit(0);
            }
        }

        cout << "Accepted on test #" << SysCase << endl;
        cdin.close();
        cdout.close();
    }

    return 0;
}
/*



 */