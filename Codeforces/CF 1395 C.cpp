#include <bits/stdc++.h>
#define ull uint64_t
#define uint uint32_t
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define xx first
#define yy second
#define mp make_pair

using namespace std;

int minn(int a, int b){
    if(a<b) return a; return b;
}

int maxx(int a, int b){
    if(a>b) return a; return b;
}

int main(){
    int tt=1;
    //cin >> tt;
    while (tt--) {
        int n, m, i, j, a[202], b[202], cur, ans=0;
        cin >> n >> m;
        ffr(i,0,n){
            cin >> a[i];
        }
        sort(a,a+n);
        ffr(i,0,m){
            cin >> b[i];
        }
        ffr(i,0,n){
            cur=1024;
            ffr(j,0,m){
                cur = minn(cur,(a[n-1-i]&b[j]));
            }
            ans=maxx(cur,ans);
        }
        ffr(i,0,n){
            cur=1024;
            ffr(j,0,m){
                cur = minn(cur,(a[n-1-i]&b[j])|ans);
            }
            ans=cur;
        }
        cout << ans << endl;
    }
    cin >> tt;
}
