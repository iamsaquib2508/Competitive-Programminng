#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}


ll minn(ll a, ll b)
{
    if(a>b) return b; return a;
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        int h, n, m;
        cin >> h >> n >> m;
        while(n)
        {
            if(h<=m*10) break;
            h/=2; h+=10;
            n--;
        }
        while(m)
        {
            if(h<=0) break;
            h-=10;
            m--;
        }
        if(h<=0)
        {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}
