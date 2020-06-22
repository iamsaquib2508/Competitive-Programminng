#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mp(a,b) make_pair(a,b)
#define mmxx 1000000

using namespace std;

int main()
{
    int n, i, j;
    string a[52];
    while(cin >> n)
    {
        ffr(i,0,n)
        {
            cin >> a[i];
        }
        //if(a[0][0]!='#' || a[n-1][0]!='#' || a[0][n-1]!='#' || a[n-1][n-1]!='#') {cout << "NO\n"; continue;}
        ffr(i,0,n-2)
        {
            ffr(j,1,n-1)
            {
                if(a[i][j]=='#') continue;
                if(a[i][j-1]=='#' && a[i][j+1]=='#' && a[i+1][j-1]=='.' && a[i+1][j]=='.' && a[i+1][j+1]=='.' && a[i+2][j]=='.')
                {
                    a[i+1][j-1]='#'; a[i+1][j]='#'; a[i+1][j+1]='#'; a[i+2][j]='#';
                    a[i][j]='#';
                }
                else break;
            }
        }
        ffr(i,0,n)
        {
            ffr(j,0,n)
            {
                if(a[i][j]=='.') break;
            }
            if(j<n) break;
        }
        if(i<n) cout << "NO\n";
        else cout << "YES\n";

    }
}
