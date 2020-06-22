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
#define bug(x) cerr << #x << " = " << x << endl

using namespace std;

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

ll gcd(ll a, ll b)
{
    if (b==0) return a;
    return gcd(b, a%b);
}

int mymod(int n, int mod)
{
    if(n%mod==0) return 0;
    if(n<0)
    {
        n=-n; n%=mod; return mod-n;
    }
    return n%mod;
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        int n, i, temp, x;
        bool fel=0, a[200005]; mm(a,0);
        cin >> n;
        ffr(i,0,n)
        {
            cin >> x;
            temp=(i+mymod(x, n))%n;
            if(a[temp]==0) a[temp]=1;
            else fel=1;
        }
        if(fel) cout << "NO\n";
        else cout << "YES\n";
    }
}
