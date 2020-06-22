




/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define xx first
#define yy second
#define PI acos(-1.0)
#define mp make_pair

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */


vector<int> v[100005];
int n, m, nm;

int ff(int start)
{
    int sz=v[start].size(), prev=start-m, ind, i, len, thiss, cost;
    int best=n+n;
    ffr(i,0,sz)
    {
        thiss=v[start][i];
        if(thiss<start)
        {
            if(cost<best) {best=cost;}
            len=0;
        }
        else
        {
            thiss-=start;
            if(thiss%m>0)
            {
                if(len+cost<best) {best=len+cost;}
                len=0;
            }
            else
            {
                if(len>0)
                {
                    prev+=m; if(prev>nm) prev-=nm;

                    if(prev==thiss) {len++;}
                    else {
                        if(len+cost<best) {best=len+cost;}
                        len=0;
                    }
                }
                else
                {
                    len=1;
                    cost=i-thiss/m; if(cost<0) cost+=n;
                    prev=thiss;
                }
            }
        }
    }
    return best;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    while(cin >> n >> m)
    {
        nm=n*m;
        int i, j, x, ans;
        ffr(i,0,100005) v[i].clear();

        ffr(i,0,n)
        {
            ffrr(j,1,m)
            {
                cin >> x;
                v[j].pb(x);
            }
        }
        ans=0;
        ffrr(i,1,m)
        {
            ans+=(ff(i));
        }
        cout << ans << endl;
    }
    return 0;
}
