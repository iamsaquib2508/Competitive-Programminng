#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int minn(int a, int b)
{
    if(a<b) return a; return b;
}


int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        int n, a[502], t[502], x, z, o, i;
        cin >> n;
        ffr(i,0,n)
        {
            cin >> a[i];
            t[i]=a[i];
        }
        z=0; o=0;
        ffr(i,0,n)
        {
            cin >> x;
            if(x==0) z=1;
            else o=1;
        }
        string ans="Yes\n";
        if(z!=1 || o!=1)
        {
            sort(t,t+n);
            ffr(i,0,n) if(a[i]!=t[i]) break;
            if(i<n) ans="No\n";
        }
        cout << ans;
    }
}
