




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

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i, n, x, p, q, t;
    double ans, temp;
    bool canback, canfront;
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> n;

        ffr(i,0,n)
        {
            cin >> p >> q >> x;
            temp=(1+x*1.0/100.0)*(1-x*1.0/100.0);
            ans+=(1.0*p*q*(1.0-temp));
            //cout << ans << endl;

        }

        cout << setprecision(12) << ans << endl;
    }
	return 0;

}
