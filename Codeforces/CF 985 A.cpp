




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
    int i, n, nn, x, a[1000], ans, mn;
    cin >>n;
    nn=n/2;
    ffr(i,0,nn)
    {
        cin >> a[i];

    }
    sort(a,a+nn);
    ans=0;
    ffrr(i,1,nn)
    {
        x=a[i-1];
        ans+=abs(x-i-i+1);
    }
    mn=ans;
    ans=0;
    ffrr(i,1,nn)
    {
        x=a[i-1];
        ans+=abs(x-i-i);
    }
    cout << min(mn,ans) << endl;


    return 0;
}
