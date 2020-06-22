

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

ll n;

ll ff(ll x)
{
    if(x%2==1) return (x+1)/2;
    else return ff(x+n-x/2);
}

int main()
{
    ll q, x;
    cin >> n >> q;
    while(q--)
    {
        cin >> x;
        cout << ff(x) << endl;
    }
	return 0;
}
