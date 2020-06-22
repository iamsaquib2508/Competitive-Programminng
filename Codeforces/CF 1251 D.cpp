#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<ll,ll>
#define pb push_back
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

vector<pii> v;
ll s;
int n;

bool ok(ll mid)
{
    int i;
    ll ss=s, small=0, big=0;
    vector<ll> temp; temp.clear();
    ffr(i,0,n)
    {
        if(v[i].second<mid) small++;
        else if(v[i].first>=mid) big++;
        else temp.pb(v[i].first);
    }
    if(small>n/2) return false;
    //if(big>n/2) return false;
    sort(temp.begin(),temp.end());
    reverse(temp.begin(),temp.end());
    int bneed=maxx(n-n/2-big,0);
    //if(bneed)
    ffr(i,0,minn(bneed,temp.size()))
    {
        ss-=(mid-temp[i]);
    }

    return (ss>=0);
}

bool cmp(pii a, pii b)
{
    if(a.second<b.second) return true;
    if(a.second==b.second && a.first<b.first) return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll lll, rrr;
        int i;
        cin >> n >> s;
        v.clear();
        ffr(i,0,n)
        {
            cin >> lll >> rrr;
            v.pb(make_pair(lll,rrr));
            s-=lll;
        }
        sort(v.begin(),v.end());
        ll lo=v[n/2].first, hi=v[n-1].second, mid=(hi+lo)/2;
        //cout << mid << " mid" << endl;
        sort(v.begin(),v.end(),cmp);


        while(hi-lo>1)
        {
            mid=(hi+lo)/2;
            if(ok(mid)) lo=mid;
            else hi=mid;
        }
        if(ok(hi)) cout << hi << endl;
        else cout << lo << endl;
    }
}
