




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
    ll t, i, n, a[100003], x;
    bool canback, canfront;
    cin >> t;
    while(t--)
    {
        cin >> n;
        canfront=1; canback=1;
        ffr(i,0,n)
        {
            cin >> a[i];
        }
        ffr(i,0,n)
        {
            cin >> x;
            if(a[i]>x) canfront=0;
            if(a[n-1-i]>x) canback=0;
        }
        if(canback && canfront) cout << "both\n";
        else if(canfront) cout << "front\n";
        else if(canback) cout << "back\n";
        else cout << "none\n";
    }
	return 0;

}
