




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

char a[102][102];
int n, m;

int ff(int i, int j)
{

    if(i<0 || j<0 || i==n || j==m) return 0;
    if(a[i][j]=='*') return 1;
    return 0;
}


int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);

    int i, j, x;
    cin >> n >> m;
    ffr(i,0,n)
    {
        ffr(j,0,m) cin >> a[i][j];
    }

    ffr(i,0,n)
    {
        ffr(j,0,m)
        {
            x=0;

            if(a[i][j]=='*') continue;
            if(a[i][j]=='.')
            {
                x=ff(i-1,j)+ff(i-1,j+1)+ff(i-1,j-1)+ff(i,j)+ff(i,j+1)+ff(i,j-1);
                x+=ff(i+1,j)+ff(i+1,j+1)+ff(i+1,j-1);
                if(x>0) {break;}
                continue;
            }
            x=ff(i-1,j)+ff(i-1,j+1)+ff(i-1,j-1)+ff(i,j)+ff(i,j+1)+ff(i,j-1);
            x+=ff(i+1,j)+ff(i+1,j+1)+ff(i+1,j-1);
            if(x==a[i][j]-'0') continue;
            else break;
        }
        if(j<m) break;
    }
    if(i<n)
    {
        cout << "NO\n";
    }
    else cout << "YES\n";





    return 0;
}
