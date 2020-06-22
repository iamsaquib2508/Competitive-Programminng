#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int minind[3502][3502];

int main()
{
    int ttt; cin >> ttt;
    while(ttt--)
    {
        int n, p, k, i, j, stripsize, uk, ans, l, r, lmin, rmin, lindex, rindex;
        int a[3502];
        vector<int> v; v.clear();

        cin >> n >> p >> k;
        p--;
        k=minn(p,k);
        ffr(i,0,n)
        {
            cin >> a[i];
        }
        l=0, r=p;
        stripsize=n-p;
        i=stripsize-1; //[ 0 1 2 ... i ]
        while(i<n)
        {
            //ffr(j,0,stripsize)
            {

            }
            v.pb(maxx(a[i],a[i-stripsize+1]));
            i++;
        }
        uk=p-k;
        ffr(i,0,v.size())
        {
            minind[i][i]=v[i];
            ans=v[i];
            ffr(j,i+1,v.size())
            {
                if(v[j]<ans) ans=v[j];
                minind[i][j]=ans;
            }
        }

        ans=0;
        int vsz=v.size();
        //for(int po: v) cout << po << ' '; cout << endl;
        ffr(i,0,vsz)
        {
            j=i;
            if(l<=k)
            {
                lmin=minind[j][minn(j+uk,vsz-1)];
            }
            else
            {
                lindex=maxx(j-(l-k),j-uk);
                rindex=minn(j+uk,vsz-1);
                lmin=minind[lindex][rindex];
            }
            if(r<=k)
            {
                rmin=minind[j][maxx(j-uk,0)];
            }
            else
            {
                rindex=minn(j+(r-k),j+uk);
                //lindex=j-uk;
                lindex=maxx(j-uk,0);
                rmin=minind[lindex][rindex];
            }
            ans=maxx(ans,maxx(lmin,rmin));
            l++; r--;
        }
        cout << ans << endl;
    }
}
