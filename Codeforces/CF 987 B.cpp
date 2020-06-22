




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



#define eps 1e-12
int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    double p1, p2, x, y;
    cin >> x >> y;
    //if(x<y)
    {
        p1=x*(log(y*1.0));
        p2=y*log(x*1.0);
        if(abs(p1-p2)<=eps)
        {
            cout << "=\n";
        }
        else if(p1<p2)
        {
            cout << ">\n";
        }
        else cout << "<\n";
    }




    return 0;
}
