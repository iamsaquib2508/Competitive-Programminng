#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int minn(int a, int b)
{
    if(a<b) return a; return b;
}


int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int di[4]={1,-1,0,0};
int dj[4]={0,0,1,-1};
int n, m, vis[60][60], a[60][60];

int dfs(int i, int j)
{
    if(i<0 || j<0 || i>=n || j>=m) return 0;
    if(vis[i][j]) return 0;
    if(a[i][j]=='#') return 0;
    vis[i][j]=1;
    int k, ans=0, ii, jj;
    if(a[i][j]=='G')
    {
        ans=1;
    }

    ffr(k,0,4)
    {
        ii=i+di[k];
        jj=j+dj[k];
        ans+=dfs(ii,jj);
    }
    return ans;
}

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        cin >> n >> m;
        int i, j, ans, gd=0; char c;
        ffr(i,0,n)
        {
            ffr(j,0,m)
            {
                cin >> c;
                a[i][j]=c;
                if(c=='G') gd++;
                vis[i][j]=0;
            }
        }
        ffr(i,0,n)
        {
            ffr(j,0,m)
            {
                c=a[i][j];
                if(c=='B')
                {
                    if(i>0) a[i-1][j]='#';
                    if(j>0) a[i][j-1]='#';
                    if(i+1<n && a[i+1][j]!='B') a[i+1][j]='#';
                    if(j+1<m && a[i][j+1]!='B') a[i][j+1]='#';
                }
            }
        }
        ans=dfs(n-1,m-1);
        //cout << ans << endl;
        if(ans==gd)
            cout << "Yes\n";
        else cout << "No\n";
    }
}
