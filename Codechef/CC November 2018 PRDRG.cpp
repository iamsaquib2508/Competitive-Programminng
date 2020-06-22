



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
    int T, n;
    cin >> T;
    while(T--)
    {
        cin >> n;
        int times=n/2;
        int mulfour=1, up=0, i;
        ffr(i,0,times)
        {
            up+=mulfour;
            mulfour*=4;

        }
        if(n&1)
        {
            mulfour+=mulfour;
            up+=up; up++;
        }


        cout << up << " " << mulfour << endl;

    }
    return 0;




    return 0;
}
