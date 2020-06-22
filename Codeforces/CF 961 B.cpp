




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
    ll n, m, k, i, j, a[100005], s, mx=0;
    bool t[100005];
    cin >> n >> k;
    ffr(i,0,n)
    {
        cin >> a[i];
    }
    ffr(i,0,n)
    {
        cin >> t[i];

    }
    s=0;
    ffr(i,0,k)
    {
        s+=a[i];
    }
    ffr(i,i,n)
    {
        if(t[i]) s+=a[i];
    }
    mx=s;
    for(i=1, j=k; j<n; i++, j++)
    {
        if(t[i-1]==0)
        {
            s-=a[i-1];
        }
        if(t[j]==0)
        {
            s+=a[j];
        }
        mx=max(mx,s);
    }
    
    cout << mx << endl;
    
    return 0;
}
