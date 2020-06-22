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

int main()
{
    ll t, a, b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(gcd(a,b)==1) cout << "finite\n";
        else cout << "infinite\n";
    }
}
