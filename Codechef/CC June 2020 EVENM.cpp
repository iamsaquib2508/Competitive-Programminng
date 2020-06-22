#include <bits/stdc++.h>
#define ll int64_t
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back

using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int maxx(int a, int b){
    if(a>b) return a; return b;
}

int minn(int a, int b){
    if(a<b) return a; return b;
}

int main()
{
    int tt; cin >> tt;
    while(tt--){
        int n, put, i, j, ans[1002][1002];
        cin >> n;
        put=1;
        ffr(i,0,n){
            if(i&1){
                for(j=n-1;j>=0;j--) ans[i][j]=put++;
            }
            else{
                ffr(j,0,n) ans[i][j]=put++;
            }
        }
        ffr(i,0,n){
            ffr(j,0,n) cout << ans[i][j] << ' ';
            cout << '\n';
        }
    }
}
