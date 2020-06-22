#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define pb push_back
#define pf printf
#define ll long long int
#define ff first
#define ss second
#define sf(a) scanf("%d", &a)
#define CMAX 30002

using namespace std;

class pp
{
    public:
    int next; int cost;
    pp(int n, int cc)
    {
        next=n; cost=cc;
    }
};

vector<pp> v[CMAX];
vector<int> DANS[CMAX];
pair<int,int> MX[CMAX];
int R[CMAX], par[CMAX], root=0;


int demo(int vr)
{
    int sz=v[vr].size(), i, s, fff=0, sss=0;
    ffr(i,0,sz)
    {
        pp t=v[vr][i];
        if(par[vr]==t.next)
        {
            DANS[vr].pb(0); continue;
        }
        par[t.next]=vr;

        s=demo(t.next)+t.cost;
        DANS[vr].pb(s);
        if(s>fff)
        {
            sss=fff;
            fff=s;
        }
        else if(s>sss) sss=s;
    }
    MX[vr].ff=fff;
    MX[vr].ss=sss;
    return fff;
}

void Rans(int ver, int fir, int sec, int cos, bool boro)
{
    if(ver==root) R[ver]=MX[ver].ff;
    else if(boro)
    {
        int pick, k;
        if(R[par[ver]]==fir) pick=sec;
        else pick=R[par[ver]];

        k=pick+cos;
        if(k>MX[ver].ff) R[ver]=k;
        else if(k>MX[ver].ss)
        {
            R[ver]=MX[ver].ff;
            MX[ver].ss=k;
        }
        else R[ver]=MX[ver].ff;
    }
    else
    {
        int pick=max(R[par[ver]],fir);
        R[ver]=max(pick+cos,MX[ver].ff);
    }

    int sz=v[ver].size(), i;
    ffr(i,0,sz)
    {
        if(par[ver]==v[ver][i].next) continue;
        Rans(v[ver][i].next, MX[ver].ff, MX[ver].ss, v[ver][i].cost, (MX[ver].ff==DANS[ver][i]) );
    }
    return;
}


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cc=1, t, i, n, a, b, c;
    sf(t);
    while(t--)
    {
        ffr(i,0,CMAX)
        {
            v[i].clear();
            DANS[i].clear();
            par[i]=-1;
        }

        sf(n); n--;
        ffr(i,0,n)
        {
            sf(a); sf(b); sf(c);

            v[a].pb(pp(b,c));
            v[b].pb(pp(a,c));
        }
        n++;

        demo(root);
        Rans(root,0,0,0,1);

        pf("Case %d:\n", cc++);
        ffr(i,0,n)
        {
            pf("%d\n", R[i]);
        }
    }
    return 0;
}
