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
    int t, x, n, ans, i, a[200005];
    cin >> t;
    while(t--)
    {
        mm(a,-1);
        cin >> n;
        ans=200005;
        ffr(i,0,n)
        {
            cin >> x;
            if(a[x]>=0)
            {
                ans=minn(ans,i-a[x]+1);
            }
            a[x]=i;
        }
        if(ans==200005) ans=-1;
        cout << ans << endl;

    }
}
