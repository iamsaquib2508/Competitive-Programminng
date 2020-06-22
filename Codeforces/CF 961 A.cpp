




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
    int n, m, a[1002], mn=1002, x, t, i; mm(a,0);
    cin >> n >> m;
    ffr(i,0,m)
    {
        cin >> x;
        a[x]++;
        
    }
    ffrr(i,1,n)
    {
        mn=min(mn,a[i]);
    }
    cout << mn << endl;
    return 0;
}
