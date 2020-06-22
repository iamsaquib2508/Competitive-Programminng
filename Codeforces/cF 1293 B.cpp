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
    int i, n;
    while(cin >> n)
    {
        double ans=0.0;
        ffrr(i,1,n)
        {
            ans+=(1.0/i);
        }
        cout << ans << endl;
    }
}
