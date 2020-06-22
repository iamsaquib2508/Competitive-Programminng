
/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pb push_back
#define pii pair<int,int>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define PI acos(-1.0)
#define mp make_pair

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */

int main()
{
    ll a, b, c;
    while(cin >> a >> b >> c)
    {
        ll m=min(a,b);
        cout << c+c+m+m+(a!=b) << endl;
    }
}
