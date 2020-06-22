




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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);
    
    int i, n, a[100005], m[100005], prev; ll ans;
    
    cin >> n;
    prev=0;
    ffr(i,0,n)
    {
        
        cin >> m[i];
        a[i]=max(m[i]+1, prev);
        prev=a[i];
        //cout << a[i] << " ";
    }
    ans=(a[n-1]-1-m[n-1]);
    //pf("\n");
    for(i=n-2;i>=0;i--)
    {
        a[i]=max(a[i],a[i+1]-1);
        ans+=(a[i]-1-m[i]);
    }
    cout << ans << endl;
    //fix size
    return 0;
}
