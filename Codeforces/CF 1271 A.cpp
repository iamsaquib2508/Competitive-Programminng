#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

int main()
{
    ll a, b, c, d, e, f;
    while(cin >> a >> b >> c >> d >> e >> f)
    {
        ll ans=0, i;
        ffrr(i,0,d)
        {
            ans=maxx(minn(a,i)*e+minn(minn(b,c),d-i)*f,ans);
        }
        cout << ans << endl;
    }
}
