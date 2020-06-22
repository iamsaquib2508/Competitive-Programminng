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
    int t; cin >> t;
    while(t--)
    {
        ll n, k, cnt=0, l, temp;
        cin >> n;
        while(n>0)
        {
            l=1;
            while(1)
            {
                temp=(3*l-1);
                if(n>=temp) n-=temp;
                else break;
                l++;
            }
            if(l==1) break;
            cnt++;
        }
        cout << cnt << endl;
    }
}
