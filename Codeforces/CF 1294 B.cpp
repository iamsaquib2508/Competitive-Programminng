




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

class node
{
public:
    int x, y;
    node(){}
};

bool cmp(node a, node b)
{
    if(a.x<b.x || (a.x==b.x && a.y<b.y)) return true;
    return false;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        int i, n, j, xx, yy, x, y;
        string ans="";

        node a[1004];
        cin >> n;
        ffr(i,0,n)
        {
            cin >> a[i].x >> a[i].y;
        }
        sort(a, a+n, cmp);
        xx=a[0].x, yy=a[0].y;
        ffr(j,0,xx) ans+='R';
        ffr(j,0,yy) ans+='U';
        ffr(i,1,n)
        {
            //cout << xx << " " << yy << endl;
            x=a[i].x-xx;
            y=a[i].y-yy;
            if(x<0 || y<0) break;
            ffr(j,0,x) ans+='R';
            ffr(j,0,y) ans+='U';

            xx+=x; yy+=y;
        }
        if(i==n)
        {
            cout << "YES\n" << ans << endl;
        }
        else cout << "NO\n";
    }



    return 0;
}
