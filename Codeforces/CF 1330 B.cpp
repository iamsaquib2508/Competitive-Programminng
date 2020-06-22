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

int n;
vector<int> v, ans;

bool check(int from, int mx)
{
    map<int,int> mp;
    mp.clear();
    int i, x, mgot;
    mgot=0;
    ffr(i,0,mx)
    {
        x=v[i+from];
        mgot=max(mgot,x);
        if(mp.find(x)==mp.end())
        {
            mp[x]=1;
        }
        else return false;
    }
    if(mgot==mx)
    {
        return true;
    }
    else return false;
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        int i, j, x;

        v.clear();
        ans.clear();

        cin >> n;
        ffr(i,0,n)
        {
            cin >> x;
            v.pb(x);
        }
        //gofor(v, true);
        //reverse(v.begin(),v.end());
        int mx=0;
        ffr(i,0,n)
        {
            x=v[i];
            if(x>mx)
            {
                mx=x;

            }
        }
        if ( check(0, mx) && check(mx, n-mx) )
        {
            ans.pb(mx);
            ans.pb(n-mx);

        }
        if ( mx+mx!=n && check(0, n-mx) && check(n-mx, mx) )
        {
            ans.pb(n-mx);
            ans.pb(mx);

        }

        cout << ans.size()/2 << endl;
        ffr(i,0,ans.size())
        {
            cout << ans[i] << ' ' << ans[i+1] << endl;
            i++;
        }

    }
}
