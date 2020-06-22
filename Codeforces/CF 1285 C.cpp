#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define mp make_pair

using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ll x;
    while(cin >> x)
    {
        ll sq=sqrt(x)+1;
        if(sq*sq>x) sq--;
        while(1)
        {
            if(x%sq==0 && gcd(x/sq,sq)==1) break;
            sq--;
        }
        cout << sq << ' ' << x/sq << endl;
    }
}
