#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define pf printf
#define ll long long int
#define ff first
#define ss second
#define sf(a) scanf("%d", &a)
#define CMAX 30002

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

ll mod=998244353;

ll bm(ll a, ll p)
{
    if(p==0) return 1;
    ll x=bm(a,p/2);
    x=x*x; x%=mod;
    if(p&1) x=(x*a)%mod;
    return x;
}

int main()
{
    ll t, pp, ans=0, i, c, e, inv;
    ll p[200005];
    while(cin >> t)
    {
        ffr(i,0,t)
        {
            cin >> pp;
            p[i]=pp;
            //ans+=bm(p,mod-2);
            //ans%=mod;
        }
        c=0, e=0;
        inv=bm(100,mod-2);
        ffr(i,0,t)
        {
            pp=(p[t-i-1]*inv)%mod;
            c=pp*c+1;
            c%=mod;
            e=pp*(e-1)+1;
            e%=mod;
        }

        cout << c * bm((mod+1-e),mod-2)%mod << endl;
    }
}
