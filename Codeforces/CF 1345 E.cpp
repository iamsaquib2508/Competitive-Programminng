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

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

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
    
    int n, m;
    while(cin >> n >> m)
    {
        int i, x, y, cnt=0;
        char a[200005];
        ffr(i,0,n) a[i]='A';
        ffr(i,0,m)
        {
            cin >> x >> y;
            x--; y--;
            a[maxx(x,y)]='E';
        }
        ffr(i,0,n)
        {
            if(a[i]=='E')
            cnt++;
        }
        if(cnt==n)
        {
            cout << "-1\n";
        }
        else
        {
            cout << n-cnt << endl;
            ffr(i,0,n)
            {
                cout << a[i];
            }
            cout << endl;
        }
    }
}
