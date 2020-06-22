



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

vector<int> best, v[200005], p;
int n;
int a, b, c;
int got;

void dfs2(int s, int par=-1, int depth=0)
{
   int sz=v[s].size(), i, u;
   if(sz==1 && v[s][0]==par)
   {
       //leaf
       if(best.empty() || depth>best[0])
       {
           best.clear();
           best.pb(depth);
           best.pb(s);
       }
       return;
   }
   for(int u: v[s])
   {
       if(u!=par)
           dfs2(u,s,depth+1);
   }
   best.pb(s);
}

void dfs3(int s, int id)
{
   int sz=v[s].size(), i, u;

   for(int u:v[s])
   {
       if( (u!=p[id-1] && u!=p[id+1]) )
       {
           dfs2(u,s,1);
           if(best.size()>got)
           {
               got=best.size(); c=best[1];
           }
       }
   }
   return;
}

void print(std::vector<int> pp) {for(int aa:pp) cout << aa << ' '; cout << endl;}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);

   while(cin >> n)
   {
       best.clear();
       int i, u, uu, sz;
       ffr(i,0,200005) v[i].clear();
       got=0;

       ffr(i,1,n)
       {
           cin >> u >> uu;
           v[u].pb(uu);
           v[uu].pb(u);
       }
       best.clear();
       best.pb(0);
       dfs2(1);  //edgelen  a ... 1
       a=best[1];

       best.clear();
       best.pb(0);
       dfs2(a);  //edl  b ... a
       b=best[1];
       //print(best);

       p=best;
       sz=best.size()-1;
       //assert(best[sz]==a);

       best.clear();
       best.pb(0);

       ffr(i,2,sz)
       {
           dfs3(p[i],i);
       }
       if(got==0) {got=1; c=p[sz-1];}
       cout << sz-1+got-1 << endl;
       cout << a << ' ' << b << ' ' << c << endl;
   }

   return 0;
}
