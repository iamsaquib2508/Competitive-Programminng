#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define pf printf

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


ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, i;
        cin >> n;

        ll l, r, lll=0, rrr=1000000009;
        ffr(i,0,n)
        {
            cin >> l >> r;
            rrr=minn(rrr,r);
            lll=maxx(lll,l);
        }
        if(n==1 || lll<=rrr) cout << "0\n";
        else cout << lll-rrr << endl;
    }
}
