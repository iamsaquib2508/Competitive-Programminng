


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
    int T, i, j, x, n;
    vector<int> indices[100005];
    cin >> T;
    while(T--)
    {
        cin >> n;
        ffrr(i,1,n) indices[i].clear();
        ffrr(i,1,n)
        {
            cin >> x;
            indices[x].pb(i);
        }
        ffrr(i,1,n)
        {
            int sz=indices[i].size();
            int cnt=0, cur;
            ffr(j,0,sz)
            {
                cur=indices[i][j];
                if(indices[cur].size()>0) cnt++;
            }
            if(cnt>1)
            {
                cout << "Truly Happy\n";
                break;
            }
        }
        if(i>n)
        {
            cout << "Poor Chef\n";
        }
    }
    return 0;
}
