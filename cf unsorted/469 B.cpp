




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
    ll n, m;
    ll ai, bi, sa, sb, a[100002], b[100002], cnt;
    //while(1)
    {
        cin >> n >> m;
        ffr(ai,0,n)
        {
            cin >> a[ai];
        }
        ffr(ai, 0, m)
        {
            cin >> b[ai];
        }
        sa=a[0]; sb=0; ai=1; bi=0; cnt=0;
        while(1)
        {
            
            if(ai==n && bi==m) break;
            if(sa==sb)
            {
                cnt++; sa=a[ai]; sb=0; ai++;
            }
            else if(sa>sb)
            {
                sb+=b[bi]; bi++;
            }
            else
            {
                sa+=a[ai]; ai++;
            }
        }
        cout << cnt+1 << endl;
    }

    

	return 0;

}
