




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



class node
{ public:
  ll val, x;
  node(){}
  node(ll v, ll xx)
  {
    val=v; x=xx;
  }
};

node arra[100005], arrb[100005];

bool cmp(node aa, node bb)
{
  return aa.val<bb.val;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    ll i, n, a, x, ans, m, lim, b;
    while(cin >> n)
    {


    ffr(i,0,n)
    {
          cin >> a >> x;
          arra[i]=node(a,x);
    }

    cin >> m;
    ffr(i,0,m)
    {
          cin >> a >> x;
          arrb[i]=node(a,x);
    }
    sort(arra,arra+n,cmp);
    sort(arrb,arrb+m,cmp);

    lim=n+m;
    a=0ll; b=0ll; ans=0ll;
    ffr(i,0,lim)
    {
      if(a==n)
      {
        ans+=arrb[b].x; b++;
      }
      else if(b==m || arra[a].val<arrb[b].val)
      {
        ans+=arra[a].x; a++;
      }
      else if(arra[a].val>arrb[b].val)
      {
        ans+=arrb[b].x; b++;
      }
      else if(arra[a].val==arrb[b].val)
      {
        ans+=max(arra[a].x,arrb[b].x);
        a++; b++; i++;
      }
      //cout << a << " a b " << b << endl;
      //cout << "ans " << ans << endl;

    }
    cout << ans << endl;


}

    return 0;
}
