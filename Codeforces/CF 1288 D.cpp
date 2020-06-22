#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 1e18

using namespace std;

int gcd(int a, int b)
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

int lim, m, n, ii, jj;
int a[300002][8];
vector< pair<int,int> > lst;

bool ok(int val)
{
    int i, j, num;
    //set<int> st; st.clear();
    bool st[255]={};
    ffr(i,0,n)
    {
        num=0;
        ffr(j,0,m)
        {
            num+=num;
            if(a[i][j]>=val) num++;
        }

        if(num==lim) {ii=lim; jj=lim; return true;}
        st[num]=1;
    }
    for(pair<int,int> p: lst)
    {
        if(st[p.first] && st[p.second])
        {
            ii=p.first; jj=p.second;
            return true;
        }
    }
    return false;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);

    while(cin >> n >> m)
    {
        int i, j, hi, lo, mid, ans=-1, x;
        lim=0;
        ffr(i,0,m) {lim+=lim; lim++;}
        hi=0; lo=1000000007;

        lst.clear();
        ffr(i,1,lim)
        {
            ffr(j,i+1,lim)
            {
                if((i|j)==lim )
                {
                    lst.pb(mp(i,j));
                }
            }
        }
        //cout << lst.size();
        ffr(i,0,n)
        {
            ffr(j,0,m)
            {
                cin >> x;
                a[i][j]=x;
                hi=maxx(hi,x);
                lo=minn(lo,x);
            }
        }
        while(hi-lo>1)
        {
            mid=(hi+lo)/2;
            if(ok(mid)) lo=mid;
            else hi=mid;
        }
        if(ok(hi)) ans=hi;
        else if(ok(lo)) ans=lo;

        int num;
        ffr(i,0,n)
        {
            num=0;
            ffr(j,0,m)
            {
                num+=num;
                if(a[i][j]>=ans) num++;
            }
            if(num==ii || num==jj) {cout << i+1 << ' '; break;}
        }
        ii=ii+jj-num;
        ffr(i,i,n)
        {
            num=0;
            ffr(j,0,m)
            {
                num+=num;
                if(a[i][j]>=ans) num++;
            }
            if(num==ii) {cout << i+1 << endl; break;}
        }
    }
}
