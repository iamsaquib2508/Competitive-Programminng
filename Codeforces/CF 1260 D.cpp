#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define pf printf
#define PI acos(-1.0)

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

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int n, m, k, t;
vector<int> rr[200005], dd[200005], v;

bool ok(int sol)
{
    int ans=0, lo, l, j;
    lo=v[m-sol];
    set<int> hang; hang.clear();
    //cout << sol << " lok\n";
    ffrr(l,1,n)
    {
        bool did=false;

        int sz=rr[l].size();
        if(sz>0)
        {
            ffr(j,0,sz)
            {
                int d=dd[l][j];
                if(d<=lo) continue;
                hang.insert(rr[l][j]);
            }
        }

        while(hang.size()>0)
        {
            if(*(hang.begin())==l) {hang.erase(hang.begin()); did=1;}
            else break;
        }

        if(did || hang.size()>0)
        {
            ans+=3;
        }
        else ans++;

        //cout << l << " pos " << hang.size() << endl;
        if(ans>t) break;
    }
    return (ans+1<=t);

}


int main()
{
    while(cin >> m >> n >> k >> t)
    {
        int i, x, lo, hi, mid, ans, l, r, d;
        ffr(i,0,200005) {rr[i].clear(); dd[i].clear();}
        v.clear();

        ffr(i,0,m)
        {
            cin >> x; v.pb(x);
        }
        sort(v.begin(),v.end());
        ffr(i,0,k)
        {
            cin >> l >> r >> d;
            //arr[d]=maxx(arr[d],r);
            //left[d]=minn(left[d],l);
            rr[l].pb(r);
            dd[l].pb(d);
        }


        lo=0; hi=m;
        while(hi-lo>1)
        {
            mid=(lo+hi)/2;
            if(ok(mid)) lo=mid;
            else hi=mid;
        }
        if(ok(hi)) ans=hi;
        else ans=lo;
        cout << ans << endl;
    }
}
