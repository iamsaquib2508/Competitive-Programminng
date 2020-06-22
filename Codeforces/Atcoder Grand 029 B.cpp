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

using namespace std;
ll a[200005];

int main()
{
    ll n, i, x;
    map<ll,ll> mp;
    while(cin >> n)
    {
        ll ans=0;

        mp.clear();
        ffr(i,0,n)
        {
            cin>> x;
            a[i]=x;
            mp[x]++;
        }
        sort(a,a+n);
        for(i=n-1;i>=0;i--)
        {
            ll cur=a[i];
            if(mp[cur]==0)
            {
                continue;
            }
            ll p2=1;
            while(p2<=cur) p2+=p2;
            ll req=p2-cur;
            if(req==cur)
            {
                if(mp[cur]>1)
                {
                    mp[cur]-=2;
                    ans++;
                }
            }
            else if(mp.find(req)!=mp.end() && mp[req]>0)
            {
                mp[cur]--;
                mp[req]--;
                ans++;
            }


        }
        cout << ans << endl;

    }
}
