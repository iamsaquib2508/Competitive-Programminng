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

int main()
{
    int tt; cin >> tt;
    while(tt--)
    {
        int n, m, a[100][100], i, j, got1, row, col;
        cin >> n >> m;
        row=n, col=m;
        ffr(i,0,n)
        {
            got1=0;
            ffr(j,0,m)
            {
                cin >> a[i][j];
                if(a[i][j]==1) got1=1;
            }
            if(got1) row--;
        }
        ffr(j,0,m)
        {
            got1=0;
            ffr(i,0,n)
            {
                if(a[i][j]==1) got1=1;
            }
            if(got1) col--;
        }
        string ans;
        if((minn(row,col)&1)==1)
        ans="Ashish\n";
        else ans="Vivek\n" ;
        cout << ans;
    }
}
