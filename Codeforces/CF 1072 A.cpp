



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




int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    ll n, m, k, rowst, rowend, colst, colend, ans;
    cin >> n >> m >> k;
    rowst=1; rowend=n;
    colst=1; colend=m;
    ans=0;
    while(k--)
    {
        ans+=(rowend-rowst+1)*2+(colend-colst+1)*2-4;
        rowend-=2; colend-=2;
        rowst+=2; colst+=2;
    }
    cout << ans << endl;



    return 0;
}