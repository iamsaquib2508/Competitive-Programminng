




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
    ll n, ans, arl, num;
    while(1){

    cin >> n;
    ans=0;
    arl=2;
    while(1)
    {
        //cout << arl << " ";
        num=n/arl;
        if((n-num*arl)>(arl/2))  
        {
            num++; cout << "special " << n << endl;
        }
        ans+=(arl/2*num);
        if(ans>100000000000000) cout << "danger\n";
        //cout << ans << endl;
        /*if(arl+1==n)
        {
            ans+=(n-1); break;
        }*/
        arl+=arl;
        if(arl>n)
        {
            break;
        }
    }
    if(n+n!=arl)
    ans+=arl/2;
    cout << ans << endl;
}
    
    return 0;
}
