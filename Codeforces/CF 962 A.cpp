




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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //while(1){

    ll i, n, a[20002], x;
    ll s, ss;
    cin >> n;
    s=0; ss=0;
    ffrr(i,1,n)
    {
        cin >> x;
        a[i]=x;
        s+=x;
    }
    ffrr(i,1,n)
    {
        ss+=a[i];
        if(ss+ss>=s) break;
    }
    cout << i << endl;
    
//}
    return 0;
}