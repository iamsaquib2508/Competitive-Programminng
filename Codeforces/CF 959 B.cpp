




/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define xx first
#define yy second
#define PI acos(-1.0)
#define mp make_pair

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */

#define MX 100005
#define inf 100000000000000017


int main()
{
    ll n, m, k, t, x, i, j, tt[MX], cost[MX], ans=0, mn;
    string str;
    map<string,ll> mp;
    cin >> n >> k >> m;
    
    ffrr(i,1,n)
    {
        cin >> str;
        mp[str]=i;
    }
    ffrr(i,1,n)
    {
        cin >> cost[i] ;
    }
    ffr(j,0,k)
    {
        cin >> x;
        mn=inf;
        ffr(i,0,x)
        {
            cin >> t;
            tt[i]=t;
            mn=min(mn,cost[t]);
        }
        ffr(i,0,x)
        {
            
            cost[tt[i]]=mn;
        }
    }
    ffr(i,0,m)
    {
        cin >> str;
        t=mp.find(str)->second;
        ans+=cost[t];
    }
    
    cout << ans << endl;
    
    return 0;
}
