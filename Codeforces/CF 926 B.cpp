




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


#define MX 100005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i, n, ans, a[MX], pv, gc, df, x;
    cin >> n;
    
    ffr(i,0,n)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    gc=a[1]-a[0];
    pv=a[1];
    ffr(i,2,n)
    {
        df=a[i]-pv;
        gc=__gcd(gc,df);
        pv=a[i];
    }
    //cout << gc << endl;
    ans=0;
    pv=a[0];
    ffr(i,1,n)
    {
        df=a[i]-pv;
        ans+=(df/gc-1);
        pv=a[i];
    }
    cout << ans << endl;
    //fix size
    return 0;
}
