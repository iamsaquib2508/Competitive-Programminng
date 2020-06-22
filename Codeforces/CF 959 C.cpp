




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
    int i, j, n, t;
    cin >> n;
    if(n<6)
    {
        cout << "-1\n";
    }
    else
    {
        t=n-2;
        ffrr(i,2,t)
        {
            cout << "1 " << i << endl;
        }
        cout << "2 " << n-1 << endl << "2 " << n << endl;
    }
    ffrr(i,2,n)
    {
        cout << "1 " << i << endl;
    }
    return 0;
}
