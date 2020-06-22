#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define max(q,w) (q<w)? w:q
#define min(q,w) (q>w)? w:q

using namespace std;

int main()
{
    ll n, k, p, q, x, i;
    while(cin >> n >> k >> p >> q)
    {
        if(p==q)
        {
            map<ll,ll> mp;
            map<ll,ll>::iterator it;
            mp.clear();

            ffr(i,0,n)
            {
                cin >> x;
                mp[x]++;
            }

            ll mx=0;
            for(it=mp.begin();it!=mp.end();it++)
            {
                mx=max(mx,(it->second));
            }
            mx+=k; mx=min(mx,n);
            cout << mx << endl;
        }
        else
        {
            map<ll,ll> mp;
            map<ll,ll>::iterator it;
            mp.clear();


            ll lim, ans=0;
            lim=(ceil)((q*1.0/(p-q)));

            ffr(i,0,n)
            {
                cin >> x;
                mp[x]++;
                if(x>=lim) ans++;
            }
            if(ans==0)
            {
                if(k==1) ans=0; else ans=k;
            }
            else {ans+=k;
            ans=min(ans,n);}

            ll mx=0;
            for(it=mp.begin();it!=mp.end();it++)
            {
                ll cur=it->first;
                if(cur<lim)
                mx=max(mx,(it->second));
            }
            mx+=k; mx=min(mx,n);

            ans=max(ans,mx);

            cout << ans << endl;
        }
    }
}
