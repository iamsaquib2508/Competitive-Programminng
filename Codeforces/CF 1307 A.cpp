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
#define bug(x) ;//cerr << #x << " = " << x << endl

using namespace std;

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        ll n, d, ans, x, i, temp;
        cin >> n >> d;
        cin >> ans;
        ffr(i,1,n)
        {
            cin >> x;
            temp=minn(d/i,x);
            d-=temp*i;
            ans+=temp;
        }
        cout << ans << endl;
    }
}
