#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define pf printf
#define ll long long int

using namespace std;

ll mul(ll a, ll b, ll m);

ll bm(ll a, ll p, ll m)
{
    if(p==0) return 1ll;
    if(a==1) return 1ll;
    if(p==1) return a%m;
    ll x=bm(a,p/2,m);
    //x=(x*x)%m;
    x=mul(x,x,m);
    if(p&1) //x=(x*a%m)%m;
    x=mul(x,a%m,m);
    return x;
}

ll mul(ll a, ll b, ll m)
{
    if(b==0) return 0ll;
    if(b==1ll) return a;
    ll x=mul(a,b/2,m);
    x+=x; x%=m;
    if(b&1) x=(x+a%m)%m;
    return x;
}

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main()
{
    ll a, b, n, ans, g, p, q, m, x, M=1000000007, T;
    cin >> T;
    while(T--)
    {
        cin >> a >> b >> n;
        if(a==b)
        {
            ans=bm(b,n,M);
            ans+=ans; ans%=M;
        }
        else
        {
            if(a<b){ll t=a; a=b; b=t;}
            m=a-b;
            //cout << p << q << m << endl;
            x=bm(b,n,m);
            x+=x; x%=m;
            //cout << x << endl;
            //error
            ans=(gcd(m,x))%M;
        }
        cout << ans << endl;
    }
    return 0;
}
