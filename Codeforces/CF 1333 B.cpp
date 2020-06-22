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

int main()
{
    int ttt; cin >> ttt;
    while(ttt--)
    {
        int n, x, a[100005], i;
        ffr(i,0,n)
        {
            cin >> x;
            a[i]=x;
        }
        bool failed=0, got1=0, gotmin1=0;
        ffr(i,0,n)
        {
            cin >> x;
            if(x>a[i])
            {
                if(!got1) failed=1;
            }
            else if(x<a[i])
            {
                if(!gotmin1) failed=1;
            }
            if(x==1) got1=1;
            else if(x==-1) gotmin1=1;

        }
        if(!failed) cout << "YES\n";
        else cout << "NO\n";
    }
}
