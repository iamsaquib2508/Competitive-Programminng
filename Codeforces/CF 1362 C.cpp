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
    int tt, i; cin >> tt;
    ll spc[64];
    spc[0]=0; spc[1]=1;
    ffr(i,2,63)
    {
        spc[i]=2*spc[i-1]+i;
        //cout << spc[i] << endl;
    }
    while(tt--)
    {
        ll n, ans=0, temp;
        cin >> n;

        ffr(i,1,62)
        {
            temp=n&1;
            if(temp) ans+=spc[i-1]+i;
            n/=2;
        }
        cout << ans << endl;
    }
}
