#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}


ll minn(ll a, ll b)
{
    if(a>b) return b; return a;
}

ll n, k;
vector<ll> v[200005];
vector<ll> ans;

ll dfs(ll s, ll par=-1, ll prev=0)
{

    if(v[s].size()==1 && v[s][0]==par)
    {
        //leaf
        //cout << prev << endl;
        ans.pb(prev);
        return 1;
    }
    ll sum=0;
    for(ll vv:v[s])
    {
        if(vv==par) continue;

        sum+= dfs(vv, s, prev+1);
    }
    ans.pb(prev-sum);
    return sum+1;
}

int main()
{
    while(cin >> n >> k)
    {
        ll i, uu, vv;
        ffr(i,0,200005)
        {
            v[i].clear();
        }
        ans.clear();

        ffr(i,1,n)
        {
            cin >> uu >> vv;
            v[uu].pb(vv);
            v[vv].pb(uu);
        }
        dfs(1);
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        ll sum=0;
        ffr(i,0,k)
        {
            sum+= ans[i];
        }
        cout << sum << endl;
    }
}

/*
6 6
1 2
2 3
3 4
3 5
5 6
*/
