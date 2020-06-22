




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
    
    string as, bs; int i, j, sz;
    cin >> as >> bs;
    if(as.size()!=bs.size())
    {
        cout << "NO\n";
    }
    else
    {
        sz=as.size();
        j=sz;
        ffr(i,0,sz)
        {
            j--;
            if(as[i]!=bs[j]) break;
            
            
        }
        if(i==sz) cout << "YES\n";
        else cout << "NO\n";
    }
    //fix size
    return 0;
}
