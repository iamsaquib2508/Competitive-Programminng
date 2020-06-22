#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
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
ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}


int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, x, i;
        cin >> n;
        int a[n+2];
        ffrr(i,1,n)
        {
            cin >> x;
            a[x]=i;
        }
        int boro=0, coto=n+1;
        ffrr(i,1,n)
        {
            coto=minn(coto,a[i]);
            boro=maxx(boro,a[i]);
            if(1-coto+boro<=i) cout << "1";
            else cout << "0";
        }
        cout << endl;
    }
}
