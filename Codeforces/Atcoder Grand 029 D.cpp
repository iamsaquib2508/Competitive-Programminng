#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<ll,ll>
#define mp(a,b) make_pair(a,b)
#define mmxx 1e18

using namespace std;

int main()
{
    ll n, r, c, x, y, ilim, jlim, i, j;

    while(cin >> r >> c >> n)
    {
        map<pii,ll>mapp;
        mapp.clear();
        int mn[200005], lim[200005];
        ffrr(i,1,r)
        {
            mn[i]=c+1;
            lim[i]=1;
        }
        ffr(i,0,n)
        {
            cin >> x >> y;
            if(x<y) continue;
            mapp[mp(x,y)]=1;
            if(y<mn[x]) mn[x]=y;
            //mn[x]=min(mn[x],y);
        }
        jlim=1;
        ilim=r+1;
        //cout << mapp[mp(3,2)] << endl;

        ffrr(i,2,r)
        {
            //cout << i << " i jlim " << jlim << endl;
            if(mapp.find(mp(i,jlim))!=mapp.end())
            {
                ilim=i;
                break;
            }
            if(mapp.find(mp(i,jlim+1))==mapp.end())
            {
                jlim++;
            }

            lim[i]=jlim;
        }

        //ffrr(i,1,r) cout << mn[i] << " "; cout << "mn\n";
        //ffrr(i,1,r) cout << lim[i] << " "; cout << "lim\n";
        //cout << ilim << endl;

        ffr(i,1,ilim)
        {
            if(mn[i]==c+1) continue;
            if(mn[i]<lim[i])
            {
                //ans found
                break;
            }
        }
        cout << i-1 << endl;

    }
}
