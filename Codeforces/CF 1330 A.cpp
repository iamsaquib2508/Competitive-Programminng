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
    int tt; cin >> tt;
    while(tt--)
    {
        int n, k, i, x, a[500]={}, id;
        cin >> n >> k;
        ffr(i,0,n) {cin >> x; a[x]=1;}
        id=1;
        while(k--)
        {
            while(a[id]==1) id++;
            id++;
        }
        while(a[id]==1) id++;
        cout << id-1 << "\n";
    }
}
