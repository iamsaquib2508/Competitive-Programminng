




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
    ll n, m, k, d, mx, x1, x2, got1, i, nich, tem;
    cin >> n >> k >> m >> d;
    
    if(d==1)
    {
        cout << m << endl;
        return 0;
    }
    mx=m;
    nich=1;
    ffrr(i,2,d)
    {
        nich+=k;
        x1=ceil(n*1.0/nich); //3
        //tt=floor((n*1.0)/(k*x1));
        got1=(i-1)*x1+(n-(i-1)*k*x1);
        
        
        //cout << got1 << endl;
        
        x2=ceil(n*1.0/k/i); //2
        if(x1<=m) mx=max(mx,got1);
        else if(x2<=m && m<=x1)
        {
            tem=n-(i-1)*k*m;
            if(tem>m) tem=m;
            got1=(i-1)*m+tem;
            mx=max(mx,got1);
        }
        
    }
    
    cout << mx << endl;

    return 0;
}
