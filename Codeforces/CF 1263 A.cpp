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
    int t; cin >> t;
    while(t--)
    {
        int a[3], ans;
        cin >> a[0] >> a[1] >> a[2];
        sort(a,a+3);
        ans=(a[0]+a[1]+a[2])/2;
        ans=min(ans,a[0]+a[1]);
        cout << ans << endl;
    }
}
