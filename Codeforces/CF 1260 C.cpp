#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define pf printf
#define PI acos(-1.0)

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

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int main()
{
    ll t, r, b, k;
    cin >> t;
    while(t--)
    {
        cin >> r >> b >> k;
        if(r==b) cout << "OBEY\n";
        else
        {
            if(r>b) {int temp=r; r=b; b=temp;}
            if(b%r==0)
            {
                if(b/r-1>=k) cout << "REBEL\n";
                else cout << "OBEY\n";
            }
            else
            {
                if((b-gcd(r,b)-1)/r+1>=k) cout << "REBEL\n";
                else cout << "OBEY\n";
            }
        }
    }
}
