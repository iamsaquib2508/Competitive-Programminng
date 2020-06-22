#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
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

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int x, y; bool ans=0;
        cin >> x >> y;
        if(x==1)
        {
            if(y==1) ans=1;
        }
        else if(x<=3 && y<=3)
        {
            ans=1;
        }
        else if(x>3) ans=1;
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}
