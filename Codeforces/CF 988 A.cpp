



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
    int n, k, i, a[200], x;
    vector<int> v; v.clear();
    mm(a,0);
    cin >> n >> k;
    ffrr(i,1,n)
    {
        cin >> x;
        a[x]=i;
    }
    ffr(i,0,102)
    {
        if(a[i]) v.pb(a[i]);
    }
    if(v.size()>=k)
    {
        cout << "YES\n";
        ffr(i,0,k)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    else cout << "NO\n";
    



    return 0;
}
