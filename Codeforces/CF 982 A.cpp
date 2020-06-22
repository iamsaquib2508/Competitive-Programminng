




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
    int t;
    //cin >> t;
    //while(t--)
    {


    int i, n;
    bool b; string s;
    cin >> n; cin >> s;
    if(n==1)
    {
        if(s[0]=='0') cout << "NO\n";
        else cout << "YES\n"; return 0;
    }
    b=true;

    ffr(i,1,n)
    {
        if(s[i]=='1' && s[i-1]=='1')
        {
            b=false; break;
        }
    }
    if(s[0]=='0' && s[1]=='0') b=false;
    if(s[n-1]=='0' && s[n-2]=='0') b=false;
    ffr(i,1,n-1)
    {
        if(s[i]=='0')
        {
            if(s[i-1]=='0' && s[i+1]=='0') b=false;
        }
    }
    if(b) cout << "YES\n";
    else cout << "NO\n";



    }
    return 0;
}
