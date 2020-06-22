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
    int t; cin >> t;
    while(t--)
    {
        int n, x, i, ev=0, od=0;
        string ans;
        cin >> n;
        ffr(i,0,n)
        {
            cin >> x;
            if(x&1) od++;
            else ev++;
        }
        if(od&1) ans="YES\n";
        else
        {
            if(od>0 && ev>0) ans="YES\n";
            else ans="NO\n";
        }
        cout << ans;
    }
}
