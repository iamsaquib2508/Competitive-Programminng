




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


int ar[1000006], a[200005];

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL
    int n, K, i, j;
    ll gb;
    cin >> n >> K;
    mm(ar,0);
    ffr(i,0,n)
    {
        cin >> a[i];
        ar[a[i]]++;

    }
    sort(a,a+n);
    gb=0ll;
    ffr(i,1,n)
    {

        j=i-1;

        if(((a[j]<a[i]) && ((a[j]+K)>=a[i])))
        {
            gb+=(ar[a[j]]);
        }
    }
    cout << n-gb << endl;



    return 0;
}
