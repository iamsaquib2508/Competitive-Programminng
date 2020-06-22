#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 1e18

using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ll n, m, i, x;
    while(cin >> n >> m)
    {
        ll g=0, init, prev;;
        cin >> prev;
        init=prev;
        ffr(i,1,n)
        {
            cin >> x;
            g=gcd((x-prev),g);
            prev=x;
        }
        ll ans=-1;
        ffr(i,0,m)
        {
            cin >> x;
            if(g%x==0) ans=i+1;
        }
        if(ans==-1) cout << "NO\n";
        else cout << "YES\n" << init << ' ' << ans << endl;
    }
}
