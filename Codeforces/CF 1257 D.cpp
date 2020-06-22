#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, m;
    int day, cur, en, p, s, mxmon, mxp, mxal, done;
    int mon[200005];
    set<int> ss;
    int v[200005];
    mm(v,0);
    cin >> t;
    while(t--)
    {
        ss.clear();
        set<int>::iterator it;
        for(it=ss.begin();it!=ss.end();it++)
        {
            en=(*it);
            //v[en].clear();
            v[en]=0;
        }

        cin >> n;
        mxmon=0;
        ffr(i,0,n)
        {
            cin >> mon[i];
            mxmon=maxx(mxmon,mon[i]);
        }

        cin >> m;
        ffr(i,0,m)
        {
            cin >> p >> s;
            v[s]=maxx(v[s],p);
            ss.insert(s);
            mxp=maxx(mxp,p);
        }

        if(mxmon>mxp)
        {
            cout << "-1\n"; continue;
        }

        // for(it=ss.begin();it!=ss.end();it++)
        // {
        //     en=(*it);
        //     sort(v[en].begin(),v[en].end());
        // }

        cur=0;
        day=0;
        while(cur<n)
        {
            day++;
            done=0;
            mxal=0;
            for(it=ss.begin();it!=ss.end();it++)
            {
                en=(*it);
                mxp=v[en];
                if(mxp<mxal) continue;

                ffr(j,done,en)
                {
                    if(cur+j>=n || mon[cur+j]>mxp) break;
                    mxal=maxx(mon[cur+j],mxal);
                }
                done=j;
            }
            if(done==0) break;
            cur+=done;
            //cout << cur << endl;
        }
        //if(cur<n) day=-1;
        cout << day << endl;
    }
    return 0;
}
