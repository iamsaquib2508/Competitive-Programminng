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

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int fixer(int i, int dod, int n)
{
    return (dod+i)%n;
}

ll mod=1000000007;

ll bm(ll a, ll p)
{
    if(p==0) return 1ll;
    ll x=bm(a,p/2);
    x=(x*x)%mod;
    if(p&1) x=(x*a)%mod;
    return x;
}

int main()
{
    string s;
    while(cin >> s)
    {
        ll sz=s.size(), i, cur, a[100005]={};
        ll ans=1;
        a[0]=1;
        if(s[0]=='m' || s[0]=='w') a[1]=0;
        else
        {
            a[1]=1;
            ffr(i,1,sz)
            {
                if(s[i]=='m' || s[i]=='w')
                {
                    a[sz]=0; break;
                }
                else if(s[i]=='n' || s[i]=='u')
                {
                    if(s[i-1]==s[i])
                    {
                        a[i+1]=a[i]+a[i-1];
                        while(a[i+1]>=mod) a[i+1]-=mod;
                    }
                    else a[i+1]=a[i];
                }
                else a[i+1]=a[i];
            }
        }
        cout << a[sz] << endl;
    }
}
