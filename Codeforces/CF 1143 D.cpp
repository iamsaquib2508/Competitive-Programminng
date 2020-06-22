#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back

using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ll n, k, a, b, aa, bb, cc, dd, temp, mx, mn, nk, ek, e;
    while(cin >> n >> k >> a >> b)
    {
        nk=n*k;
        ek=0;
        mn=nk; mx=0;
        ffr(e,1,n)
        {
            aa=b-a+ek;
            bb=b+a-k+ek;
            cc=-b-a+k+ek;
            dd=a-b+ek;
            if(aa>=0)
            {
                temp=gcd(aa,nk);
                mn=min(mn,temp);
                mx=max(mx,temp);
            }
            if(bb>=0)
            {
                temp=gcd(bb,nk);
                mn=min(mn,temp);
                mx=max(mx,temp);
            }
            if(cc>=0)
            {
                temp=gcd(cc,nk);
                mn=min(mn,temp);
                mx=max(mx,temp);
            }
            if(dd>=0)
            {
                temp=gcd(dd,nk);
                mn=min(mn,temp);
                mx=max(mx,temp);
            }
            ek+=k;
        }
        cout << nk/mx <<  ' ' << nk/mn << endl;
    }
}
