



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
    int T, n, m, i, j, x;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        vector<int> a, b;
        ffr(i,0,n)
        {
            cin >> x;
            if(x==0) continue;
            a.pb(x);

        }
        sort(a.begin(), a.end());
        ffr(i,0,m)
        {
            cin >> x;
            if(x==0) continue;
            b.pb(x);
        }
        sort(b.begin(), b.end());
        if(a.size()==b.size())
        {
            n=a.size();
            ffr(i,0,n)
            {
                if(a[i]!=b[i]) break;
            }
            if(i==n)
            {
                cout << "Bob\n";
            }
            else cout << "Alice\n";
        }
        else cout << "Alice\n";
    }




    return 0;
}
