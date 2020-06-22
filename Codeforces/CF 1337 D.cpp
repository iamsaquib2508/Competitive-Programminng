#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<ll,ll>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
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

vector< pii > v;
vector<ll> temp;
ll n;

ll sqr(ll a, ll b, ll c)
{
    ll ans, ans2, ans3= (b-a)*(b-a);
    ans2= (c-b)*(c-b);
    ans= (c-a)*(c-a);
    return ans+ans2+ans3;
}

ll sarc(ll one, ll three)
{
    ll target=(one+three)/2;
    ll mid, lo=0, hi=temp.size();
    while(hi-lo>2)
    {
        mid=(hi+lo)/2;
        if(temp[mid]>target)
        {
            hi=mid;
        }
        else lo=mid;
    }
    if(temp[lo]>target) mid=lo;
    else mid=hi;
    ll id=mid;
    if(id==temp.size())
        id--;

    ll two=temp[id], ans, ans2;
    ans=sqr(one, two, three);
    if(id!=0)
    {
        two=temp[id-1];

        ans2=sqr(one, two, three);
        if(ans2<ans) ans=ans2;
    }
    return ans;
}

ll func()
{
    ll curid=1, curtype, curval;
    bool twogot=0;
    ll onetype=v[0].ss, twotype=-1;
    ll oneid=0, twoid=-1;
    ll oneval, threeval;

    //ff val, ss type

    ll ans, bestans=4000000000000000000;


    while(curid<n)
    {

        curval=v[curid].ff; curtype=v[curid].ss;

        if(!twogot)
        {

            if(curtype!=onetype)
            {
                //2 paisi
                twoid=curid; // ?

                twotype=curtype;
                temp.clear();
                temp.pb(curval);

                twogot=1;
            }
            else
            {
                //1 repeat
                oneid=curid;
            }
        }
        else
        {
            if(curtype==3-onetype-twotype)
            {
                //3 paisi
                threeval=curval;
                oneval=v[oneid].ff;

                ans=sarc(oneval, threeval);
                if(ans<bestans) bestans=ans;

                oneid=curid-1;
                twoid=curid;
                onetype=v[oneid].ss;
                twotype=curtype;
                temp.clear();
                temp.pb(curval);
            }
            else if(curtype==onetype)
            {
                //1 fix
                oneid=curid-1;
                twoid=curid;
                onetype=v[oneid].ss;
                twotype=curtype;
                temp.clear();
                temp.pb(curval);
            }
            else
            {
                //two prolong
                temp.pb(curval);
            }
        }
        curid++;
    }

    return bestans;
}

int main()
{

    ll ttt; cin >> ttt;
    while(ttt--)
    {
        v.clear();
        ll rr, gg, bb, i;
        ll x;
        cin >> rr >> gg >> bb;
        n=rr+gg+bb;
        ffr(i,0,rr)
        {
            cin >> x;
            v.pb(mp(x,0));
        }
        ffr(i,0,gg)
        {
            cin >> x;
            v.pb(mp(x,1));
        }
        ffr(i,0,bb)
        {
            cin >> x;
            v.pb(mp(x,2));
        }
        sort(v.begin(),v.end());

        cout << func() << endl;
    }
}
/*
1999999982000000114
1999999996000000002
*/
