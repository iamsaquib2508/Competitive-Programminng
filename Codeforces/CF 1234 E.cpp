#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll grt[200005], les[200005], sum[200005];

vector< pair<int,int> > pp1, pp2;

ll fun2(ll t)
{
    ll ans=0;
    ll hi, lo, mid;
    lo=-1, hi=pp2.size()-1;

    if(pp2[0].second>=t) return 0;
    if(pp2[hi].second<t) return pp2.size();

    while(hi-lo>1)
    {
        //cout << lo << " lo hi " << hi << endl;
        mid=(lo+hi)/2;
        if(pp2[mid].second<t) lo=mid;
        else if(pp2[mid].second>=t) hi=mid;
    }

    return hi;
}

ll fun1(ll t)
{
    ll ans=0;
    ll hi, lo, mid;
    lo=0, hi=pp1.size();

    if(pp1[0].first>t) return pp1.size();
    if(pp1[hi-1].first<=t) return 0;

    while(hi-lo>1)
    {
        mid=(lo+hi)/2;
        if(pp1[mid].first<=t) lo=mid;
        else if(pp1[mid].first>t) hi=mid;
    }

    return pp1.size()-hi;
}

bool logic(pair<int,int> a, pair<int,int> b)
{
    if(a.second<b.second) return true;
    else if(a.second>b.second) return false;

    else if(a.first<b.first) return true;
    else return false;
}

int main() {
    ll n, m, i, xx, ans, temp;

    while(cin >> n >> m)
    {
        ans=0;
        mm(grt,0); mm(les,0); mm(sum,0);
        vector<ll> x; x.clear();
        pp1.clear(); pp2.clear();
        ll toteq;
        toteq=0;

        cin >> xx; x.pb(xx);
        ffr(i,1,m)
        {
            cin >> xx;
            temp=x[i-1];

            if(xx==temp)
            {
                toteq++;
            }
            else
            {
                if(temp<xx)
                {
                    sum[xx]+=temp;
                    les[xx]++;
                    grt[temp]++;
                    pp1.pb(make_pair(temp,xx));
                    pp2.pb(make_pair(temp,xx));
                }
                else
                {
                    sum[temp]+=xx;
                    les[temp]++;
                    grt[xx]++;
                    pp1.pb(make_pair(xx,temp));
                    pp2.pb(make_pair(xx,temp));
                }
                ans+=abs(xx-temp);
            }
            x.pb(xx);
        }
        sort(pp1.begin(),pp1.end());
        sort(pp2.begin(),pp2.end(),logic);

        cout << ans << " ";
        n++;
        ffr(i,2,n)
        {
            ll t1, t2, t3, t4, t5, t6;
            //cout << i << " show\n";
            t1 = (m-1-toteq-les[i]-grt[i]);
            t2 = (i-1)*grt[i];
            t3 = 2*sum[i];
            t4 = i*(les[i]);
            t5 = fun1(i);
            t6 = fun2(i);
            //cout << t1-t5-t6 << " cross | boro " << t2 << " chotoder sum " << t3 << " chotoder num " << t4 << endl;
            //cout << t5 << " t5 | t6 " << t6 << endl;
            cout << ans - t1 + t2 + t3 - t4 + t5 + t6 << " ";
            //int hu; cin >> hu;
        }
        cout << endl;

    }

}
