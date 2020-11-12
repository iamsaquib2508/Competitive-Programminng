#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define bug cout << "hello\n"
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

int maxx(int a, int b){
    if(a>b) return a; return b;
}

int main(){
    int tt; cin >> tt;
    while(tt--){
        int n, x, i, ans=-1, m;
        cin >> n >> m;
        bool a[1005];
        ffr(i,0,1002) a[i]=0;
        ffr(i,0,n){
            cin >> x;
            a[x]=1;
        }
        ffr(i,0,m){
            cin >> x;
            if(a[x]==1) ans=x;
        }
        if(ans>=0)
        cout << "YES\n1 " << ans << endl;
        else cout << "NO\n";
    }
    //cin >> tt;
}
