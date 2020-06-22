#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005
#define so(x) cerr << #x << " = " << x << endl

using namespace std;

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int main()
{
    int t=100;
    while(t--)
    {
        ll n, x[1003], y[1003], i, j, d;
        map<ll, set<ll> > mp;
        set<ll> dis[1003];
        mp.clear();
        cin >> n;
        ffr(i,0,n)
        {
            cin >> x[i] >> y[i];
        }
        ffr(i,0,n)
        {
            ffr(j,i+1,n)
            {
                d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                mp[d].insert(i);
                dis[i].insert(d);
                //dis[i][j]=d;
            }
        }
        ffr(i,0,n-1)
        {
            set<ll>:: iterator it=dis[i].begin();
            for(;it!=dis[i].end();it++)
            {
                if(mp[(*it)].size()>2) break;
            }
            if(it==dis[i].end())
            {
                cout << "1\n" << i+1 << endl;
                break;
            }
        }

    }
}
