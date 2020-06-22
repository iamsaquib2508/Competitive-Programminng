




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
    int t; cin >> t; while(t--)
    {int a, b, c, n;
    while(cin >> a >> b >> c >> n)
    {
        int p=a+b+c+n;
        if(p%3) cout << "NO\n";
        else
        {
            p=p/3;
            if(a>p || b>p || c>p) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}




    return 0;
}
