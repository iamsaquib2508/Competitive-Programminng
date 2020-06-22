




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
    
    ll U, a[MX], tt;
    int i, j, k, tem, n;
    double ans=0;
    cin >> n >> U;
    cin >> a[0];

    ffr(i,1,n)
    {
        cin >> a[i];
        //if(a[i]-a[0]<=U) k=i;
    }
    
    /*if(k<2)
    {
        pf("-1\n"); return 0;
        
    }*/
    //ans=(a[k]-a[1])*1.0/(a[k]-a[0]);
    ans=-1;
    k=-1;
    ffr(i,0,n)
    {
        if(i+2==n) break;
        k=max(k,i+1);
        ffr(tem,k,n)
        {
            if(a[tem]-a[i]<=U) k=tem;
        }
        if(i+2>k) continue;
        ans=max(ans, (a[k]-a[i+1])*1.0/(a[k]-a[i]) );
        //if(k==n-1) break;
    }
    if(ans==-1) cout << "-1\n";
    else cout << setprecision(17) << ans << endl;
    //fix size
    return 0;
}
