#include <bits/stdc++.h>
#define ull uint64_t
#define uint uint32_t
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define xx first
#define yy second
#define mp make_pair

using namespace std;

int main(){
    int tt=1;
    //cin >> tt;
    while (tt--) {
        int n, m, xx, yy, k, i, x;
        cin >> n >> m >> xx >> yy;

        ffr(k,0,m){
            cout << xx << ' ' << yy << endl;
            ffrr(i,1,n){
                if(i==xx) continue;
                cout << i << ' ' << yy << endl;
                x=i;
            }
            yy++; if(yy>m) yy=1;
            xx=x;
        }
    }
    cin >> tt;
}
