




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

int org[50];

bool call(int pos, int prev, int shadhin, string done)
{
    if(pos==sz) cout << done << endl;
    if(dp[pos][prev]!=-1) return dp[pos][prev];
    
    if(!shadhin)
    {
        
    }
}

void main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i, j;
    
    cin >> a >> b;
    if(a.size()<b.size())
    {
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        cout << a << endl;
    }
    else
    {
        sz=a.size();
        call(0, 0, "")
    }
}


    //fix size
    return 0;
}
