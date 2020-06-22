



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
    ll n, cn=0;
    cin >> n;
    while(n>=100ll)
    {
        n-=100ll;
        cn++;
    }
    while(n>=20ll)
    {
        n-=20ll;
        cn++;
    }
    while(n>=10ll)
    {
        n-=10ll;
        cn++;
    }
    while(n>=5ll)
    {
        n-=5ll;
        cn++;
    }
    while(n>=1ll)
    {
        n-=1ll;
        cn++;
    }
    cout << cn << endl;



    return 0;
}
