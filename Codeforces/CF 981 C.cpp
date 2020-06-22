




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

vector<int> vc;


int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    int n, i, j, u, v, deg[100005], cn, r;
    while(cin >> n)
    {
    mm(deg,0);
    vc.clear();
      //cin >> n;
    ffr(i,1,n)
    {
      cin >> u >> v;
      deg[u]++; deg[v]++;
    }
    cn=0;
    ffrr(i,1,n)
    {
      if(deg[i]==1) vc.pb(i);
      else if(deg[i]>2)
      {
        cn++; r=i;
      }
    }
    //cout << " cn " << cn << endl;
    if(cn>1) cout << "No\n";
    else if(cn==1)
    {
      int sz=vc.size();
      cout << "Yes\n" << sz << endl;
      ffr(i,0,sz)
      {
        cout << r << " " << vc[i] << endl;
      }
    }
    else
    {

      cout << "Yes\n1\n" << vc[0] << " " << vc[1] << endl;
    }

}


    return 0;
}
