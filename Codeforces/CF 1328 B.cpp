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

ll ncr(ll n, ll r)
{
    if(r==2) return n*(n-1)/2;
    if(r==1) return n;
    if(r==0) return 1;
}

void print(ll n, ll r, ll k)
{
    if(n==r)
    {
        int i;
        ffr(i,0,n)
        {
            cout << 'b';
        }
        return;
    }
    ll temp=ncr(n-1,r);
    if(temp<k)
    {
        //b
        cout << 'b';
        r--;
        n--;
        k-=temp;
        print(n,r,k);
    }
    else
    {
        cout << 'a';
        n--;
        print(n,r,k);
    }
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        ll n, r, k;
        cin >> n >> k;
        print(n, 2, k);
        cout << endl;
    }
}
